#!/bin/bash

echo "" > output.txt

for i in {1..500}; do
    ARG=$(seq 1 500 | sort -R | tr '\n' ' ')
    # ./push_swap "$ARG" | wc -l >> output.txt
    ./push_swap $ARG | ./checker_linux $ARG >> output.txt
done

# sort -r output.txt | head -n 10