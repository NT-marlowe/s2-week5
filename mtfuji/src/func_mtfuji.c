#include <stdio.h>

typedef struct
{
  char loc[20];   // location name
  double alt;  // altitude (km)
  double temp; // temperature (centigrade)
} Sample;


double f_value(Sample data, const double a, const double b)
{
  return a * data.alt + b;
}

void f_gradient(const Sample data[], double g[], int n, double a, double b) // gradientを更新する
{
  // double a = g[0], b = g[1];
  double grad_a = 0, grad_b = 0;
  for (int i = 0; i < n; i++) {
    double al = data[i].alt, tm = data[i].temp;
    grad_a += -2 * al * (tm - a*al - b);
    grad_b += -2 * (tm - a*al - b);
  }
  
  g[0] = grad_a / n;
  g[1] = grad_b / n;
}

double mean_squared_error(Sample data[], int n, const double a, const double b) {
  
  double sum = 0;
  for (int i = 0; i < n; i++) {
    double delta = (data[i].temp - f_value(data[i], a, b));
    sum += delta * delta;
  }
  return sum / n;
}

void update_params(const double g[], double *a, double *b, const double alpha) {
  *a = *a - g[0] * alpha;
  *b = *b - g[1] * alpha;
}

void steepest_descend(Sample data[], int n, double *a, double *b, const double thresh, const double alpha) {
  
  double g[2] = {0};
  int max_iter = 10000;
  int cnt = 0;
  while (mean_squared_error(data,n,*a,*b) > thresh) {
    f_gradient(data, g, n, *a, *b);
    update_params(g, a, b, alpha);
    
    if (cnt == max_iter) break;
    cnt++;
  }

}