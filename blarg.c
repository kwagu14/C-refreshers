#include <stdio.h>

/*
    NOTE: the explicit cast to int is necessary in the #define statement
    because it forces a signed comparison in the for loop

    without this cast, sizeof returns unsigned. The entire expression TOTAL_ELEMENTS -2
    is then converted to unsigned, as well as i. In unsigned representation, -1 is the largest possible value
    so the expression is false from the start
*/

#define TOTAL_ELEMENTS (int)((sizeof(array) / sizeof(array[0])))
int array[] = {1, 3, 15, 19, 0, 43, 12};

int main(int argc, char *argv[]) {
  int i;  

  for (i=-1;i <= TOTAL_ELEMENTS - 2; i++) {
    printf("Element %d has value %d\n", i+1, array[i+1]);
  }
  
  return 0;
}