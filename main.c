#include <stdio.h>

#include "c-csv-test.h"

int main()
{

  printf("Testing on valid csv file (entire file, not terminal output).");
  test_valid_csv_entire();

  printf("Testing on valid csv file.");
  test_valid_csv();

  printf("Testing on invalid csv file.");
  test_invalid_csv();

  printf("Testing on partially missing csv file.");
  test_partially_missing_csv();

  printf("Testing on valid unheadered csv file (entire file, not terminal output).");
  test_valid_csv_entire_unheadered();
}
