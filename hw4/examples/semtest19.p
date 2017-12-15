//&S-
//&T-
//&D-
/**
 * semtest5.p: test for program name
 */
semtest15;

begin
    var a : integer;
    var b : real;
    var c,d : boolean;
    while a+b do
    end do

    while c + d do
    end do

    while c and d or not c  do
    end do
    
    if a+b then
    else  
    end if

    if c and d then
    else  
    end if
end
end semtest15

/*
<Error> found in Line 7: program beginning ID inconsist with file name
<Error> found in Line 13: operand of while statement is not boolean type
<Error> found in Line 16: operands of operator '+' are not both integer or both real
<Error> found in Line 16: operand of while statement is not boolean type
<Error> found in Line 19: adjacent operator 'or' and ''
<Error> found in Line 19: operand of while statement is not boolean type
<Error> found in Line 22: operand of if statement is not boolean type
<Error> found in Line 30: program end ID inconsist with file name

*/
