#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAM_MATRIZ_LINHA 100
#define TAM_MATRIZ_COLUNA 101

typedef struct {
    int pontosFeitos;
    int pontosRecebidos;
    int pontuacaoTotal;
} tPontuacao;

typedef struct {
    int qntJogadas;
    int coordenadaLinha;
    int coordenadaColuna;
    int contJogada;
} tJogada;

typedef struct {
    tJogada jogada;
    tPontuacao pontuacao;
    char nome[17];
    int qntPalavras;
    char palavra[25][17];
    char maiorPalavra[17];
} tJogador;

typedef struct {
    int tam;
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA];
    int sucesso; //Usada para atribuir sucesso da palavra no tabuleiro a um jogador
} tTabuleiro;

typedef struct {
    int pontuacao;
    int jogada;
    char palavra[25];

} tEstatisticas;

typedef struct{
    int matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA];
    int tamPalavra;
}tMapaOrdenado;

typedef struct {
    tJogador jogador1;
    tJogador jogador2;
    tTabuleiro tabuleiro;
    tTabuleiro matrizDasPalavras;
    tEstatisticas estatisticas[50]; // max 25 palavras por jogador
    int qntTurnos;
    int qntPalavras;
    tMapaOrdenado mapaOrdenado;

} tJogo;

tJogo InicializacaoDoArquivoConfig(tJogo jogo, char config[]) {
    FILE *arquivo;
    arquivo = fopen(config, "r"); //Abre arquivo "config.txt" com permissao apenas para leitura

    if (arquivo == NULL) {
        printf("Nao foi possivel ler o caminho:%s\n", config);
        exit(1);
    }

    int i = 0, j = 0;

    //Jogadas para cada Jogador
    fscanf(arquivo, "%d", &jogo.qntTurnos);
    jogo.jogador1.jogada.qntJogadas = (jogo.qntTurnos);
    jogo.jogador2.jogada.qntJogadas = (jogo.qntTurnos);

    //tamanho da matriz
    fscanf(arquivo, "%d", &jogo.matrizDasPalavras.tam);

    //Preenchendo a Matriz 
    for (i = 0; (jogo.matrizDasPalavras.tam) > i; i++) {
        fscanf(arquivo, "%s", jogo.matrizDasPalavras.matriz[i]);
    }

    //Quantidade de Palavras para cada jogador
    fscanf(arquivo, "%d", &jogo.jogador1.qntPalavras);
    jogo.jogador2.qntPalavras = jogo.jogador1.qntPalavras;
    jogo.qntPalavras = jogo.jogador1.qntPalavras + jogo.jogador2.qntPalavras;

    //Preenchendo as Palavras de cada jogador
    for (i = 0; (jogo.jogador1.qntPalavras) > i; i++) {
        fscanf(arquivo, "%s", jogo.jogador1.palavra[i]);
    }
    for (i = 0; (jogo.jogador2.qntPalavras) > i; i++) {
        fscanf(arquivo, "%s", jogo.jogador2.palavra[i]);
    }

    fclose(arquivo);

    return jogo;
}

void PreencheNomeJogador(char* nome) {
    scanf("%[^\n]", nome); //Armazena valores ate \n
    scanf("%*c"); //Elimina o \n
}

tJogo OrganizaNomesJogo(tJogo jogo) {

    printf("Nome do Jogador 1:\n");
    PreencheNomeJogador(jogo.jogador1.nome);

    printf("Nome do Jogador 2:\n");
    PreencheNomeJogador(jogo.jogador2.nome);

    return jogo;
}

tJogo InicializaPontuacaoJogo(tJogo jogo) { //Remove todo lixo das pontuacoes

    jogo.jogador1.pontuacao.pontuacaoTotal = 0;
    jogo.jogador1.pontuacao.pontosFeitos = 0;
    jogo.jogador1.pontuacao.pontosRecebidos = 0;
    jogo.jogador2.pontuacao.pontuacaoTotal = 0;
    jogo.jogador2.pontuacao.pontosFeitos = 0;
    jogo.jogador2.pontuacao.pontosRecebidos = 0;
    return jogo;
}

tJogo InicializaJogadaJogo(tJogo jogo) {
    jogo.jogador1.jogada.contJogada = 0; //Remove todo lixo dos contadores
    jogo.jogador2.jogada.contJogada = 0;
    return jogo;
}

tJogo CriaTabuleiroJogo(tJogo jogo) {
    int i, j;
    jogo.tabuleiro = jogo.matrizDasPalavras; //Tabuleiro deve ter mesma formatacao da matriz de palavras
    for (i = 0; jogo.tabuleiro.tam > i; i++) {
        for (j = 0; jogo.tabuleiro.tam > j; j++) {
            jogo.tabuleiro.matriz[i][j] = '-';
        }
    }
    return jogo;
}

int EhMaiorPalavra(char* palavra, char* maiorAtual) {//Compara se a primeira palavra e maior que a segunda
    int x, y;
    x = strlen(palavra); //Armazena tamanho do vetor em x
    y = strlen(maiorAtual); //Armazena tamanho do vetor em y
    return x>y;
}

tJogador PreencheMaiorPalavraJogador(tJogador jogador) {//retorna jogador e  sua maior palavra
    int i = 0;

    strcpy(jogador.maiorPalavra, jogador.palavra[i]); //copia valor da primeira palavra para o vetor "maiorPalavra"

    while (jogador.qntPalavras > i) {
        
        if (EhMaiorPalavra(jogador.palavra[i], jogador.maiorPalavra)) {
            strcpy(jogador.maiorPalavra, jogador.palavra[i]);
        }
        i++;
    }
    return jogador;
}



