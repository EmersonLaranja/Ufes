#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int qnt, a, b;
  scanf("%d", &qnt);

  for (int i = 0; i < qnt; i++)
  {
    scanf("%d %d", &a, &b);

    if (a == b)
      cout << "=" << endl;

    else if (a > b)
      cout << ">" << endl;

    else
      cout << "<" << endl;
  }

  return 0;
}
