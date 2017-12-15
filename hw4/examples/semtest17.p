//&S-
//&T-
//&D-
/**
 * semtest5.p: test for program name
 */
semtest15;

fun();
begin
end
end fun

fun2():integer;
begin
end
end fun2
begin
    var a : array 1 to 5 of integer;
    print a;
    print fun;
    print fun2;
    read a;
    read fun;
    read fun2;
end
end semtest15

/*
<Error> found in Line 7: program beginning ID inconsist with file name
<Error> found in Line 20: operand of print statement is array type
<Error> found in Line 21: 'fun' is function
<Error> found in Line 22: 'fun2' is function
<Error> found in Line 23: operand of read statement is array type
<Error> found in Line 24: 'fun' is function
<Error> found in Line 25: 'fun2' is function
<Error> found in Line 27: program end ID inconsist with file name
*/
