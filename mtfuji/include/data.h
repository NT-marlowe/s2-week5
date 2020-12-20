#ifndef DATA_H
#define DATA_H

#include "func_mtfuji.h"

int load_csv(char *filepath, Sample data[]); // 返り値はデータ行数

int comp_alt(const void *x0, const void *x1);

#endif