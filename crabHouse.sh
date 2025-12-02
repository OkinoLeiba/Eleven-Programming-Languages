#!/usr/bin/env bash

echo "Hello World!"

function world {
    echo "Hello $1!"
}

declare -a combinArray=(2 3 3 5 3)
combinArray=(2 3 3 5 3)
combinResult=1

combination(){
    for i in "${combinArray[@]}"; do
        combinResult=$(($combinResult * $i))
    done
    echo $combinResult
}

robotTrack(){
    n=-10
    w=20
    s=10
    e=0

    muls=$(($s*-1))
    mule=$(($e*-1))
    l=$(($n+$muls))
    r=$(($w+$mule))
    

    robotResult=($l $r)

    echo $robotResult


}

world World
combination
robotTrack

