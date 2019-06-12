count=0;
while [[ count -lt 100 ]];
    do ./DesempenhoLista 150 < input/input_rand_900000.txt > teste2.txt;
    count=$(expr $count + 1);
