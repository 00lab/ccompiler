#include<stdio.h>

#ifdef USE_MACRO
#define square(x) (x)*(x)
#else
inline int square(x) {
  return x*x;
}
#endif

int main() {
  int a = 3;
  int b = square(++a);
  printf("%d\n", b);
  return 0;
}

// gcc -E test_macro.c > o_no_def_macro.c
/*
inline int square(x) {
  return x*x;
}


int main() {
  int a = 3;
  int b = square(++a);
  printf("%d\n", b);
  return 0;
}
*/
// gcc -E test_macro.c -DUSE_MACRO > o_def_macro.c
/*
# 2 "test_macro.c" 2
# 11 "test_macro.c"
int main() {
  int a = 3;
  int b = (++a)*(++a);
  printf("%d\n", b);
  return 0;
}
*/
