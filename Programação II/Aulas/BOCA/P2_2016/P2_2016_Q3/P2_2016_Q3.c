#include <stdio.h>
#include <stdlib.h>

int EhProduto(char prd) {
    if (prd >= 'A' && prd <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int AcabaramOsProdutos(char prd) {
    if (prd == '0') {
        return 1;
    } else {
        return 0;
    }
}

int QtdDoProdutoMaisComprado() {
    char produtoAnterior='\0',produto = '\0';
    int j=0,armazenaContadorAntigo=0,aindaTemProduto = 0, verificacao = 0,produtoMaisComprado = 0, contadorDoProdutoMaisComprado = 1;
    scanf("%*c");
    scanf("%c",&produtoAnterior);
    produto=produtoAnterior;
    while (!(aindaTemProduto = AcabaramOsProdutos(produto))) {
        scanf("%c", &produto);
        verificacao = EhProduto(produto);
        if (verificacao != 0) {
            if (produtoAnterior == produto) {
                contadorDoProdutoMaisComprado++;
            } else {
                produtoAnterior=produto;
                if(j==0){armazenaContadorAntigo=contadorDoProdutoMaisComprado;j++;}
                if(contadorDoProdutoMaisComprado>armazenaContadorAntigo){
                    armazenaContadorAntigo=contadorDoProdutoMaisComprado;}
                contadorDoProdutoMaisComprado = 1;
                continue;
            }
        } else if (verificacao == 0) {
            continue;
        }
    }
    return armazenaContadorAntigo;
}

int main() {
    int maiorQuantidade=0,clienteGuloso=0,QntDoProdutoMaisCompradoDesteCliente=0,codigo = 0,contCliente=0,primeiroLoop=0;
    char produtoAnterior = '\0';
    scanf("%d",&codigo);
    while(codigo!=-1){
        QntDoProdutoMaisCompradoDesteCliente=QtdDoProdutoMaisComprado();
        if(primeiroLoop==0){
            clienteGuloso=codigo;
            maiorQuantidade=QntDoProdutoMaisCompradoDesteCliente;
            primeiroLoop++;
        }
        if(QntDoProdutoMaisCompradoDesteCliente>maiorQuantidade){
            clienteGuloso=codigo;
            maiorQuantidade=QntDoProdutoMaisCompradoDesteCliente;
        }
        scanf("%d",&codigo);
    }
    printf("CLIENT:%d QTD:%d",clienteGuloso,maiorQuantidade);
    
    
    
    
    
    return 0;
}