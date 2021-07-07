#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int t, n, s, max = 0;

  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &s);

      if (s >= max)
        max = s;
    }
    cout << "Case " << (i + 1) << ": " << max << endl;
    max = 0;
  }

  return 0;
}
