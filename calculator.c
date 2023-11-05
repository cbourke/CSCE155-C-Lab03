/**
 * Author: Alisha
 * Date: 5-10-2023
 *
 * This programs provides basic calculator functionality
 * allowing a user to enter two operands and to compute
 * various calculated values.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
double calculator( int choice, double a, double b );
double calculator( int choice, double a, double b ){
  double result= 0.0;
    if(choice == 1)
   {
    result = a + b;
      printf("Result: %.2f\n", result);
    
  }
   else if(choice == 2) 
  {
    result = a - b;
    printf("%.2f", result);
    
  }
   else if(choice == 3)
  {
    result = a * b;
      printf("Result: %.2f\n", result);
    
    
  } //TODO: handle this case (division)
  else if(choice == 4) 
  {
    if (b != 0) {
        result = a / b;
        printf("Result: %.2f\n", result);
        
      } else {
        printf("Cannot divide by zero.\n");
      }

    
  }//TODO: handle this case (minimum)
   else if(choice == 5) 
  {
    result = fmin(a, b);
      printf("Result: %.2f\n", result);
    
    
  }//TODO: handle this case (log_a(b))
   else if(choice == 6) 
  {
    if (a > 0 && a != 1) {
        result = log(b) / log(a);
        printf("Result: %.2f\n", result);
      } else {
        printf("Invalid base for logarithm.\n");
      }
    
  } 
  else
  {
    printf("Please input a valid operator next time");
  }
  return result;
}

int main(int argc, char **argv) {

  double a, b, result;
  int choice;

  printf("Enter operand a: ");
  scanf("%lf", &a);

  printf("Enter operand b: ");
  scanf("%lf", &b);

  printf("Enter operation:\n");
  printf("(1) Addition\n");
  printf("(2) Subtraction\n");
  printf("(3) Multiplication\n");
  printf("(4) Division\n");
  printf("(5) Minimum\n");
  printf("(6) log_a(b)\n");
  scanf("%d", &choice);
  result= calculator(choice,  a, b);
  printf("Result: %.2f\n", result);
 
  
  return 0;
}
