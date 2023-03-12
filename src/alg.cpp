// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0)
    return 1;
  double result = value;
  for (uint16_t i = 1; i < n; ++i)
    result *= value;
  return result;
}

uint64_t fact(uint16_t n) {
  if (n <= 1)
    return 1;
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) { return pown(x, n) / fact(n); }

double expn(double x, uint16_t count) {
  double result = 1;
  for (uint16_t n = 1; n <= count; ++n)
    result += calcItem(x, n);
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t n = 1; n <= count; ++n)
    result += calcItem(x, 2 * n - 1) * pown(-1, n - 1);
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t n = 1; n <= count; ++n)
    result += calcItem(x, 2 * n - 2) * pown(-1, n - 1);
  return result;
}
