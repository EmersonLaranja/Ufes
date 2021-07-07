#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int i, qnt, sal1, sal2, sal3;

  scanf("%d", &qnt);

  for (i = 0; i < qnt; i++)
  {

    scanf("%d %d %d", &sal1, &sal2, &sal3);

    if ((sal1 > sal2 && sal1 < sal3) || (sal1 > sal3 && sal1 < sal2))
      cout << "Case " << (i + 1) << ": " << sal1 << endl;

    else if ((sal2 > sal1 && sal2 < sal3) || (sal2 > sal3 && sal2 < sal1))
      cout << "Case " << (i + 1) << ": " << sal2 << endl;

    else
      cout << "Case " << (i + 1) << ": " << sal3 << endl;
  }

  return 0;
}
