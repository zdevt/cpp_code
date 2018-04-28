
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

  //�����ں�Դ�뵽source_str
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

  //���ƽ̨���豸��Ϣ
  cl_platform_id platform_id = NULL;
  cl_device_id device_id = NULL;
  cl_uint ret_num_devices;
  cl_uint ret_num_platforms;
  cl_int ret = clGetPlatformIDs ( 1, &platform_id, &ret_num_platforms );
  ret = clGetDeviceIDs ( platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices );

  //����OpenCL������
  cl_context context = clCreateContext ( NULL, 1, &device_id, NULL, NULL, &ret );
  //�����������
  cl_command_queue command_queue = clCreateCommandQueue ( context, device_id, 0, &ret );
  //�����ڴ滺��������豸��Ϊÿ������
  cl_mem a_mem_obj = clCreateBuffer ( context, CL_MEM_READ_ONLY,
                                      LIST_SIZE * sizeof ( int ), NULL, &ret );
  cl_mem b_mem_obj = clCreateBuffer ( context, CL_MEM_READ_ONLY,
                                      LIST_SIZE * sizeof ( int ), NULL, &ret );
  cl_mem c_mem_obj = clCreateBuffer ( context, CL_MEM_WRITE_ONLY,
                                      LIST_SIZE * sizeof ( int ), NULL, &ret );

  //��������A��B����Ӧ���ڴ滺��
  ret = clEnqueueWriteBuffer ( command_queue, a_mem_obj, CL_TRUE, 0,
                               LIST_SIZE * sizeof ( int ), A, 0, NULL, NULL );
  ret = clEnqueueWriteBuffer ( command_queue, a_mem_obj, CL_TRUE, 0,
                               LIST_SIZE * sizeof ( int ), B, 0, NULL, NULL );

  //��������
  cl_program program = clCreateProgramWithSource ( context, 1,
                       ( const char** ) &source_str, ( const size_t* ) &source_size, &ret );
  //��������
  ret = clBuildProgram ( program, 1, &device_id, NULL, NULL, NULL );
  //����OpenCL�ں�
  cl_kernel kernel = clCreateKernel ( program, "vector_add", &ret );

  //�����ں˲���
  ret = clSetKernelArg ( kernel, 0, sizeof ( cl_mem ), ( void* ) &a_mem_obj );
  ret = clSetKernelArg ( kernel, 1, sizeof ( cl_mem ), ( void* ) &b_mem_obj );
  ret = clSetKernelArg ( kernel, 2, sizeof ( cl_mem ), ( void* ) &c_mem_obj );

  //ִ���ں�
  size_t global_item_size = LIST_SIZE; //���������б�
  size_t local_item_size = 64;        //�ָ�Ϊ64����
  ret = clEnqueueNDRangeKernel ( command_queue, kernel, 1, NULL,
                                 &global_item_size, &local_item_size, 0, NULL, NULL );

  //��ȡ�ڴ滺��C�����ر���C
  int* C = ( int* ) malloc ( sizeof ( int ) * LIST_SIZE );
  ret = clEnqueueReadBuffer ( command_queue, c_mem_obj, CL_TRUE, 0,
                              LIST_SIZE * sizeof ( int ), C, 0, NULL, NULL );

  //��ʾ���
  for ( i = 0; i < LIST_SIZE; i++ )
  {
    printf ( "%d + %d = %d\n", A[i], B[i], C[i] );
  }

  //������Դ
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

