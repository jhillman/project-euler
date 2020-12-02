#!/bin/bash

for directory in $( find ./ -type d -name "problem*" | sort )
do
    echo "Editing $directory..."
    pushd . > /dev/null
    cd $directory

    subl solution.c
    
    popd > /dev/null
done
