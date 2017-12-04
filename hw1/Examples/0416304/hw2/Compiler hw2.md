Compiler hw2
===

## yacc parser

### format 
program
```
identifier;
<zero or more variable and constant declaration>
<zero or more function declaration>
<one compound statement>
end identifier
```

statement
```
variable_reference := expression;
print variable_reference; 
print expression;
read variable_reference;
```
variable_reference
```
identifier
identifier [integer_expression] [integer_expression]
```

expression
```
```

variable declaration
```
var identifier_list: type;
var identifier_list: array integer_constant to integer_constant of type;
```

function declaration
```
identifier (<zero or more formal arguments>): type;
<one compound statement>
end identifier
```

constants
```
var identifier_list: constants;
```

compound
```
begin
<zero or more variable and constant declaration>
<zero or more statements>
end
```

condition
```
if boolean_expr then
<zero or more statements>
else
<zero or more statements>
end if
```

while
```
while boolean_expr do
<zero or more statements>
end do
```

for
```
for identifier := integer_constant to integer_constant do
<zero or more statements>
end do
```

function invocation
```
identifier (<expressions separated by zero or more comma>)
```