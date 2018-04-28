
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <random>

std::default_random_engine gen;
std::normal_distribution<double> dis ( 0, 0.15 );

double frand()
{
  double t = dis ( gen );
  fprintf ( stderr, "t=%f\n", t );
  return t;
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  float x_last = 0;
  float p_last = 0.02;
  float Q = 0.018;
  float R = 0.542;
  float kg;
  float karman_mid;
  float kalman_measure;
  float p_mid;
  float p_now;
  float z_real = 0.56;
  float z_measure;
  float summerror_kalman = 0;
  float summerror_measure = 0;
  int i;

  x_last = z_real + frand();
  karman_mid = x_last;

  for ( i = 0; i < 3000; i++ )
  {
    karman_mid = x_last;
    p_mid = p_last + Q;
    kg = p_mid / ( p_mid + R );
    z_measure = z_real + frand(); //测量值
    kalman_measure = karman_mid + kg * ( z_measure - karman_mid ); //估计出的最有值
    p_now = ( 1 - kg ) * p_mid; //最优值对应的协方差

    #if 1
    printf ( "Real position:%6.3f\n", z_real );
    printf ( "Measure position:%6.3f [diff:%.3f]\n", z_measure, fabs ( z_real - z_measure ) );
    printf ( "Kalman position: %6.3f [diff:%.3f]\n", kalman_measure, fabs ( z_real - kalman_measure ) );
    printf ( "\n\n" );
    #endif
    summerror_measure += fabs ( z_real - z_measure );
    summerror_kalman += fabs ( z_real - kalman_measure );
    p_last = p_now;
    x_last = kalman_measure;
  }

  printf ( "total error     :%f\n", summerror_measure );
  printf ( "total kalman error :%f\n", summerror_kalman );
  printf ( "pesent kalman error:%d%%\n", ( int ) ( ( summerror_kalman / summerror_measure ) * 100 ) );
}

