#include "a.h"

int x;

void __attribute__ ((constructor)) premain() {
  x = 1;
}