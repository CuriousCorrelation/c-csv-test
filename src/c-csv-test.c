#include <stdio.h>

#include "c-csv.h"

void test_valid_csv_entire()
{
  const char* file_path = "../data/AAPL.csv";

  CSV    apple_historical;
  Status read_status = CCSV_UNDEFINED;

  read_status = enumerate_csv_from_file(file_path, ",", 1, &apple_historical);

  if (read_status != CCSV_SUCCESS)
    {
      printf("Error parsing csv file: %s\n", file_path);
      printf("Error code is: %d\n", read_status);
    }
  else
    {
      printf("Parsing successful. Freeing.\n");

      free_csv(&apple_historical);
    }
}

void test_valid_csv()
{

  const char* file_path = "../data/AAPL.csv";

  CSV    apple_historical;
  Status read_status = CCSV_UNDEFINED;

  read_status = enumerate_csv_from_file(file_path, ",", 1, &apple_historical);

  if (read_status != CCSV_SUCCESS)
    {
      printf("Error parsing csv file: %s\n", file_path);
      printf("Error code is: %d\n", read_status);
    }
  else
    {

      puts("Header\n");

      for (int i = 0; i < apple_historical.number_of_columns; ++i)
        {
          printf("%s ", apple_historical.header[i]);
        }

      for (int i = 0; i < 10; ++i)
        {
          for (int j = 0; j < apple_historical.number_of_columns; ++j)
            {
              printf("%s ", apple_historical.table[i][j]);
            }
        }

      puts("Parsing successful. Freeing.\n");

      free_csv(&apple_historical);
    }
}

void test_invalid_csv()
{

  const char* file_path = "../data/AAPL_invalid.csv";

  CSV    apple_historical;
  Status read_status = CCSV_UNDEFINED;

  read_status = enumerate_csv_from_file(file_path, ",", 1, &apple_historical);

  if (read_status != CCSV_SUCCESS)
    {
      printf("Error parsing csv file: %s\n", file_path);
      printf("Error code is: %d\n", read_status);
    }
  else
    {

      puts("Header\n");

      for (int i = 0; i < apple_historical.number_of_columns; ++i)
        {
          printf("%s ", apple_historical.header[i]);
        }

      for (int i = 0; i < 10; ++i)
        {
          for (int j = 0; j < apple_historical.number_of_columns; ++j)
            {
              printf("%s ", apple_historical.table[i][j]);
            }
        }

      puts("Parsing successful. Freeing.\n");

      free_csv(&apple_historical);
    }
}

void test_partially_missing_csv()
{

  const char* file_path = "../data/AAPL_partially_missing.csv";

  CSV    apple_historical;
  Status read_status = CCSV_UNDEFINED;

  read_status = enumerate_csv_from_file(file_path, ",", 1, &apple_historical);

  if (read_status != CCSV_SUCCESS)
    {
      printf("Error parsing csv file: %s\n", file_path);
      printf("Error code is: %d\n", read_status);
    }
  else
    {

      puts("Header\n");

      for (int i = 0; i < apple_historical.number_of_columns; ++i)
        {
          printf("%s ", apple_historical.header[i]);
        }

      for (int i = 0; i < apple_historical.number_of_rows; ++i)
        {
          for (int j = 0; j < apple_historical.number_of_columns; ++j)
            {
              printf("%s ", apple_historical.table[i][j]);
            }
        }

      puts("Parsing successful. Freeing.\n");

      free_csv(&apple_historical);
    }
}

void test_valid_csv_entire_unheadered()
{
  const char* file_path = "../data/AAPL_unheadered.csv";

  CSV    apple_historical;
  Status read_status = CCSV_UNDEFINED;

  read_status = enumerate_csv_from_file(file_path, ",", 0, &apple_historical);

  if (read_status != CCSV_SUCCESS)
    {
      printf("Error parsing csv file: %s\n", file_path);
      printf("Error code is: %d\n", read_status);
    }
  else
    {
      for (int i = 0; i < apple_historical.number_of_rows; ++i)
        {
          for (int j = 0; j < apple_historical.number_of_columns; ++j)
            {
              printf("%s ", apple_historical.table[i][j]);
            }
        }

      printf("Parsing successful. Freeing.\n");

      free_csv(&apple_historical);
    }
}
