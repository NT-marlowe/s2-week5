#ifndef FUNC_MTFUJI_H
#define FUNC_MTFUJI_H

#include <stdio.h>

typedef struct sample
{
  char loc[20]; // name of location
  double alt; // 
  double temp;
} Sample;


double f_value(Sample data[], const double a, const double b);

void f_gradient(const Sample data[], double g[], int n, double a, double b);

// double mean_squared_error(const double x[], double (*f_value)(const double x[]));
double mean_squared_error(Sample data[], int n, const double b, const double a);

void update_params(const double g[], double *a, double *b, const double alpha);

void steepest_descend(Sample data[], int n, double *a, double *b, const double thresh, const double alpha);

#endif