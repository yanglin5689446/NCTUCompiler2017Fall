Compiler assignment 1
==

## 用 lex 做 P language tokenizer

### SPEC achivement:
- Delimiters 
    - [x] ","
    - [x] ":"
    - [x] "()"
    - [x] "[]"
- Operators
    - [x] \+\-\*\\
    - [x] mod
    - [x] ":="
    - [x] < <= <> >= >
    - [x] and
    - [x] or
    - [x] not 
- Keywords
    - [x] array 
    - [x] begin 
    - [x] boolean 
    - [x] def 
    - [x] do 
    - [x] else 
    - [x] end 
    - [x] false 
    - [x] for 
    - [x] integer 
    - [x] if 
    - [x] of 
    - [x] print 
    - [x] read 
    - [x] real 
    - [x] string
    - [x] then 
    - [x] to 
    - [x] true 
    - [x] return 
    - [x] var 
    - [x] while
- [x] Identifier
- Constants
    - [x] Integer
    - [x] Floating-Point
    - [x] Scientific Notation
    - String 
        - [x] '\n' in string
        - [x] double double-quote in string
- Discarded Tokens
    - [x] white space
    - comment
        - [x] inline
        - [x] multiplie line
        - pseudocomments
            - [x] S[+-]
            - [x] T[+-]

### 環境
- linux1

### 使用方法
- make all
    - 產生 scanner 可執行檔，參數為input檔名
- make clean
    - 清除 scanner 
