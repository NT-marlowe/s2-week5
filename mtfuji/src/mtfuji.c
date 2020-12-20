#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func_mtfuji.h"
#include "data.h"

int main(int argc, char **argv) {
  
  if (argc != 2) {
    fprintf(stderr, "Usage %s: ./%s <path of csv file>\n", argv[0], argv[0]);
    exit(1);
  }
  
  char *filepath = argv[1];
  FILE *fp;
  if ((fp = fopen(filepath, "r"))== NULL) {
    fprintf(stderr, "%s: cannot open file.\n", filepath);
    exit(1);
  }

  Sample data[100];
  int n = load_csv(filepath, data); // data.hは正しく動く
  
  double a = 10;
  double b = 10;
  double alpha = 0.05; // とりあえず
  double thresh = 0.3;
  
  steepest_descend(data, n, &a, &b, thresh, alpha);

  printf("a = %lf, b = %lf\n", a, b);
  double temp_peak = a * 3.776 + b;
  printf("The temperature at the peak of Mt.Fuji is %lf\n", temp_peak);

  qsort(data, n, sizeof(Sample), comp_alt); 
  for (int i = 0; i < n; i++) {
    printf("%s,\t\t%lf,\t%lf\n", data[i].loc, data[i].alt, data[i].temp);
  }
  return 0;
}