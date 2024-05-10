#!/bin/bash

filename="example.txt"

echo "This is a text file." > $filename

if [ -e $filename ]; then
    echo "$filename exists."
    cat $filename
else
    echo "$filename does not exist."
fi

rm $filename
