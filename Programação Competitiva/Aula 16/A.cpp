#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int n = 4, counter_black = 0, counter_white = 0;
  char matrix[n][n];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {

      if (matrix[i + 1][j + 1] == '#') //diagonal
      {
        counter_black++;
      }
      else
      {
        counter_white++;
      }

      if (matrix[i + 1][j] == '#') //below
      {
        counter_black++;
      }
      else
      {
        counter_white++;
      }

      if (matrix[i][j + 1] == '#') //right
      {
        counter_black++;
      }
      else
      {
        counter_white++;
      }

      if (matrix[i][j] == '#')
      {
        counter_black++;
      }
      else
      {
        counter_white++;
      }

      if (counter_black >= 3 || counter_white >= 3)
      {
        cout << "YES" << endl;
        return 0;
      }

      counter_black = 0;
      counter_white = 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}
