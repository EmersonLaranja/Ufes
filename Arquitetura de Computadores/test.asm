.data
v: .word 1

.text
li $t1,1 #valor inicial do i
li $t2, 10 #limite 
li $t3,0 #elemento que será incrementado
la $t4,v #la carrega o endereço na memoria deste label

loop:
	sw $t1,0($t4) #atribuição para a memoria de t1 o conteudo que temos na primeira posição do t4
	addi $t4,$t4,4  #incrementando o registrador t4
	addi $t3,$t3,1 #incrementando o loop
	addi $t1,$t1,1 #incrementando t1
	bne $t2,$t3,loop #enquanto é diferente, continua o loop
