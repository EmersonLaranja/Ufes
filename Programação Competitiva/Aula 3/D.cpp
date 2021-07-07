#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int i = 0, x0, y0, x, y, qnt;

  while (scanf("%d", &qnt) != 0)
  {
    if (qnt == 0)
      break;

    scanf("%d %d", &x0, &y0);
    for (i = 0; i < qnt; i++)
    {
      scanf("%d %d", &x, &y);

      if (x == x0 || y == y0)
        cout << "divisa" << endl;

      else if (x > x0 && y > y0) //1 quadrante
        cout << "NE" << endl;

      else if (x < x0 && y > y0) //2 quadrante
        cout << "NO" << endl;

      else if (x < x0 && y < y0) //3 quadrante
        cout << "SO" << endl;

      else if (x > x0 && y < y0) //4 quadrante
        cout << "SE" << endl;
    }
  }

  return 0;
}