void GeraArquivoDeInicializacao(tJogo jogo, char inicializacao[]) {

    FILE* arquivoInicializacao;

    arquivoInicializacao = fopen(inicializacao, "w"); //arquivo sera criado e escrito

    int i = 0, j = 0, cont = 0;
    char d = '\0', c = '\0';

    fprintf(arquivoInicializacao, "--Jogador 1--\n");

    fprintf(arquivoInicializacao, "Nome: %s\n", jogo.jogador1.nome);

    fprintf(arquivoInicializacao, "Palavras:\n");

    for (i = 0; jogo.jogador1.qntPalavras > i; i++) {
        fprintf(arquivoInicializacao, "%s\n", jogo.jogador1.palavra[i]);
    }

    fprintf(arquivoInicializacao, "Maior Palavra: \n");

    fprintf(arquivoInicializacao, "%s\n", jogo.jogador1.maiorPalavra);

    fprintf(arquivoInicializacao, "Letras Iniciais: \n");

    for (c = 'a'; c <= 'z'; c++) {//Percorre alfabeto

        for (i = 0; jogo.jogador1.qntPalavras > i; i++) {//Percorre palavras do jogador
            if (jogo.jogador1.palavra[i][0] == c) {//se a inicial da palavra eh igual a letra em questao
                cont++;
            }
        }
        if (cont != 0) {//Eliminar letras que nao sao iniciais das palavras do jogador
            fprintf(arquivoInicializacao, "%c -> %d\n", c, cont);
        }
        cont = 0;
    }

    fprintf(arquivoInicializacao, "\n");

    fprintf(arquivoInicializacao, "--Jogador 2--\n");

    fprintf(arquivoInicializacao, "Nome: %s\n", jogo.jogador2.nome);

    fprintf(arquivoInicializacao, "Palavras:\n");

    for (i = 0; jogo.jogador2.qntPalavras > i; i++) {
        fprintf(arquivoInicializacao, "%s\n", jogo.jogador2.palavra[i]);
    }

    fprintf(arquivoInicializacao, "Maior Palavra: \n");

    fprintf(arquivoInicializacao, "%s\n", jogo.jogador2.maiorPalavra);

    fprintf(arquivoInicializacao, "Letras Iniciais: \n");

    for (c = 'a'; c <= 'z'; c++) {//mesma iteracao do Jogador1

        for (i = 0; jogo.jogador2.qntPalavras > i; i++) {
            if (jogo.jogador2.palavra[i][0] == c) {
                cont++;
            }
        }
        if (cont != 0) {
            fprintf(arquivoInicializacao, "%c -> %d\n", c, cont);
        }
        cont = 0;
    }

    fclose(arquivoInicializacao);
}



tJogo CriaMapaJogo(tJogo jogo){
    int i,j;
    
    for (i = 0; jogo.tabuleiro.tam > i; i++) {
        for (j = 0; jogo.tabuleiro.tam > j; j++) {
            jogo.mapaOrdenado.matriz[i][j] = 0;
        }
    }
    
    
    return jogo;
}

tJogo CriaJogo(tJogo jogo, char config[]) {
    jogo = InicializacaoDoArquivoConfig(jogo, config); //Armazena valores do arquivo no jogo
    jogo = OrganizaNomesJogo(jogo);
    jogo = InicializaPontuacaoJogo(jogo);
    jogo = InicializaJogadaJogo(jogo);
    jogo = CriaTabuleiroJogo(jogo);
    jogo.jogador1 = PreencheMaiorPalavraJogador(jogo.jogador1);
    jogo.jogador2 = PreencheMaiorPalavraJogador(jogo.jogador2);
    jogo=CriaMapaJogo(jogo);
    return jogo;
}

int EstaMaiuscula(char letra) {
    if (letra >= 'A' && letra <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

void ImprimeTabuleiro(tTabuleiro matrizTabuleiro) {
    int i = 0, j = 0;

    //Imprime borda superior do tabuleiro
    printf("    ");
    while (matrizTabuleiro.tam - 1 > i) {
        printf("%.2d ", i);
        i++;
    }
    printf("%.2d", i);
    printf("\n");

    //Imprime coluna lateral e matriz do tabuleiro
    for (i = 0; matrizTabuleiro.tam > i; i++) {
        printf("%.2d|", i);
        for (j = 0; matrizTabuleiro.tam > j; j++) {
            printf(" %c ", matrizTabuleiro.matriz[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

tJogador ColetaCoordenadasJogador(tJogador jogador) {

    scanf("%d %d", &jogador.jogada.coordenadaLinha,
    &jogador.jogada.coordenadaColuna);
    
    return jogador;

}

int EstaFora(int l, int c, int tam) {//Verifica se jogada esta fora do tabuleiro
    if (l >= tam || l < 0 || c >= tam || c < 0) {
        return 1;
    } else {
        return 0;
    }
}

int EhRepetida(int l, int c, int tam, char tabuleiro[100][101]) {//Verifica se coordenadas ja foram jogadas
    
    if (tabuleiro[l][c] >= 'A' && tabuleiro[l][c] <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

tJogada AtualizaQntJogadas(tJogada jogada) {
    
    jogada.qntJogadas = jogada.qntJogadas - 1;
    return jogada;
}

int EhIgual(char letraDaMatriz, char letraDaPalavra) {
    
    if (letraDaMatriz == letraDaPalavra) {
        return 1;
    } else {
        return 0;
    }
}

int EhMaiuscula(char letra) {
    
    if (letra >= 'A' && letra <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int EhMinuscula(char letra) {
    
    if (letra >= 'a' && letra <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

tTabuleiro ColocaLetraMaiusculaNoTabuleiro(int l, int c, char letraMinuscula,
    tTabuleiro tabuleiro) {
    
    char letraMaiuscula = letraMinuscula - 32; //transforma letra minuscula em maiuscula
    tabuleiro.matriz[l][c] = letraMaiuscula;
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroAcima(int l, int c, char* palavra,
    tTabuleiro tabuleiro) {
    
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra); //tamanho da palavra 
    
    while (tamPalavra > i) {
        
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i]; /*atribui letra da palavra 
                                                 para a posicao do tabuleiro*/
        }
        l--;
        i++;
    }
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroAbaixo(int l, int c, char* palavra,
    tTabuleiro tabuleiro) {
    
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    
    while (tamPalavra > i) {
        
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i];
        }
        l++;
        i++;
    }
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroAEsquerda(int l, int c, char* palavra, 
    tTabuleiro tabuleiro) {
    
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    
    while (tamPalavra > i) {
        
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i];
        }
        c--;
        i++;
    }
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroADireita(int l, int c, char* palavra, 
    tTabuleiro tabuleiro) {
    
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    
    while (tamPalavra > i) {
        
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i];
        }
        c++;
        i++;
    }
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroNaDiagonalSuperiorEsquerda(int l, int c,
    char* palavra, tTabuleiro tabuleiro) {
    
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    
    while (tamPalavra > i) {
        
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i];
        }
        l--;
        c--;
        i++;
    }
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroNaDiagonalSuperiorDireita(int l, int c,
    char* palavra, tTabuleiro tabuleiro) {
   
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    
    while (tamPalavra > i) {
        
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i];
        }
        l--;
        c++;
        i++;
    }
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroNaDiagonalInferiorEsquerda(int l, int c,
    char* palavra, tTabuleiro tabuleiro) {
    
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    
    while (tamPalavra > i) {
        
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i];
        }
        l++;
        c--;
        i++;
    }
    return tabuleiro;
}

tTabuleiro PreencheTabuleiroNaDiagonalInferiorDireita(int l, int c,
    char* palavra, tTabuleiro tabuleiro) {
   
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
   
    while (tamPalavra > i) {
       
        if (!EhRepetida(l, c, tabuleiro.tam, tabuleiro.matriz)) {
            tabuleiro.matriz[l][c] = palavra[i];
        }
        l++;
        c++;
        i++;
    }
    return tabuleiro;
}

int EstaAcima(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {
    //verifica se a palavra esta nas coordenadas acimas as dadas
    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];

    while (tamPalavra > i) {
        
        if (!EstaFora(l, c, tamMatriz)) {
            strDaMatriz[i] = matriz[l][c];
            l--;
        } else {
            strDaMatriz[i] = '\0'; //Se passar dos limites do \0

        }
        i++;
    }
    strDaMatriz[i] = '\0';
    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32; /*transforma letra maiuscula em minuscula*/
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0; //palavra nao esta nesta orientacao

    }
    return 1; //palavra esta nesta orientacao
}

int EstaAbaixo(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];
    char qualquer;
    while (tamPalavra > i) {
        if (!EstaFora(l, c, tamMatriz)) {
            qualquer = matriz[l][c];
            strDaMatriz[i] = matriz[l][c];
            l++;
        } else {
            strDaMatriz[i] = '\0';
        }
        i++;
    }
    strDaMatriz[i] = '\0';

    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32;
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0;

    }
    return 1;
}

int EstaAEsquerda(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];

    while (tamPalavra > i) {
        if (!EstaFora(l, c, tamMatriz)) {
            strDaMatriz[i] = matriz[l][c];
            c--;
        } else {
            strDaMatriz[i] = '\0';
        }
        i++;
    }
    strDaMatriz[i] = '\0';
    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32;
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0;

    }
    return 1;
}

