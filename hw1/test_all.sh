#!/bin/bash
testcase=("decl" "err2" "err" "statement" "test" "expr1")
for test in ${testcase[@]}; do
    printf $test": "
    ./parser Examples/$test.p > output 2>&1
    if [[ -z $(diff output Examples/ExAns/r$test.p) ]] ; then
        printf "correct!\n"
    else
        printf "incorrect!\n"
    fi
done
