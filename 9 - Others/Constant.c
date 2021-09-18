// defined constants: calculate circumference
#include <stdio.h>
#define PI 3.14159
#define NEWLINE "\n"

int main (){
  double r=5.0;               // radius
  double circle;
  circle = 2 * PI * r;       // utilizamos o Pi e não 3.
  printf("%lf", circle);
  printf("%s", NEWLINE );
  return 0;
}