int EstaADireita(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];

    while (tamPalavra > i) {
        if (!EstaFora(l, c, tamMatriz)) {
            strDaMatriz[i] = matriz[l][c];
            c++;
        } else {
            strDaMatriz[i] = '\0';
        }
        i++;
    }
    strDaMatriz[i] = '\0';
    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32;
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0;

    }
    return 1;
}

int EstaNaDiagonalSuperiorEsquerda(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];

    while (tamPalavra > i) {
        if (!EstaFora(l, c, tamMatriz)) {
            strDaMatriz[i] = matriz[l][c];
            l--;
            c--;
        } else {
            strDaMatriz[i] = '\0';
        }
        i++;
    }
    strDaMatriz[i] = '\0';
    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32;
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0;

    }
    return 1;
}

int EstaNaDiagonalSuperiorDireita(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];

    while (tamPalavra > i) {
        if (!EstaFora(l, c, tamMatriz)) {
            strDaMatriz[i] = matriz[l][c];
            l--;
            c++;
        } else {
            strDaMatriz[i] = '\0';
        }
        i++;
    }
    strDaMatriz[i] = '\0';
    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32;
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0;

    }
    return 1;
}

int EstaNaDiagonalInferiorEsquerda(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];

    while (tamPalavra > i) {
        if (!EstaFora(l, c, tamMatriz)) {
            strDaMatriz[i] = matriz[l][c];
            l++;
            c--;
        } else {
            strDaMatriz[i] = '\0';
        }
        i++;
    }
    strDaMatriz[i] = '\0';
    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32;
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0;

    }
    return 1;
}

int EstaNaDiagonalInferiorDireita(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    char letraAux;
    int i = 0, tamPalavra;
    tamPalavra = strlen(palavra);
    char strDaMatriz[tamPalavra + 1];

    while (tamPalavra > i) {
        if (!EstaFora(l, c, tamMatriz)) {
            strDaMatriz[i] = matriz[l][c];
            l++;
            c++;
        } else {
            strDaMatriz[i] = '\0';
        }
        i++;
    }
    strDaMatriz[i] = '\0';
    i = 0;
    while (tamPalavra > i) {

        if (EhMaiuscula(strDaMatriz[i])) {
            letraAux = strDaMatriz[i] + 32;
            if (EhIgual(letraAux, palavra[i])) {
                i++;
                continue;
            }
        }
        if (EhMinuscula(strDaMatriz[i])) {
            if (EhIgual(strDaMatriz[i], palavra[i])) {
                i++;
                continue;
            }
        }

        return 0;

    }
    return 1;
}

int EncontraOrientacao(int l, int c, char* palavra, int tamMatriz,
    char matriz[TAM_MATRIZ_LINHA][TAM_MATRIZ_COLUNA]) {

    if (EstaAcima(l, c, palavra, tamMatriz, matriz)) {
        return 1;
    }
    if (EstaAbaixo(l, c, palavra, tamMatriz, matriz)) {
        return 2;
    }
    if (EstaAEsquerda(l, c, palavra, tamMatriz, matriz)) {
        return 3;
    }
    if (EstaADireita(l, c, palavra, tamMatriz, matriz)) {
        return 4;
    }
    if (EstaNaDiagonalSuperiorEsquerda(l, c, palavra, tamMatriz, matriz)) {
        return 5;
    }
    if (EstaNaDiagonalSuperiorDireita(l, c, palavra, tamMatriz, matriz)) {
        return 6;
    }
    if (EstaNaDiagonalInferiorEsquerda(l, c, palavra, tamMatriz, matriz)) {
        return 7;
    }
    if (EstaNaDiagonalInferiorDireita(l, c, palavra, tamMatriz, matriz)) {
        return 8;
    }

    return 0; // sem orientacao
}

