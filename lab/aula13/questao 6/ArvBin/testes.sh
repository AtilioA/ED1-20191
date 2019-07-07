#! /bin/bash
# USO: ./teste.sh iterações executável nBuscas arquivoDeEntrada

count=0
tInsert=0
tBusca=0
tSomaIns=0
tSomaBusca=0

while [[ count -lt $1  ]]; do
    result=$(./$2 $3 < $4)
    tInsert=$(echo $result | cut -d " " -f1)
    tBusca=$(echo $result | cut -d " " -f2)
    echo "Tempos da $(expr $count + 1)ª iteração: Ins = $tInsert Busca = $tBusca"
    tSomaIns=$(bc -l <<< "$tSomaIns + $tInsert")
    tSomaBusca=$(bc -l <<< "$tSomaBusca + $tBusca")
    count=$(expr $count + 1)
done

mediaIns=$(bc -l <<< "$tSomaIns / $1")
mediaBusca=$(bc -l <<< "$tSomaBusca / $1")

echo "Média Inserção: $mediaIns segundos. Média Busca: $mediaBusca segundos."
