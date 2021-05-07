#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  cout << "Qual é o seu nome?:" << endl;
  string nome;
  getline(cin, nome);
  cout << "Seu nome é: " << nome << endl;
  return 0;
}