int FoiEncontrada(char* palavra, int tam, char tabuleiro[100][101]) {
    int orientacao = 0, i = 0, j = 0;

    //percorre elemento a elemento da matriz
    for (i = 0; tam > i; i++) {
        for (j = 0; tam > j; j++) {
            orientacao = EncontraOrientacao(i, j, palavra, tam, tabuleiro);
            //verifica se palavra esta contida e retorna sua orientacao
            if (orientacao != 0) {//se tem orientacao
                if (EstaMaiuscula(tabuleiro[i][j])) {//ja foi jogada
                    return 1;
                }
            }
        }
    }

    return 0;
}

void EsvaziaPalavra(char* palavra) {//transforma palavra num vetor de \0
    int tam, i = 0;
    tam = strlen(palavra);
    while (tam > i) {
        palavra[i] = '\0';
        i++;
    }
}

void ImprimePalavrasRestantesJogo(tJogo jogo, tJogador jogador1, tJogador jogador2) {

    int i = 0, j = 0, z = 0;
    int contVaziaJ1 = 0, contVaziaJ2 = 0; //contador para palavras ja encontradas
    int qntPalavras = ((jogo.qntPalavras) / 2);
    char novaListaJogador1[25][17];
    char novaListaJogador2[25][17];

    printf("|            Palavras Restantes           |\n");

    printf("|%-16s(%.2d)|%-16s(%.2d)|\n", jogador1.nome,
    jogador1.pontuacao.pontuacaoTotal, jogador2.nome,
    jogador2.pontuacao.pontuacaoTotal);

    printf("|--------------------|--------------------|\n");


    //Remove palavras ja jogadas do jogador1
    for (i = 0; qntPalavras > i; i++) { // divisao: cada linha possui duas palavras

        if (FoiEncontrada(jogador1.palavra[i],
            jogo.tabuleiro.tam,
            jogo.tabuleiro.matriz)) {
            
            EsvaziaPalavra(jogador1.palavra[i]);
            contVaziaJ1++;
        }
    }
    //Remove palavras ja jogadas do jogador2
    for (i = 0, j = 0; qntPalavras > i; i++) { // divisao: cada linha possui duas palavras

        if (FoiEncontrada(jogador2.palavra[i],
            jogo.tabuleiro.tam,
            jogo.tabuleiro.matriz)) {
            
            EsvaziaPalavra(jogador2.palavra[i]);
            contVaziaJ2++;
        }
    }

    i = 0;
    j = 0;

    //Sobe todas as palavras nao vazias para jogador1
    while (qntPalavras > i) {
        
        if (jogador1.palavra[i][0] == '\0') {//se a inicial da palavra for \0,ignore-a
            i++;
            continue;
            
        } else {//Ao contrario, preenche na nova lista
            //strcpy armazena palavra numa nova lista
            strcpy(novaListaJogador1[j], jogador1.palavra[i]);
            i++;
            j++;

        }
    }

    i = 0;
    j = 0;
    //Sobe todas as palavras nao vazias para jogador2
    while (qntPalavras > i) {
        if (jogador2.palavra[i][0] == '\0') {//se a inicial da palavra for \0,ignore-a
            i++;
            continue;
        } else {//Ao contrario, preenche na nova lista
            strcpy(novaListaJogador2[j], jogador2.palavra[i]);
            i++;
            j++;

        }
    }
    z = qntPalavras - 1;
    //    Preenche posicoes vazias para jogador1
    while (contVaziaJ1 > 0) {
        EsvaziaPalavra(novaListaJogador1[z]);
        z--;
        contVaziaJ1--;
    }

    z = qntPalavras - 1;
    //    Preenche posicoes vazias para jogador2
    while (contVaziaJ2 > 0) {
        EsvaziaPalavra(novaListaJogador2[z]);
        z--;
        contVaziaJ2--;
    }


    for (i = 0; qntPalavras > i; i++) {//Percorre lista de palavras
       
        if (novaListaJogador1[i][0] == '\0' && novaListaJogador2[i][0] == '\0') {
            continue; //linha vazia no tabuleiro nao sera impressa
        } else {
            printf("|%-20s|%-20s|\n", novaListaJogador1[i], novaListaJogador2[i]);
        }
    }

    printf("\n");
}

