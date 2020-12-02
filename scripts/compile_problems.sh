#!/bin/bash

for directory in $( find ./ -type d -name "problem*" | sort )
do
    echo "Building $directory..."
    pushd . > /dev/null
    cd $directory

    gcc -std=c89 solution.c -lm
    popd > /dev/null
done
