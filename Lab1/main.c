#include "temp.h"
#include <stdio.h>

// Task T.1. Defined a macro USE_HEADER1 and
// use if else logic in preprocessor directives
#define USE_HEADER1 1

#if (USE_HEADER1 == 1)
#include "header1.h"
#else
#include "header2.h"
#endif

// Task 1.3. checks if native c language _DEBUG mode
// is active or if another user defined DEBUG macro was defined
#if defined(_DEBUG) && !defined(DEBUG)
#define DEBUG
#endif

int main(void) {
  // Task T.1.3 __LINE__ expands as an int to the current line
  // __FILE__ expands as a string to the current src file
#ifdef DEBUG
  printf("[DEBUG LOG] %d in %s\n\n", __LINE__, __FILE__);
#endif

  // Task T.1.2:
  f();
  printf("\n");

  // Task T.1.4 uses _WIN32 __linux__ premade macros to check for os
#if defined(_WIN32)
  printf("Hello Windows\n");
#elif defined(__linux__)
  printf("Hello Linux\n");
#else
  printf("Hello Other OS\n");
#endif
  printf("\n");

  // Task T.1.1
  char scale;
  printf("In which scale will you input the temperature? (F/C): ");
  // smart scanf scans only the char and looks for specified amount of size
  scanf_s(" %c", &scale, (unsigned)sizeof(scale));

  switch (scale) {
  case 'F':
  case 'f':
    readTemperatureFahrenheit();
    convertToCelsius();
    displayTemperature();
    break;
  case 'C':
  case 'c':
    readTemperatureCelsius();
    convertToFahrenheit();
    displayTemperature();
    break;
  default:
    printf("Error: Invalid temperature scale selected.\n");
    break;
  }

  return 0;
}