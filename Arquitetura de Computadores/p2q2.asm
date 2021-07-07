.data
numbers:	.word 	1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35
count:		.word 9
res:		.word 	0 

.text
      la $a0, numbers	
      lw $a1, count
      li $t2, 0		
sum:
      beq $t2, $a1, finish	
      addi $a0, $a0, 4		
      addi $t2, $t2, 1		
      lw  $t0, 0($a0)		
      add $t1, $t1, $t0		
      b sum			
finish:
      sw $t1, res			
