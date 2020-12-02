#!/bin/bash

for directory in $( find ./ -type d -name "problem*" | sort )
do
    echo "Formatting $directory..."
    pushd . > /dev/null
    cd $directory

    ../astyle solution.c --style=java --indent=spaces=4 --break-blocks --unpad-paren --pad-header
    rm solution.c.orig
    
    popd > /dev/null
done
