compile: main.c comandos.c contribuicao.c editor.c listaContribuicoes.c listaEditores.c listaLinks.c listaPaginas.c
	gcc -ggdb -Wno-unused-const-variable -o wiked.out *.c

clean:
	rm -f *.o a.out wiked.out ufes.txt artes.txt fisica.txt log.txt

run:
	valgrind --leak-check=full -s ./wiked.out entrada.txt