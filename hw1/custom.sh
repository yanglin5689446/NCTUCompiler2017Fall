#!/bin/bash
lex hw1.l && gcc lex.yy.c -o scanner -lfl && ./scanner test_data 
