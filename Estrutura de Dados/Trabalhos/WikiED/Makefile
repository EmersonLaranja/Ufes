compile: main.c contribuicao.c editor.c listaContribuicoes.c listaEditores.c listaLinks.c listaPaginas.c
	gcc -ggdb -Wno-unused-const-variable -o wiked.out *.c

clean:
	rm -f *.o a.out core wiked.out

run:
	valgrind --leak-check=full -s ./wiked.out teste.txt