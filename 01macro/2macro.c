#include<stdio.h>

#define TYPE_Apple 1
#define TYPE_Pear 2

struct Fruit {
  int _type;
  char* _name;
};

#define DECLARE(x) \
struct Fruit x = { \
  TYPE_##x,        \
  #x,              \
};

DECLARE(Apple)
DECLARE(Pear)

int main() {
  printf("%d, %s\n", Apple._type, Apple._name);
  printf("%d, %s\n", Pear._type, Pear._name);
  return 0;
}

//gcc -E 2macro.c
/*
宏输出结果
# 2 "2macro.c" 2
struct Fruit {
  int _type;
  char* _name;
}


struct Fruit Apple = { 1, "Apple", };
struct Fruit Pear = { 2, "Pear", };

int main() {
  printf("%d, %s\n", Apple._type, Apple._name);
  printf("%d, %s\n", Pear._type, Pear._name);
  return 0;
}

*/