#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <math.h>
     
typedef struct predprey_params{
  double alpha; 
  double beta;
  double gamma;
  double gmax;
  int   count;
  int   jac_count;
} predprey_params;


int predprey (double t, const double x[], double dxdt[], void * params){
  // make local variables
  predprey_params    * p  = (predprey_params *)params;
  double alpha   = p->alpha; 
  double beta    = p->beta;
  double gamma   = p->gamma;
  double gmax    = p->gmax;
  
  ++p->count;
  dxdt[0] = x[0]*(1-x[1]-x[0]/x[2]);
  dxdt[1] = alpha*(x[0]-1)*x[1];
  dxdt[2] = gamma*(1-x[2]/gmax)-beta*x[0];
  return GSL_SUCCESS;
}

int
jac_predprey (double t, const double x[], double *dfdy, 
     double dfdt[], void *params)
{
  predprey_params  * p = (predprey_params *)params;
  double alpha   = p->alpha; 
  double beta    = p->beta;
  double gamma   = p->gamma;
  double gmax    = p->gmax;

  gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 3, 3);
  gsl_matrix * m = &dfdy_mat.matrix; 

  ++ p->jac_count; 
  
  gsl_matrix_set(m, 0, 0, 1-x[1]-2*x[0]/x[2]);
  gsl_matrix_set(m, 0, 1, -x[0]);
  gsl_matrix_set(m, 0, 2, (x[0]/x[2])*(x[0]/x[2]));
  
  gsl_matrix_set(m, 1, 0, alpha*x[1]);
  gsl_matrix_set(m, 1, 1, alpha*x[0]-1);
  gsl_matrix_set(m, 1, 2, 0);
  
  gsl_matrix_set(m, 2, 0, -beta);
  gsl_matrix_set(m, 2, 1 ,0);
  gsl_matrix_set(m, 2, 2, -gamma/gmax);
  
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  dfdt[2] = 0.0;
  return GSL_SUCCESS;
}

int
main () {
  double alpha = 2;
  double beta = 4;
  double gamma = 7; //3 and 7
  double gmax = 5;

  // you can use any stepper here
  const gsl_odeiv2_step_type * T = gsl_odeiv2_step_rk4imp;
  gsl_odeiv2_step * s    = gsl_odeiv2_step_alloc(T, 3);
  gsl_odeiv2_control * c = gsl_odeiv2_control_y_new(1e-6, 0.0);
  gsl_odeiv2_evolve * e  = gsl_odeiv2_evolve_alloc(3);
  predprey_params pars = {alpha,beta,gamma,gmax,0,0};     /* the parameters */
  gsl_odeiv2_system sys = {predprey, jac_predprey, 3, &pars};

  gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new(&sys, T, 1e-6, 1e-6, 1e-6 );
  gsl_odeiv2_step_set_driver(s, d);
     
  double t = 0.0, t1 = 20.0;
  double h = 1e-6;
  double x[3] = { 1.0, 0.1, 3.0 };
  
  double t2 = t;
  double interval = 0.01;
  while (t < t1)
  {
    int status = gsl_odeiv2_evolve_apply (e, c, s, &sys, &t, t1, &h, x);
    
    if (status != GSL_SUCCESS)
      break;
    if(t > t2+interval) {
      printf ("%.5e %.5e %.5e %.5e\n", t, x[0], x[1], x[2]);
      t2 = t;
    }
  }
  
  gsl_odeiv2_evolve_free (e);
  gsl_odeiv2_control_free (c);
  gsl_odeiv2_step_free (s);
  fprintf(stderr,"Number of Jacobian evaluations = %d\n"
       "Number of Function evaluations = %d\n", pars.jac_count,
 pars.count);
  return 0;

}
