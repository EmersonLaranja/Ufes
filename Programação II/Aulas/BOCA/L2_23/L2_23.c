#include <stdio.h>
#include <stdlib.h>
int main() {
    int i=0,parentesesInicial=0,parentesesFinal=0;
    char texto='\0';
    while(texto!='.'){
        scanf("%c",&texto);
        if(texto=='('){
            while(texto!=')'){
                if(i==0){printf("RESP:");i++;}
                if(texto=='(' && parentesesInicial==0){
                    scanf("%c",&texto);
                    parentesesInicial++;
                    continue;
                }
                if(texto=='(' && parentesesInicial!=0){
                    printf("%c",texto);
                    scanf("%c",&texto);
                    continue;
                }
                printf("%c",texto);
                scanf("%c",&texto);
                if(texto==')' && parentesesInicial!=0){
                    printf("%c",texto);
                    parentesesInicial--;
                    scanf("%c",&texto);
                    continue;                                        
                }
                if(texto==')' && parentesesInicial==0){
                    scanf("%c",&texto);
                    continue;
                }
            }   
        }
    }
    
    return 0;
}