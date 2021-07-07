.data
var1: .word 'c' #variavel para armazenar uma word 
var2: .word 'o' #variavel para armazenar uma word
var3: .word 'm' #variavel para armazenar uma word
var4: .word 'p' #variavel para armazenar uma word

primeiro: .byte 'e'
ultimo: .byte 's'

.text
lw $t0, var1 #carregando o valor de var1 para o registrador t0
lw $t1, var4 #carregando o valor de var4 para o registrador t1
sw $t0, var4 #atribui o valor do registrado t0 à var4
sw $t1,var1 #atribui o valor do registrado t1 à var1


lw $t2, var2 #carregando o valor de var2 para o registrador t2
lw $t3, var3 #carregando o valor de var3 para o registrador t3
sw $t2, var2 #atribui o valor do registrado t2 à var2
sw $t4,var3 #atribui o valor do registrado t4 à var3