#include <stdio.h>

int main(int argc, char const *argv[])
{
  int i, j, line, column, sum_line, sum_column, count_lines = 0, count_columns = 0, n, matrix[100][100];

  while (scanf("%d", &n))
  {
    if (n == 0)
      break;
    count_lines = 0;
    count_columns = 0;
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        scanf("%d", &matrix[i][j]);
      }
    }

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        sum_line += matrix[i][j];
      }
      if (sum_line % 2 == 1)
      {
        count_lines++;
        line = i + 1;
      }
      sum_line = 0;
    }

    if (count_lines > 1)
    {
      printf("Corrupt\n");
      continue;
    }

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        sum_column += matrix[j][i];
      }
      if (sum_column % 2 == 1)
      {
        count_columns++;
        column = i + 1;
      }
      sum_column = 0;
    }

    if (count_columns > 1)
    {
      printf("Corrupt\n");
      continue;
    }

    if (count_columns == 0 && count_lines == 0)
    {
      printf("OK\n");
    }
    else
    {
      printf("Change bit (%d,%d)\n", line, column);
    }
  }

  return 0;
}
