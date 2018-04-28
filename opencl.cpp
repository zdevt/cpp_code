
#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
  #include <OpenCL/opencl.h>
#else
  #include <CL/cl.h>
#endif

#define MAX_SOURCE_SIZE (0x100000)

int main ( void )
{
  int i;
  const int LIST_SIZE = 1024;
  int* A = ( int* ) malloc ( sizeof ( int ) * LIST_SIZE );
  int* B = ( int* ) malloc ( sizeof ( int ) * LIST_SIZE );

  for ( i = 0; i < LIST_SIZE; i++ )
  {
    A[i] = i;
    B[i] = LIST_SIZE - i;
  }

  //载入内核源码到source_str
  FILE* fp;
  char* source_str;
  size_t source_size;

  fp = fopen ( "vector_add_kernel.cl", "r" );

  if ( !fp )
  {
    fprintf ( stderr, "Failed to load kernel\n" );
    exit ( 1 );
  }

  source_str = ( char* ) malloc ( MAX_SOURCE_SIZE );
  source_size = fread ( source_str, 1, MAX_SOURCE_SIZE, fp );
  fclose ( fp );

  //获得平台和设备信息
  cl_platform_id platform_id = NULL;
  cl_device_id device_id = NULL;
  cl_uint ret_num_devices;
  cl_uint ret_num_platforms;
  cl_int ret = clGetPlatformIDs ( 1, &platform_id, &ret_num_platforms );
  ret = clGetDeviceIDs ( platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices );

  //创建OpenCL上下文
  cl_context context = clCreateContext ( NULL, 1, &device_id, NULL, NULL, &ret );
  //创建命令队列
  cl_command_queue command_queue = clCreateCommandQueue ( context, device_id, 0, &ret );
  //创建内存缓冲对象，在设备上为每个向量
  cl_mem a_mem_obj = clCreateBuffer ( context, CL_MEM_READ_ONLY,
                                      LIST_SIZE * sizeof ( int ), NULL, &ret );
  cl_mem b_mem_obj = clCreateBuffer ( context, CL_MEM_READ_ONLY,
                                      LIST_SIZE * sizeof ( int ), NULL, &ret );
  cl_mem c_mem_obj = clCreateBuffer ( context, CL_MEM_WRITE_ONLY,
                                      LIST_SIZE * sizeof ( int ), NULL, &ret );

  //拷贝数据A和B到对应的内存缓冲
  ret = clEnqueueWriteBuffer ( command_queue, a_mem_obj, CL_TRUE, 0,
                               LIST_SIZE * sizeof ( int ), A, 0, NULL, NULL );
  ret = clEnqueueWriteBuffer ( command_queue, a_mem_obj, CL_TRUE, 0,
                               LIST_SIZE * sizeof ( int ), B, 0, NULL, NULL );

  //创建程序
  cl_program program = clCreateProgramWithSource ( context, 1,
                       ( const char** ) &source_str, ( const size_t* ) &source_size, &ret );
  //构建程序
  ret = clBuildProgram ( program, 1, &device_id, NULL, NULL, NULL );
  //创建OpenCL内核
  cl_kernel kernel = clCreateKernel ( program, "vector_add", &ret );

  //设置内核参数
  ret = clSetKernelArg ( kernel, 0, sizeof ( cl_mem ), ( void* ) &a_mem_obj );
  ret = clSetKernelArg ( kernel, 1, sizeof ( cl_mem ), ( void* ) &b_mem_obj );
  ret = clSetKernelArg ( kernel, 2, sizeof ( cl_mem ), ( void* ) &c_mem_obj );

  //执行内核
  size_t global_item_size = LIST_SIZE; //处理整个列表
  size_t local_item_size = 64;        //分割为64个组
  ret = clEnqueueNDRangeKernel ( command_queue, kernel, 1, NULL,
                                 &global_item_size, &local_item_size, 0, NULL, NULL );

  //读取内存缓冲C到本地变量C
  int* C = ( int* ) malloc ( sizeof ( int ) * LIST_SIZE );
  ret = clEnqueueReadBuffer ( command_queue, c_mem_obj, CL_TRUE, 0,
                              LIST_SIZE * sizeof ( int ), C, 0, NULL, NULL );

  //显示结果
  for ( i = 0; i < LIST_SIZE; i++ )
  {
    printf ( "%d + %d = %d\n", A[i], B[i], C[i] );
  }

  //清理资源
  ret = clFlush ( command_queue );
  ret = clFinish ( command_queue );
  ret = clReleaseKernel ( kernel );
  ret = clReleaseProgram ( program );
  ret = clReleaseMemObject ( a_mem_obj );
  ret = clReleaseMemObject ( b_mem_obj );
  ret = clReleaseMemObject ( c_mem_obj );
  ret = clReleaseCommandQueue ( command_queue );
  ret = clReleaseContext ( context );
  free ( A );
  free ( B );
  free ( C );
  return 0;
}

