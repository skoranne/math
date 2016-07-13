#include <iostream>
#include <cstdlib>
#include <cmath>

double EvalFx( double x )
{
  return (x*x*x - x -1 );
}

#if 1
double ApxFx( double x )
{
  return ((x+1)/(x*x));
}
#endif

double ApxFx2( double x )
{
  // return (std::cbrt(x+1));
  return ( pow( x+1 , 1.0/3 ) );
}


#if 0
double ApxFx( double x )
{
  return (x*x*x-1);
}
#endif

static void CalculateRoot( double x )
{
  for( int i=0; i < 10; ++i ) {
    double efx = EvalFx( x );
    double afx = ApxFx(  x );
    double afx2 = ApxFx2( x );
    std::cout << i << "\t& " << x << "\t& " << afx2 << 
      "\t& " << efx << " \\\\" << std::endl;
    x = afx2;
  }
}

int main( int argc, char* argv[])
{
  CalculateRoot( atof( argv[1] ) );
  return 0;
}
