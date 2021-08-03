#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
  string line;
  while (getline(cin, line))
  {
    if (line.compare("#") == 0)
      break;

    if (next_permutation(line.begin(), line.end()))
      cout << line << endl;
    else
      cout << "No Successor" << endl;
  }
  return 0;
}
