//&S-
//&T-
//&D-
/**
 * semtest5.p: test for program name
 */
semtest15;

begin
    var a : array 1 to 5 of integer;
    a := a[1.23];
    a := a[a];
end
end semtest15

/*
<Error> found in Line 7: program beginning ID inconsist with file name
<Error> found in Line 11: array index is not integer
<Error> found in Line 11: type mismatch, LHS= integer [5], RHS= integer
<Error> found in Line 12: array index is not integer
<Error> found in Line 12: type mismatch, LHS= integer [5], RHS= integer
<Error> found in Line 14: program end ID inconsist with file name

*/
