#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int t, k, n;
  cin >> t;

  for (int j = 0; j < t; j++)
  {
    cin >> n >> k;
    cout << k + ((k - 1) / (n - 1)) << endl;
  }

  return 0;
}
