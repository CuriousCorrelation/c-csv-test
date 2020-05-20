#include <stdio.h>

#include "c-csv-test.h"

int main()
{
  int r1 = -1;
  int r2 = -1;
  int r3 = -1;
  int r4 = -1;
  int r5 = -1;

  printf("Testing on valid csv file (entire file, not terminal output).");
  r1 = test_valid_csv_entire();

  printf("Testing on valid csv file.");
  r2 = test_valid_csv();

  printf("Testing on invalid csv file.");
  r3 = test_invalid_csv();

  printf("Testing on partially missing csv file.");
  r4 = test_partially_missing_csv();

  printf("Testing on valid unheadered csv file (entire file, not terminal output).");
  r5 = test_valid_csv_entire_unheadered();

  if (r1 == -1)
    {
      puts("test_valid_csv_entries failed.");
      return -1;
    }
  else if (r2 == -1)
    {
      puts("test_valid_csv failed.");
      return -1;
    }
  else if (r3 == -1)
    {
      puts("test_invalid_csv failed.");
      return -1;
    }
  else if (r4 == -1)
    {
      puts("test_partially_missing_csv failed.");
      return -1;
    }
  else if (r5 == -1)
    {
      puts("test_valid_csv_entire_unheadered failed.");
      return -1;
    }
  else
    {
      return 0;
    }
}
