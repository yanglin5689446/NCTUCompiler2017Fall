#!/bin/bash
testcase="expr1"
./parser Examples/$testcase.p > output 2>&1
diff output Examples/ExAns/r$testcase.p
