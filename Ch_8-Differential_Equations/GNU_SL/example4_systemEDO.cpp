/* Compilacao  

 $ gcc -Wall -I/usr/local/include -c neutrino_osc_w_matter.cpp
 $ gcc -L/usr/local/lib example1_oscillator.o -lgsl -lgslcblas -lm 
 $ ./a.out

Nonlinear system:

  x' = -x + 3z
  y' = -y + 2z
  z' = x*x - 2z

initial condition: x(0) = 0; y(0) = 1/2; z(0) = 3
interval t: [0:1.5] 
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
  double p = *(double *)params;
  f[0] = -y[0] + 3.*y[2];
  f[1] =  -y[1] + p*y[2];
  f[2] =  y[0]*y[0] - p*y[2];
  return GSL_SUCCESS;
}

int
jac (double t, const double y[], double *dfdy,
     double dfdt[], void *params)
{
  (void)(t); /* avoid unused parameter warning */
  double p = *(double *)params;
  
  gsl_matrix_view dfdy_mat
    = gsl_matrix_view_array (dfdy, 3, 3);
  gsl_matrix * m = &dfdy_mat.matrix;
  gsl_matrix_set (m, 0, 0, -1.0);
  gsl_matrix_set (m, 0, 1, 0.0);
  gsl_matrix_set (m, 0, 2, 3.0);
  gsl_matrix_set (m, 1, 0, 0.0);
  gsl_matrix_set (m, 1, 1, -1.0);
  gsl_matrix_set (m, 1, 2, p);
  gsl_matrix_set (m, 2, 0, p*y[0]);
  gsl_matrix_set (m, 2, 1, 0.0);
  gsl_matrix_set (m, 2, 2, -p);     
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  dfdt[2] = 0.0;
 
  return GSL_SUCCESS;
}

int
main (void)
{

  FILE *outfile;
  outfile=fopen("example4_systemEDO_out.txt", "w");
    
  double p =2.0;
 
  gsl_odeiv2_system sys = {func, jac, 3, &p};

  gsl_odeiv2_driver * d =
    gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rk4,
                                  1e-6, 1e-6, 0.0);
  int i;
  double t = 0.0, t1 = 1.5;
  double y[3] = { 0.0, 0.5, 3.0};

  for (i = 1; i <= 100; i++)
    {
      double ti = i * t1 / 100;
      int status = gsl_odeiv2_driver_apply (d, &t, ti, y);

      if (status != GSL_SUCCESS)
        {
          printf ("error, return value=%d\n", status);
          break;
        }

      //printf ("%.5e %.5e %.5e\n", t, y[0], y[1]);
    fprintf(outfile, "%.3e %.3e %.3e %.3e\n", t, y[0], y[1], y[2]) ;
    }
  fclose(outfile);
  gsl_odeiv2_driver_free (d);
  return 0;
}
