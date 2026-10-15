#pragma once
#include <stdio.h>

// restrict function visibility, compiler inserts directly at call site
static inline void f(void) { printf("Hello from header1.h!\n"); }