tTabuleiro AtualizaTabuleiro(
        tJogador jogadorDaVez, tJogador jogadorAdversario,
        tTabuleiro tabuleiro, tTabuleiro matrizDasPalavras) {

    int l = jogadorDaVez.jogada.coordenadaLinha;
    int c = jogadorDaVez.jogada.coordenadaColuna;
    int i = 0, orientacao = 0;
    tabuleiro.sucesso = 0;

    //ORIENTAÇÕES:
    //    0= Sem orientação;
    //    1=Acima;
    //    2=Abaixo;
    //    3=Esquerda;
    //    4=Direita;
    //    5=Na diagonal superior esquerda;
    //    6=Na diagonal superior direita;
    //    7=Na diagonal inferior esquerda;
    //    8=Na diagonal inferior direita;

    //sucesso = 0; nenhum jogador pontuou
    //sucesso = 1; jogador da vez fez o ponto
    //sucesso = 2;jogador da vez deu o ponto


    for (i = 0; jogadorDaVez.qntPalavras > i; i++) {
        if (EhIgual(matrizDasPalavras.matriz[l][c],
            jogadorDaVez.palavra[i][0])) {
            
            orientacao = EncontraOrientacao(l, c,
                jogadorDaVez.palavra[i],
                matrizDasPalavras.tam,
                matrizDasPalavras.matriz);

            if (orientacao == 1) {
               
                tabuleiro = PreencheTabuleiroAcima(l, c, 
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c, 
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

            if (orientacao == 2) {
                
                tabuleiro = PreencheTabuleiroAbaixo(l, c,
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

            if (orientacao == 3) {
                
                tabuleiro = PreencheTabuleiroAEsquerda(l, c,
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

            if (orientacao == 4) {
                
                tabuleiro = PreencheTabuleiroADireita(l, c, 
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c, 
                    matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

            if (orientacao == 5) {
                
                tabuleiro = PreencheTabuleiroNaDiagonalSuperiorEsquerda(l, c, 
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

            if (orientacao == 6) {
                
                tabuleiro = PreencheTabuleiroNaDiagonalSuperiorDireita(l, c,
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

            if (orientacao == 7) {
                
                tabuleiro = PreencheTabuleiroNaDiagonalInferiorEsquerda(l, c,
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c, 
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

            if (orientacao == 8) {
                
                tabuleiro = PreencheTabuleiroNaDiagonalInferiorDireita(l, c,
                jogadorDaVez.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 1;
                
                return tabuleiro;
            }

        }
    }

    for (i = 0; jogadorAdversario.qntPalavras > i; i++) {
        
        if (EhIgual(matrizDasPalavras.matriz[l][c],
        jogadorAdversario.palavra[i][0])) {// Se as coordenadas forem iniciais da palavra
            
            orientacao = EncontraOrientacao(l, c, jogadorAdversario.palavra[i],
            matrizDasPalavras.tam,
            matrizDasPalavras.matriz);

            if (orientacao == 1) {
                
                tabuleiro = PreencheTabuleiroAcima(l, c,
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c, 
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

            if (orientacao == 2) {
                
                tabuleiro = PreencheTabuleiroAbaixo(l, c, 
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

            if (orientacao == 3) {
                
                tabuleiro = PreencheTabuleiroAEsquerda(l, c, 
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

            if (orientacao == 4) {
                
                tabuleiro = PreencheTabuleiroADireita(l, c,
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c, 
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

            if (orientacao == 5) {
                
                tabuleiro = PreencheTabuleiroNaDiagonalSuperiorEsquerda(l, c,
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

            if (orientacao == 6) {
                
                tabuleiro = PreencheTabuleiroNaDiagonalSuperiorDireita(l, c,
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

            if (orientacao == 7) {
                
                tabuleiro = PreencheTabuleiroNaDiagonalInferiorEsquerda(l, c,
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

            if (orientacao == 8) {
                tabuleiro = PreencheTabuleiroNaDiagonalInferiorDireita(l, c,
                jogadorAdversario.palavra[i], tabuleiro);
                
                tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
                matrizDasPalavras.matriz[l][c], tabuleiro);
                
                tabuleiro.sucesso = 2;
                
                return tabuleiro;
            }

        }
    }

    tabuleiro = ColocaLetraMaiusculaNoTabuleiro(l, c,
    matrizDasPalavras.matriz[l][c], tabuleiro);
    
    return tabuleiro;

}

int PontuaJogadaFeita(int pontuacao) {
    pontuacao = pontuacao + 2;
    return pontuacao;
}

int PontuaJogadaRecebida(int pontuacao) {
    pontuacao = pontuacao + 1;
    return pontuacao;
}

//soma pontuacoes feitas e recebidas numa variavel

tJogador AtualizaPontuacaoTotalJogador(tJogador jogador) {
    
    jogador.pontuacao.pontuacaoTotal = 
    jogador.pontuacao.pontosFeitos + jogador.pontuacao.pontosRecebidos;
    
    return jogador;
}

int AcabaramPalavrasJogador(tJogador jogador, tTabuleiro tabuleiro) {

    int i = 0, contEncontradas = 0;

    //percorre palavras do jogador e conta se foi encontrada
    for (i = 0; jogador.qntPalavras > i; i++) {

        if (FoiEncontrada(jogador.palavra[i], tabuleiro.tam, tabuleiro.matriz)){
            contEncontradas++;
        }
    }

    //se todas foram encontradas, retorna 1
    if (jogador.qntPalavras == contEncontradas) {
        return 1;
    } else {
        return 0;
    }


}

int AcabaramJogadasJogador(tJogador jogador) {
    if (jogador.jogada.qntJogadas == 0) {
        return 1;
    } else {
        return 0;
    }
}

int TerminouJogo(tJogo jogo) {

    if (AcabaramJogadasJogador(jogo.jogador1) && 
        AcabaramJogadasJogador(jogo.jogador2)) {
        
        return 1;
    }
    if (AcabaramPalavrasJogador(jogo.jogador1, jogo.tabuleiro) ||
        AcabaramPalavrasJogador(jogo.jogador2, jogo.tabuleiro)) {

        return 1;
    }


    return 0;
}

//ORIENTAÇÕES:
    //    0= Sem orientação;
    //    1=Acima;
    //    2=Abaixo;
    //    3=Esquerda;
    //    4=Direita;
    //    5=Na diagonal superior esquerda;
    //    6=Na diagonal superior direita;
    //    7=Na diagonal inferior esquerda;
    //    8=Na diagonal inferior direita;

tMapaOrdenado AtualizaMapaComPalavra(tMapaOrdenado mapa, int l, int c,
        char* palavra, int orientacao,
        int valor) {

    int i,j;
    mapa.tamPalavra = strlen(palavra);


    if (orientacao == 1) {
        for (i = mapa.tamPalavra; i > 0; i--) {//Percorre mapa
            if (mapa.matriz[l][c] == 0) {//Palavra nao acertada na posicao
                mapa.matriz[l][c] = valor;//atribui valor contador
            }
            l--;
        }
    }
    
    if (orientacao == 2) {
        for (i = mapa.tamPalavra; i > 0; i--) {
            if (mapa.matriz[l][c] == 0) {
                mapa.matriz[l][c] = valor;
            }
            l++;
        }
    }
    
    if (orientacao == 3) {
        for (i = mapa.tamPalavra; i > 0; i--) {
            if (mapa.matriz[l][c] == 0) {
                mapa.matriz[l][c] = valor;
            }
            c--;
        }
    }
    
    if (orientacao == 4) {
        for (i = mapa.tamPalavra; i > 0; i--) {
            if (mapa.matriz[l][c] == 0) {
                mapa.matriz[l][c] = valor;
            }
            c++;
        }
    }
    
    if (orientacao == 5) {
        for (i = mapa.tamPalavra; i > 0; i--) {
            if (mapa.matriz[l][c] == 0) {
                mapa.matriz[l][c] = valor;
            }
            l--;
            c--;
        }
    }
    
    if (orientacao == 6) {
        for (i = mapa.tamPalavra; i > 0; i--) {
            if (mapa.matriz[l][c] == 0) {
                mapa.matriz[l][c] = valor;
            }
            l--;
            c++;
        }
    }
    
    if (orientacao == 7) {
        for (i = mapa.tamPalavra; i > 0; i--) {
            if (mapa.matriz[l][c] == 0) {
                mapa.matriz[l][c] = valor;
            }
            l++;
            c--;
        }
    }
    
    if (orientacao == 8) {
        for (i = mapa.tamPalavra; i > 0; i--) {
            if (mapa.matriz[l][c] == 0) {
                mapa.matriz[l][c] = valor;
            }
            l++;
            c++;
        }
    }

    if (orientacao == 0) {
        if (mapa.matriz[l][c] == 0) {
            mapa.matriz[l][c] = valor;
        }
        l--;
    }




    return mapa;

}

tJogo ComecaJogo(tJogo jogo) {
    
    int contJogada = 0;//Usado para ordenar estatisticas
    int contPos = 0;//Usado para ordenar estatisticas e mapa
    int i = 0, j = 0, orientacao = 0;//orientacao da palavra

    while (1) {

        ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);

        ImprimeTabuleiro(jogo.tabuleiro);

        printf("%s por favor entre com as coordenadas para a sua jogada:\n",
        jogo.jogador1.nome);
        
        jogo.jogador1 = ColetaCoordenadasJogador(jogo.jogador1);

        //Se estiver fora,coleta novas coordenadas
        while (EstaFora(jogo.jogador1.jogada.coordenadaLinha,
                jogo.jogador1.jogada.coordenadaColuna, jogo.tabuleiro.tam)) {
            
            ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);
            
            ImprimeTabuleiro(jogo.tabuleiro);
            
            printf("Coordenadas fora do tabuleiro.%s por favor entre com novas coordenadas para a sua jogada:\n",
            jogo.jogador1.nome);
            
            jogo.jogador1 = ColetaCoordenadasJogador(jogo.jogador1);
            
            continue;
        }
        //Se for coordenada repetida,coleta novas coordenadas
        while (EhRepetida(jogo.jogador1.jogada.coordenadaLinha,
            jogo.jogador1.jogada.coordenadaColuna,
            jogo.tabuleiro.tam,
            jogo.tabuleiro.matriz)) {
            
            ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);
            
            ImprimeTabuleiro(jogo.tabuleiro);
            
            printf("Coordenadas ja jogadas.%s por favor entre com novas coordenadas para a sua jogada:\n",
            jogo.jogador1.nome);
            
            jogo.jogador1 = ColetaCoordenadasJogador(jogo.jogador1);
            
            continue;
        }




        jogo.jogador1.jogada = AtualizaQntJogadas(jogo.jogador1.jogada);
        contJogada++;


        jogo.tabuleiro = AtualizaTabuleiro(jogo.jogador1, jogo.jogador2,
                jogo.tabuleiro, jogo.matrizDasPalavras);

        
        
        if (jogo.tabuleiro.sucesso == 1) {//Jogador fez a pontuacao
            
            jogo.jogador1.pontuacao.pontosFeitos = PontuaJogadaFeita(
            jogo.jogador1.pontuacao.pontosFeitos);//pontua jogador
            
            jogo.estatisticas[contPos].pontuacao = 2;
            
            jogo.estatisticas[contPos].jogada = contJogada;

            for (i = 0; jogo.jogador1.qntPalavras > i; i++) {
                
                orientacao = EncontraOrientacao(
                jogo.jogador1.jogada.coordenadaLinha,
                jogo.jogador1.jogada.coordenadaColuna,
                jogo.jogador1.palavra[i],
                jogo.matrizDasPalavras.tam,
                jogo.matrizDasPalavras.matriz);

                if (orientacao != 0) {//Para avaliar se a palavra esta contida
                    strcpy(jogo.estatisticas[contPos].palavra,
                    jogo.jogador1.palavra[i]);
                    break;
                }
            }
            //transforma posicoes ocupadas pela palavra em posicoes do valor contPos+1
            jogo.mapaOrdenado=AtualizaMapaComPalavra(jogo.mapaOrdenado,
            jogo.jogador1.jogada.coordenadaLinha,
            jogo.jogador1.jogada.coordenadaColuna,jogo.jogador1.palavra[i],
            orientacao,contPos+1);
            
            contPos++;
        }
        //        ----------------------------------------------------------------------

        if (jogo.tabuleiro.sucesso == 2) {//jogador recebeu pontuacao
            
            jogo.jogador2.pontuacao.pontosRecebidos =
            PontuaJogadaRecebida(jogo.jogador2.pontuacao.pontosRecebidos);
            
            jogo.estatisticas[contPos].pontuacao = 1;
            
            jogo.estatisticas[contPos].jogada = contJogada;

            for (i = 0; jogo.jogador2.qntPalavras > i; i++) {
            
                orientacao = EncontraOrientacao(
                jogo.jogador1.jogada.coordenadaLinha,
                jogo.jogador1.jogada.coordenadaColuna,
                jogo.jogador2.palavra[i],
                jogo.matrizDasPalavras.tam,
                jogo.matrizDasPalavras.matriz);

                if (orientacao != 0) {
                    strcpy(jogo.estatisticas[contPos].palavra,
                    jogo.jogador2.palavra[i]);
                    break;
                }
            }
            jogo.mapaOrdenado=AtualizaMapaComPalavra(jogo.mapaOrdenado,
            jogo.jogador1.jogada.coordenadaLinha,
            jogo.jogador1.jogada.coordenadaColuna,jogo.jogador2.palavra[i],
            orientacao,contPos+1);
            
            contPos++;
        }

        jogo.jogador1 = AtualizaPontuacaoTotalJogador(jogo.jogador1);
        jogo.jogador2 = AtualizaPontuacaoTotalJogador(jogo.jogador2);

        if (TerminouJogo(jogo)) {
            
            ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);
            
            ImprimeTabuleiro(jogo.tabuleiro);
            
            break;
        }

        ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);

        ImprimeTabuleiro(jogo.tabuleiro);

        printf("%s por favor entre com as coordenadas para a sua jogada:\n",
        jogo.jogador2.nome);
        
        jogo.jogador2 = ColetaCoordenadasJogador(jogo.jogador2);

        while (EstaFora(jogo.jogador2.jogada.coordenadaLinha,
            jogo.jogador2.jogada.coordenadaColuna,
            jogo.tabuleiro.tam)) {
            
            ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);
            
            ImprimeTabuleiro(jogo.tabuleiro);
            
            printf("Coordenadas fora do tabuleiro.%s por favor entre com novas coordenadas para a sua jogada:\n",
            jogo.jogador2.nome);
            
            jogo.jogador2 = ColetaCoordenadasJogador(jogo.jogador2);
        }

        while (EhRepetida(jogo.jogador2.jogada.coordenadaLinha,
            jogo.jogador2.jogada.coordenadaColuna,
            jogo.tabuleiro.tam,
            jogo.tabuleiro.matriz)) {
            
            ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);
            
            ImprimeTabuleiro(jogo.tabuleiro);
            
            printf("Coordenadas ja jogadas.%s por favor entre com novas coordenadas para a sua jogada:\n",
            jogo.jogador2.nome);
            
            jogo.jogador2 = ColetaCoordenadasJogador(jogo.jogador2);
        }
        
        jogo.jogador2.jogada = AtualizaQntJogadas(jogo.jogador2.jogada);
        contJogada++;

        jogo.tabuleiro = AtualizaTabuleiro(jogo.jogador2, jogo.jogador1,
                jogo.tabuleiro, jogo.matrizDasPalavras);

        
        
        if (jogo.tabuleiro.sucesso == 1) {
            
            jogo.jogador2.pontuacao.pontosFeitos = PontuaJogadaFeita(
            jogo.jogador2.pontuacao.pontosFeitos);
            
            jogo.estatisticas[contPos].pontuacao = 2;
            
            jogo.estatisticas[contPos].jogada = contJogada;

            for (i = 0; jogo.jogador2.qntPalavras > i; i++) {
                
                orientacao = EncontraOrientacao(jogo.jogador2.jogada.coordenadaLinha,
                jogo.jogador2.jogada.coordenadaColuna,
                jogo.jogador2.palavra[i],
                jogo.matrizDasPalavras.tam,
                jogo.matrizDasPalavras.matriz);

                if (orientacao != 0) {
                    
                    strcpy(jogo.estatisticas[contPos].palavra,
                    jogo.jogador2.palavra[i]);
                    break;
                }
            }
            
            jogo.mapaOrdenado=AtualizaMapaComPalavra(jogo.mapaOrdenado,
            jogo.jogador2.jogada.coordenadaLinha,
            jogo.jogador2.jogada.coordenadaColuna,jogo.jogador2.palavra[i],
            orientacao,contPos+1);
            
            contPos++;
        }

        if (jogo.tabuleiro.sucesso == 2) {
            jogo.jogador1.pontuacao.pontosRecebidos = 
            PontuaJogadaRecebida(jogo.jogador1.pontuacao.pontosRecebidos);
            
            jogo.estatisticas[contPos].pontuacao = 1;
            
            jogo.estatisticas[contPos].jogada = contJogada;

            for (i = 0; jogo.jogador1.qntPalavras > i; i++) {
                orientacao = EncontraOrientacao(jogo.jogador2.jogada.coordenadaLinha,
                jogo.jogador2.jogada.coordenadaColuna,
                jogo.jogador1.palavra[i],
                jogo.matrizDasPalavras.tam,
                jogo.matrizDasPalavras.matriz);

                if (orientacao != 0) {
                    strcpy(jogo.estatisticas[contPos].palavra,
                    jogo.jogador1.palavra[i]);
                    
                    break;
                }
            }
            jogo.mapaOrdenado=AtualizaMapaComPalavra(jogo.mapaOrdenado,
            jogo.jogador2.jogada.coordenadaLinha,
            jogo.jogador2.jogada.coordenadaColuna,jogo.jogador1.palavra[i],
            orientacao,contPos+1);            

            contPos++;

        }

        jogo.jogador1 = AtualizaPontuacaoTotalJogador(jogo.jogador1);
        jogo.jogador2 = AtualizaPontuacaoTotalJogador(jogo.jogador2);


        if (TerminouJogo(jogo)) {
            ImprimePalavrasRestantesJogo(jogo, jogo.jogador1, jogo.jogador2);
            ImprimeTabuleiro(jogo.tabuleiro);
            break;
        }
    }
    //------------------------------------------------------------------------------
    //PREENCHENDO PALAVRAS VAZIAS
    i = 0;
    j = 0;
    while (jogo.jogador1.qntPalavras > i) {

        if (!FoiEncontrada(jogo.jogador1.palavra[i], jogo.tabuleiro.tam,
        jogo.tabuleiro.matriz)) {

            jogo.estatisticas[contPos].jogada = 0;
            
            strcpy(jogo.estatisticas[contPos].palavra,
            jogo.jogador1.palavra[i]);
            
            jogo.estatisticas[contPos].pontuacao = 0;
            contPos++;
        }
        i++;
    }

    i = 0;
    while (jogo.jogador2.qntPalavras > i) {

        if (!FoiEncontrada(jogo.jogador2.palavra[i], jogo.tabuleiro.tam,
        jogo.tabuleiro.matriz)) {

            jogo.estatisticas[contPos].jogada = 0;

            strcpy(jogo.estatisticas[contPos].palavra,
            jogo.jogador2.palavra[i]);

            jogo.estatisticas[contPos].pontuacao = 0;

            contPos++;
        }
        i++;
    }



    return jogo;
}

void ImprimeVencedor(tJogador jogador1, tJogador jogador2) {
    if (
        jogador1.pontuacao.pontuacaoTotal >
        jogador2.pontuacao.pontuacaoTotal) {
        
        printf("%s Ganhou!!!", jogador1.nome);
    }

    if (jogador1.pontuacao.pontuacaoTotal < jogador2.pontuacao.pontuacaoTotal) {
        printf("%s Ganhou!!!", jogador2.nome);
    } else if (
            jogador1.pontuacao.pontuacaoTotal ==
            jogador2.pontuacao.pontuacaoTotal) {
        
        printf("Empate");
    }
}

void GeraEstatisticas(tJogo jogo, char estatistica[]) {
    int i = 0, j = 0;
    int qntPalavras = jogo.jogador1.qntPalavras + jogo.jogador2.qntPalavras;
    tEstatisticas vet[50];
    int auxJogada=0;
    int auxPontuacao=0;
    char auxPalavra[25];
    

    FILE* arquivoEstatistica;
    arquivoEstatistica = fopen(estatistica, "w");


    fprintf(arquivoEstatistica, "--------------\n");
    
    fprintf(arquivoEstatistica, "--- PONTOS ---\n");
    
    fprintf(arquivoEstatistica, "--------------\n\n");

    fprintf(arquivoEstatistica, "%s\n", jogo.jogador1.nome);
    
    fprintf(arquivoEstatistica, "Feitos: %d\n",
    jogo.jogador1.pontuacao.pontosFeitos);
    
    fprintf(arquivoEstatistica, "Recebidos: %d\n",
    jogo.jogador1.pontuacao.pontosRecebidos);
    
    fprintf(arquivoEstatistica, "Total: %d\n\n",
    jogo.jogador1.pontuacao.pontuacaoTotal);

    fprintf(arquivoEstatistica, "%s\n", jogo.jogador2.nome);
    
    fprintf(arquivoEstatistica, "Feitos: %d\n",
    jogo.jogador2.pontuacao.pontosFeitos);
    
    fprintf(arquivoEstatistica, 
    "Recebidos: %d\n", jogo.jogador2.pontuacao.pontosRecebidos);
    
    fprintf(arquivoEstatistica, "Total: %d\n\n",
    jogo.jogador2.pontuacao.pontuacaoTotal);

    fprintf(arquivoEstatistica, "---------------------------\n");
    
    fprintf(arquivoEstatistica, "--- PALAVRAS POR PONTOS ---\n");
    
    fprintf(arquivoEstatistica, "---------------------------\n\n");

    fprintf(arquivoEstatistica, "|P|     Palavra    | T |\n");

    fprintf(arquivoEstatistica, "|-|----------------|---|\n");


    //ORDEM ALFABETICA

    i = 0;
    j = 0;

    for(i=0;qntPalavras>i;i++){
        for (j = i; j < qntPalavras; j++){
            if(
            strcmp(jogo.estatisticas[i].palavra,
            jogo.estatisticas[j].palavra)>0){//palavra[i] eh maior que palavra[j]
                
                strcpy(auxPalavra,jogo.estatisticas[i].palavra);
                
                auxJogada=jogo.estatisticas[i].jogada;
                
                auxPontuacao=jogo.estatisticas[i].pontuacao;
                
                strcpy(jogo.estatisticas[i].palavra,
                jogo.estatisticas[j].palavra);
                
                jogo.estatisticas[i].jogada=jogo.estatisticas[j].jogada;
                
                jogo.estatisticas[i].pontuacao=jogo.estatisticas[j].pontuacao;
                
                strcpy(jogo.estatisticas[j].palavra,auxPalavra);
                
                jogo.estatisticas[j].jogada=auxJogada;
                
                jogo.estatisticas[j].pontuacao=auxPontuacao;
            }
        }
    }

    //ORDENA POR PONTUACAO//
    j = 0;
    i = 0;
    while (qntPalavras > i) {
        if (jogo.estatisticas[i].pontuacao == 2) {
            
            vet[j].jogada = jogo.estatisticas[i].jogada;
            
            strcpy(vet[j].palavra, jogo.estatisticas[i].palavra);
            
            vet[j].pontuacao = jogo.estatisticas[i].pontuacao;
            
            j++;
        }
        i++;
    }

    i = 0;
    while (qntPalavras > i) {
        if (jogo.estatisticas[i].pontuacao == 1) {
            
            vet[j].jogada = jogo.estatisticas[i].jogada;
            
            strcpy(vet[j].palavra, jogo.estatisticas[i].palavra);
            
            vet[j].pontuacao = jogo.estatisticas[i].pontuacao;
            
            j++;
        }
        i++;
    }

    i = 0;
    while (qntPalavras > i) {
        if (jogo.estatisticas[i].pontuacao == 0) {
           
            vet[j].jogada = jogo.estatisticas[i].jogada;
            
            strcpy(vet[j].palavra, jogo.estatisticas[i].palavra);
            
            vet[j].pontuacao = jogo.estatisticas[i].pontuacao;
            
            j++;
        }
        i++;
    }





    i = 0;
    while (qntPalavras > i) {
        fprintf(arquivoEstatistica, "|%d|%-16s|%.3d|\n",
        vet[i].pontuacao, vet[i].palavra, vet[i].jogada);
        i++;
    }

    fclose(arquivoEstatistica);
}

void GeraMapaOrdenado(tJogo jogo,char mapaOrdenado[]){
    
    int i,j;
    char simb='-';
    
    FILE* arquivoMapa;
    arquivoMapa = fopen(mapaOrdenado, "w"); //arquivo sera criado e escrito
    
    for(i=0;jogo.tabuleiro.tam>i;i++){
        for(j=0;jogo.tabuleiro.tam>j;j++){
            if(jogo.mapaOrdenado.matriz[i][j]==0){
                fprintf(arquivoMapa," %c%c",simb,simb);
                continue;
            }
            fprintf(arquivoMapa," %.2d",jogo.mapaOrdenado.matriz[i][j]);
        }
        fprintf(arquivoMapa,"\n");
    }
    
    
    
    
    fclose(arquivoMapa);
}

tJogo TerminaJogo(tJogo jogo, char estatistica[],char mapaOrdenado[]) {
    ImprimeVencedor(jogo.jogador1, jogo.jogador2);
    GeraEstatisticas(jogo, estatistica);
    GeraMapaOrdenado(jogo,mapaOrdenado);
    return jogo;
}

int main(int argc, char** argv) {
    tJogo jogo;
    char inicializacao[1001],
    estatistica[1001], 
    config[1001],
    mapaOrdenado[1001];


    if (argc <= 1) {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }
    //atribuicao dos devidos enderecos
    sprintf(inicializacao, "%s/saida/Inicializacao.txt", argv[1]);
    sprintf(estatistica, "%s/saida/Estatisticas.txt", argv[1]);
    sprintf(mapaOrdenado, "%s/saida/MapaOrdenado.txt", argv[1]);
    sprintf(config, "%s/config.txt", argv[1]);

    jogo = CriaJogo(jogo, config);
    GeraArquivoDeInicializacao(jogo, inicializacao);
    jogo = ComecaJogo(jogo);
    jogo = TerminaJogo(jogo, estatistica,mapaOrdenado);
    
    return 0;
}
