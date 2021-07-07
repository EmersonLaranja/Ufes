
#if !defined(UF_H)
#define UF_H

#include <stdbool.h>
// Inicializa estrutura com N objetos numerados de 0 a N-1.
void UF_init(int N);
// Adiciona uma conexao entre p e q.
void UF_union(int p, int q);
// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(int p);
// Os objetos p e q estao no mesmo componente?
bool UF_connected(int p, int q);

#endif // UF_H
