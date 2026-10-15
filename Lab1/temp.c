#include "temp.h"
#include <stdio.h>

double celsius = 0.0, fahrenheit = 0.0;
void readTemperatureCelsius(void) {
  printf("Enter temperature in Celsius: ");
	scanf_s("%lf", &celsius);
}

void readTemperatureFahrenheit(void) {
  printf("Enter temperature in Fahrenheit: ");
	scanf_s("%lf", &fahrenheit);
}

void displayTemperature(void) {
  printf("Temperature in Fahrenheit: %2.f\n", fahrenheit);
  printf("Temperature in Celsius: %2.f\n", celsius);
}

void convertToCelsius(void) {
  celsius = (fahrenheit - 32.0) * (5.0f / 9.0f);
}
void convertToFahrenheit(void) {
  fahrenheit = celsius * 1.8f + 32.0;
}