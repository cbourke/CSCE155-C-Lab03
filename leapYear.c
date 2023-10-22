/**
 * This program determines if various years are leap years or not.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Returns true (1) if the given year is a leap year,
 * false (0) if it is not a leap year.
 */
int isLeapYear(int year);

int main(int argc, char **argv) {

  bool reportPass = false;
  if (argc > 1 && strcmp(argv[1], "-reportPass") == 0) {
    reportPass = true;
  }

  int numPassed = 0;
  int numFailed = 0;

  // Test cases
  int testCases[] = {2000, 2001, 2100, 2004, 1900, 2024, 2023, 2012};
  int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

  for (int i = 0; i < numTestCases; i++) {
    int year = testCases[i];
    printf("Test Case %d: year = %d: ", i + 1, year);
    if (isLeapYear(year)) {
      printf("PASSED!\n");
      numPassed++;
    } else {
      printf("FAILED!\n");
      numFailed++;
    }
  }

  printf("\nSummary:\n");
  printf("Number of test cases passed: %d\n", numPassed);
  printf("Number of test cases failed: %d\n", numFailed);
  printf("Percentage Passed: %.2f%%\n", (double)numPassed / (numPassed + numFailed) * 100.0);

  if (reportPass) {
    return numPassed;
  } else {
    return numFailed;
  }
}

int isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return 1; // It's a leap year
  } else {
    return 0; // It's not a leap year
  }
}




