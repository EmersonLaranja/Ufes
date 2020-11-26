# comando para compilar o sistema
compile: main.c comandos.c contribuicao.c editor.c listaContribuicoes.c listaEditores.c listaLinks.c listaPaginas.c
	gcc -ggdb -o wiked.out *.c

# comando para limpar executaveis
clean:
	rm -f *.o a.out wiked.out

# comando para executar o programa
run:
	./wiked.out entrada.txt

# comando para compilar,limpar e executar
all:
	make clean compile run