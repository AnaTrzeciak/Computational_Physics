/* Compilacao  

 $ gcc -Wall -I/usr/local/include -c arquivo_name.cpp
 $ gcc -L/usr/local/lib arquivo_name.o -lgsl -lgslcblas -lm 
 $ ./a.out

 Analytic results for the pendulum

EDO:   dtheta/dt = v
       dv/dt = -v/Q - theta + Acos(wt)

We use therefore a two-dimensional array to represent x and v
as functions of t
	y[0] == theta
	y[1] == v
	dy[0]/dt = v
	dy[1]/dt = -v/Q - theta + Acos(wt)

where Q represents the number of oscillations of the undriven system that must occur before its energy is significantly reduced due to the viscous drag. The amplitude Â is measured in units of the maximum possible gravitational torque while ω̂ is the angular frequency of the external torque measured in units of the pendulum’s natural frequency
 
 Q = 2; w = 2/3, A = 0.5
The length is set equal to 1 m and mass of the pendulum is set equal to 1 kg.

Initial condition: v(0) = 0, theta(0) = 0.01
number of steps N = 100
time interval t: [0, 10pi]
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
  double Q = *(double *)params;
  double w = *(double *)params;
  double A = *(double *)params;
  f[0] = y[1];
  f[1] = -y[1]/Q - y[0] + A*cos(w*t);
  return GSL_SUCCESS;
}

int
jac (double t, const double y[], double *dfdy,
     double dfdt[], void *params)
{
  (void)(t); /* avoid unused parameter warning */
  double Q = *(double *)params;
  gsl_matrix_view dfdy_mat
    = gsl_matrix_view_array (dfdy, 2, 2);
  gsl_matrix * m = &dfdy_mat.matrix;
  gsl_matrix_set (m, 0, 0, 0.0);
  gsl_matrix_set (m, 0, 1, 1.0);
  gsl_matrix_set (m, 1, 0, -1.0);
  gsl_matrix_set (m, 1, 1, -1.0/Q);
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  return GSL_SUCCESS;
}

int
main (void)
{

  FILE *outfile;
  outfile=fopen("example3_pendulum_out.txt", "w");
 
  double pi = M_PI;
  double Q = 2;
  double w = 2/3;
  double A = 0.5;
  double conts[3] = {Q, w, A};

  gsl_odeiv2_system sys = {func, jac, 2, &conts};

  gsl_odeiv2_driver * d =
    gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rk4,
                                  1e-6, 1e-6, 0.0);
 //gsl_odeiv2_step_rk8pd
  int i;
  double t = 0.0, t1 = 10*pi;
  double y[2] = { 0.01, 0.0 };

  for (i = 1; i <= 200; i++)
    {
      double ti = i * t1 / 300.0;
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
