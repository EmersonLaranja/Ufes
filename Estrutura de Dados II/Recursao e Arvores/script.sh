  gcc *.c -o main;

 count=10
    for i in $(seq $count); do
    printf "Case $i: "
        ./main
    done