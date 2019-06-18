tester(){
    # $1 = numero de repetições do programa
    # $2 = nome do executavel
    # $3 = numero de buscas
    # $4 = arquivo input

    local count=0 #contador pra repetir execução
    local tInsert=0 #tempo de inserção
    local tProc=0 #tempo de procura
    local tSomaIns=0 #soma das inserções apos repetição
    local tSomaProc=0 #soma das procuras

    while [[ count -lt $1  ]]; do
        result=$(./$2 $3 < $4) #guarda a saida do programa
        tInsert=$(echo $result | cut -d " " -f1) #pega primeira parte da saida
        tProc=$(echo $result | cut -d " " -f2) #pega segunda parte da saida
        echo "Tempos da $(expr $count + 1)ª iteração: Ins=$tInsert Proc=$tProc"
        tSomaIns=$(echo "$tSomaIns + $tInsert" | bc -l) #soma das inserções com ponto flutuante
        tSomaProc=$(echo "$tSomaProc + $tProc" | bc -l) #soma das procuras com ponto flutuante
        count=$(expr $count + 1)
    done
    if [[ ! -e $2.csv ]]; then
        echo -e "N,BUSCA,Tempo de inserção (média com $1 execuções),Tempo de procura (média com $1 execuções),Tipo" >> "$2.csv" #começo do csv com o nome do executavel
    fi
    mediaIns=$(echo "$tSomaIns / $1" | bc -l | sed 's/^\./0./') #coloca 0 antes do . se n tiver parte inteira
    mediaProc=$(echo "$tSomaProc / $1" | bc -l | sed 's/^\./0./')
    echo -e "$(echo "$4" | tr -dc '0123456789'),$3,\"$(echo $mediaIns | tr . ,)\",\"$(echo $mediaProc | tr . ,)\",$(strcheck "$4" "rand" "seq" )" >> "$2.csv" #coloca no csv com o nome do executavel
    echo "Media Inserção : $mediaIns segundos, Media Procura : $mediaProc segundos"
}

tester_every(){
    # $1 = lista com os arquivos
    # Ex1. "../input_seq_1000.txt ../input_seq_100.txt"
    # Ex2. "../input_seq_*"
    # Ex3. "../input_*"

    # $2 = lista com as quantidades de busca
    # Ex. "10 100 1000 10000"

    # $3 = lista com os executaveis
    # Ex. "DesempenhoLista DesempenhoArvore DesempenhoAVL"
    
    # $4 = numero de repetições para cada programa


    for exe in $3; do
        for proc in $2; do
            for file in $1; do
                echo -e "\nEXECUTAVEL = $exe; N BUSCAS = $proc; ARQUIVO = $file"
                tester $4 $exe $proc $file
            done
        done
    done
}

strcheck(){
    if [[ $1 == *"$2"* ]]; then
        echo "$2"
    else
        echo "$3"
    fi
}
