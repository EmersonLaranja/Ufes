
gcc select_sort.c main.c -o main;
printf "SELECT SORT NEARLY SORTED 1k:";
	./main in/nearly_sorted/1Knearly_sorted.txt 1000;
  printf "SELECT SORT NEARLY SORTED 10k:";
	./main in/nearly_sorted/10Knearly_sorted.txt 10000;
  printf "SELECT SORT NEARLY SORTED 100k:";
	./main in/nearly_sorted/100Knearly_sorted.txt 100000;
printf "\n";

printf "SELECT SORT REVERSE SORTED 1k:";
	./main in/reverse_sorted/1Kreverse_sorted.txt 1000;
  printf "SELECT SORT REVERSE SORTED 10k:";
	./main in/reverse_sorted/10Kreverse_sorted.txt 10000;
  printf "SELECT SORT REVERSE SORTED 100k:";
	./main in/reverse_sorted/100Kreverse_sorted.txt 100000;
printf "\n";

printf "SELECT SORT SORTED 1k:";
	./main in/sorted/1Ksorted.txt 1000;
  printf "SELECT SORT SORTED 10k:";
	./main in/sorted/10Ksorted.txt 10000;
  printf "SELECT SORT SORTED 100k:";
	./main in/sorted/100Ksorted.txt 100000;
printf "\n";

printf "SELECT SORT UNIF RAND 1k:";
	./main in/unif_rand/1Kunif_rand.txt 1000;
  printf "SELECT SORT UNIF RAND 10k:";
	./main in/unif_rand/10Kunif_rand.txt 10000;
  printf "SELECT SORT UNIF RAND 100k:";
	./main in/unif_rand/100Kunif_rand.txt 100000;
printf "\n";

#------------------------------------------------------------------

gcc insert_sort.c main.c -o main;
printf "INSERT SORT NEARLY SORTED 1k:";
	./main in/nearly_sorted/1Knearly_sorted.txt 1000;
  printf "INSERT SORT NEARLY SORTED 10k:";
	./main in/nearly_sorted/10Knearly_sorted.txt 10000;
  printf "INSERT SORT NEARLY SORTED 100k:";
	./main in/nearly_sorted/100Knearly_sorted.txt 100000;
printf "\n";

printf "INSERT SORT REVERSE SORTED 1k:";
	./main in/reverse_sorted/1Kreverse_sorted.txt 1000;
  printf "INSERT SORT REVERSE SORTED 10k:";
	./main in/reverse_sorted/10Kreverse_sorted.txt 10000;
  printf "INSERT SORT REVERSE SORTED 100k:";
	./main in/reverse_sorted/100Kreverse_sorted.txt 100000;
printf "\n";

printf "INSERT SORT SORTED 1k:";
	./main in/sorted/1Ksorted.txt 1000;
  printf "INSERT SORT SORTED 10k:";
	./main in/sorted/10Ksorted.txt 10000;
  printf "INSERT SORT SORTED 100k:";
	./main in/sorted/100Ksorted.txt 100000;
printf "\n";

printf "INSERT SORT UNIF RAND 1k:";
	./main in/unif_rand/1Kunif_rand.txt 1000;
  printf "INSERT SORT UNIF RAND 10k:";
	./main in/unif_rand/10Kunif_rand.txt 10000;
  printf "INSERT SORT UNIF RAND 100k:";
	./main in/unif_rand/100Kunif_rand.txt 100000;
printf "\n";
#------------------------------------------------------------------
gcc bubble_sort.c main.c -o main;
printf "BUBBLE SORT NEARLY SORTED 1k:";
	./main in/nearly_sorted/1Knearly_sorted.txt 1000;
  printf "BUBBLE SORT NEARLY SORTED 10k:";
	./main in/nearly_sorted/10Knearly_sorted.txt 10000;
  printf "BUBBLE SORT NEARLY SORTED 100k:";
	./main in/nearly_sorted/100Knearly_sorted.txt 100000;
printf "\n";

printf "BUBBLE SORT REVERSE SORTED 1k:";
	./main in/reverse_sorted/1Kreverse_sorted.txt 1000;
  printf "BUBBLE SORT REVERSE SORTED 10k:";
	./main in/reverse_sorted/10Kreverse_sorted.txt 10000;
  printf "BUBBLE SORT REVERSE SORTED 100k:";
	./main in/reverse_sorted/100Kreverse_sorted.txt 100000;
printf "\n";

printf "BUBBLE SORT SORTED 1k:";
	./main in/sorted/1Ksorted.txt 1000;
  printf "BUBBLE SORT SORTED 10k:";
	./main in/sorted/10Ksorted.txt 10000;
  printf "BUBBLE SORT SORTED 100k:";
	./main in/sorted/100Ksorted.txt 100000;
printf "\n";

printf "BUBBLE SORT UNIF RAND 1k:";
	./main in/unif_rand/1Kunif_rand.txt 1000;
  printf "BUBBLE SORT UNIF RAND 10k:";
	./main in/unif_rand/10Kunif_rand.txt 10000;
  printf "BUBBLE SORT UNIF RAND 100k:";
	./main in/unif_rand/100Kunif_rand.txt 100000;
printf "\n";
#------------------------------------------------------------------
gcc shaker_sort.c main.c -o main;
printf "SHAKER SORT NEARLY SORTED 1k:";
	./main in/nearly_sorted/1Knearly_sorted.txt 1000;
  printf "SHAKER SORT NEARLY SORTED 10k:";
	./main in/nearly_sorted/10Knearly_sorted.txt 10000;
  printf "SHAKER SORT NEARLY SORTED 100k:";
	./main in/nearly_sorted/100Knearly_sorted.txt 100000;
printf "\n";

printf "SHAKER SORT REVERSE SORTED 1k:";
	./main in/reverse_sorted/1Kreverse_sorted.txt 1000;
  printf "SHAKER SORT REVERSE SORTED 10k:";
	./main in/reverse_sorted/10Kreverse_sorted.txt 10000;
  printf "SHAKER SORT REVERSE SORTED 100k:";
	./main in/reverse_sorted/100Kreverse_sorted.txt 100000;
printf "\n";

printf "SHAKER SORT SORTED 1k:";
	./main in/sorted/1Ksorted.txt 1000;
  printf "SHAKER SORT SORTED 10k:";
	./main in/sorted/10Ksorted.txt 10000;
  printf "SHAKER SORT SORTED 100k:";
	./main in/sorted/100Ksorted.txt 100000;
printf "\n";

printf "SHAKER SORT UNIF RAND 1k:";
	./main in/unif_rand/1Kunif_rand.txt 1000;
  printf "SHAKER SORT UNIF RAND 10k:";
	./main in/unif_rand/10Kunif_rand.txt 10000;
  printf "SHAKER SORT UNIF RAND 100k:";
	./main in/unif_rand/100Kunif_rand.txt 100000;
printf "\n";