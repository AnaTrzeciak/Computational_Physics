/* Compilacao  

 $ gcc -Wall -I/usr/local/include -c example1_oscillator.cpp
 $ gcc -L/usr/local/lib example1_oscillator.o -lgsl -lgslcblas -lm 
 $ ./a.out

EDO:   dx/dt = v
       dv/dt = -x
We use therefore a two-dimensional array to represent x and v
as functions of t
	y[0] == x
	y[1] == v
	dy[0]/dt = v
	dy[1]/dt = -x  where k/m = 1
*/

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>


int
func (double t, const double y[], double f[],
      void *params)
{
  (void)(t); /* avoid unused parameter warning */
  double km = *(double *)params;
  f[0] = y[1];
  f[1] = -km*y[0];
  return GSL_SUCCESS;
}

int
jac (double t, const double y[], double *dfdy,
     double dfdt[], void *params)
{
  (void)(t); /* avoid unused parameter warning */
  double km = *(double *)params;
  gsl_matrix_view dfdy_mat
    = gsl_matrix_view_array (dfdy, 2, 2);
  gsl_matrix * m = &dfdy_mat.matrix;
  gsl_matrix_set (m, 0, 0, 0.0);
  gsl_matrix_set (m, 0, 1, -km*1.0);
  gsl_matrix_set (m, 1, 0, -km*1.0);
  gsl_matrix_set (m, 1, 1, 0);
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  return GSL_SUCCESS;
}

int
main (void)
{

  FILE *outfile;
  outfile=fopen("example2_harmonic_osc_out.txt", "w");
 
  double pi = M_PI;
  double km = 1;
  gsl_odeiv2_system sys = {func, jac, 2, &km};

  gsl_odeiv2_driver * d =
    gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rk8pd,
                                  1e-6, 1e-6, 0.0);
  int i;
  double t = 0.0, t1 = 4*pi;
  double y[2] = { 0.0, 1.0 };

  for (i = 1; i <= 100; i++)
    {
      double ti = i * t1 / 100.0;
      int status = gsl_odeiv2_driver_apply (d, &t, ti, y);

      if (status != GSL_SUCCESS)
        {
          printf ("error, return value=%d\n", status);
          break;
        }

      //printf ("%.5e %.5e %.5e\n", t, y[0], y[1]);
    fprintf(outfile, "%.5e %.5e %.5e\n", t, y[0], y[1]);
    }
  fclose(outfile);
  gsl_odeiv2_driver_free (d);
  return 0;
}
