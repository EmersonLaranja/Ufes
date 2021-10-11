#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
  int N;
  cin >> N;

  vector<int> h(N); //alturas
  for (int i = 0; i < N; i++)
    cin >> h[i];

  vector<int> dist(N); //soma das distancias
  dist[0] = 0;
  dist[1] = dist[0] + abs(h[1] - h[0]);
  int op1, op2;
  for (int i = 2; i < N; i++)
  {
    op1 = dist[i - 1] + abs(h[i] - h[i - 1]); //pulei 1 + distancia de onde parti
    op2 = dist[i - 2] + abs(h[i] - h[i - 2]); //pulei 2 + distancia de onde parti
    dist[i] = min(op1, op2);
  }

  cout << dist[N - 1] << endl;
  return 0;
}
