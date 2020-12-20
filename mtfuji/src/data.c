#include <stdlib.h>
#include <string.h>
#include "func_mtfuji.h"

int load_csv(char *filepath, Sample data[]) {
  
  int cnt = 0;

  FILE *fp;
  if ((fp = fopen(filepath, "r"))== NULL) {
    fprintf(stderr, "%s: cannot open file.\n", filepath);
    exit(1);
  }

  char buf[20];
  double alt, temp;
  while (fscanf(fp, "%[^,],%lf,%lf%*1[\n]", buf,&alt,&temp) == 3) {
    // data[cnt] = (Sample){ .loc = buf, .alt = alt, .temp = temp};
    // data[cnt].loc = buf;
    strcpy(data[cnt].loc, buf);
    data[cnt].alt = alt;
    data[cnt].temp = temp;
    cnt++;
  }
  
  return cnt;
}

int comp_alt(const void *x0, const void *x1) {
  const Sample *p0 = (Sample*)x0;
  const Sample *p1 = (Sample*)x1;

  double a0 = p0->alt;
  double a1 = p1->alt;

  if (a0 > a1) return 1;
  else if (a0 < a1) return -1;
  else return 0; 
}