#! /bin/bash
count=0
tInsert=0
tProc=0
tSomaIns=0
tSomaProc=0
while [[ count -lt $1  ]]; do
    result=$(./$2 $3 < $4)
    tInsert=$(echo $result | cut -d " " -f1)
    tProc=$(echo $result | cut -d " " -f2)
    echo "Tempos da $(expr $count + 1)ª iteração: Ins=$tInsert Proc=$tProc"
    tSomaIns=$(bc -l <<< "$tSomaIns + $tInsert")
    tSomaProc=$(bc -l <<< "$tSomaProc + $tProc")
    count=$(expr $count + 1)
done

mediaIns=$(bc -l <<< "$tSomaIns / $1")
mediaProc=$(bc -l <<< "$tSomaProc / $1")

echo "Media Inserção : $mediaIns segundos, Media Procura : $mediaProc segundos"