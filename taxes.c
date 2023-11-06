/**
 * This program computes income taxes based on adjusted
 * gross income and a child tax credit.
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  double agi = 0.0;
  char c = 'N';
  double tax = 0.0;
  double childCredit = 0.0;
  double totalTax = 0.0;
  int numChildren = 0;

  printf("Please enter your adjusted gross income (AGI): ");
  scanf("%lf", &agi);
  //remove the "enter" endline character
  getchar(); 

  printf("Do you have any children? (Y) or (N)? ");
  c = getchar();

  if(c == 'y' || c == 'Y') {
    printf("How many children do you have? ");
    scanf("%d", &numChildren);
  }
   if (agi <= 19900)
  {
    tax = agi * 0.1;
  }
   else if (agi <= 81050) 
  {
    tax = 2000 + (agi - 19900) * 0.15;
  }
   else if (agi <= 172750) 
  {
    tax = 7000 + (agi - 81050) * 0.2;
  }
   else 
 {
    tax = 17000 + (agi - 172750) * 0.25;
  
 }
  // Compute the child credit based on the number of children
  childCredit = numChildren * 1000;

  // Compute the total tax
  totalTax = tax - childCredit;
  
  //display result
  printf("\nTax Calculation:\n");
  printf("AGI:          $%10.2f\n", agi);
  printf("Tax:          $%10.2f\n", tax);
  printf("Child Credit: $%10.2f\n", childCredit);
  printf("Total Tax:    $%10.2f\n", totalTax);

  return 0;
}
