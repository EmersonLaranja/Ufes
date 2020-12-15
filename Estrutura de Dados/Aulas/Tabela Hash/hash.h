#include "palavra.h"

#ifndef HASH_H_
#define HASH_H_

typedef struct hash Hash;

Hash *InicializaHash(int tamanho);

Palavra *Acessa(Hash *hash, char *string);

int contaPalavras(Hash *hash);

void ImprimeHash(Hash *hash);

void LiberaHash(Hash *hash);

#endif /*HASH_H_*/