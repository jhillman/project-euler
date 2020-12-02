#!/bin/bash
 
if [ "$1" != "" ]; then
    range=$1
     
    if [[ $range == [0-9]*..[0-9]* ]]; then
        startLength=`expr "$range" : '[0-9]*'`
         
        start=${range:0:$startLength}
         
        let endLength="${#range}-$startLength-2"
        let endLength="-$endLength"
         
        end=${range:$endLength}
    else
        start=$range
        end=$range
    fi
else
    start=1
 
    lastDir=`ls -d problem* | tail -n 1`
 
    let endLength="${#lastDir}-7"
    let endLength="-$endLength"
 
    end=${lastDir:$endLength}
fi
 
allCorrect="true"
 
if [ $start -le $end ]; then
    echo "Name         Answer            Correct"
    echo "----         ------            -------"
 
    for (( number=$start; number <= $end; number++ )); do       
         
        directory="$(printf "problem%03d" $number)"
 
        if [ -d $directory ]; then
            pushd . > /dev/null
            cd $directory
             
            answer=`./a.out`
             
            final=`awk '/Problem [0-9]* = [-.0-9]*/ { print $5 }' solution.c`
 
            if [ "$final" == "$answer" ]; then
                correct="true"
            else
                if [ "$final" == "" ]; then
                    correct="N/A"
                else
                    correct="false"
                    allCorrect="false"
                fi
            fi
             
            printf "Problem %-3d  %-17s %-4s\n" $number $answer $correct
 
            popd > /dev/null
        fi
    done
 
    if [ $start -lt $end ]; then
        printf "All          ---               %s\n" $allCorrect
    fi
fi