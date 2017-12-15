//&S-
//&T-
//&D-
/**
 * semtest5.p: test for program name
 */
semtest21;

begin
    var a,b : integer;
    var a,b : integer;
    var c,d : array  1 to 10 of array 1 to 10 of array 1 to 10 of integer;
    var e,f : boolean;
    var g : 1.414;
    var h : "dasdsdasasd";
    e := e or a; 
    e := not e;
    e := e and f or (a > b);
    c := d;
    c[1] := d;
    c := d[1];
    c[1][2] := d[1];
    c[1][2][3] := d[1];
    c[1][2][3] := d[1][2];
    c[1][2][3] := d[1][2][3];
    a := a*g;
end
end semtest21

/*
<Error> found in Line 7: program beginning ID inconsist with file name
<Error> found in Line 11: symbol 'a' is redeclared
<Error> found in Line 11: symbol 'b' is redeclared
<Error> found in Line 16: one of the operands of operator 'or' is not boolean
<Error> found in Line 20: type mismatch, LHS= integer [10][10], RHS= integer [10][10][10]
<Error> found in Line 21: type mismatch, LHS= integer [10][10][10], RHS= integer [10][10]
<Error> found in Line 22: type mismatch, LHS= integer [10], RHS= integer [10][10]
<Error> found in Line 23: type mismatch, LHS= integer, RHS= integer [10][10]
<Error> found in Line 24: type mismatch, LHS= integer, RHS= integer [10]
<Error> found in Line 26: type mismatch, LHS= integer, RHS= real
<Error> found in Line 28: program end ID inconsist with file name
*/
