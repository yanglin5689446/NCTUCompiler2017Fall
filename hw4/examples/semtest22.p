//&S-
//&T-
//&D-
/**
 * semtest21.p: test for program name
 */
semtest21;

begin
    var c,d : array  1 to 10 of array 1 to 10 of array 1 to 10 of integer;
    c := d;
    c[1] := d;
    c := d[1];
    c[1][2] := d[1];
    c[1][2][3] := d[1];
    c[1][2][3] := d[1][2];
    c[1][2][3] := d[1][2][3];
	c[1][2][3][4] := d[1][2][3][4];
	c[1][2][3][4] := d[1][2][3][4] * d[1][2][3][4];
end
end semtest21

/*
<Error> found in Line 7: program beginning ID inconsist with file name
<Error> found in Line 12: type mismatch, LHS= integer [10][10], RHS= integer [10][10][10]
<Error> found in Line 13: type mismatch, LHS= integer [10][10][10], RHS= integer [10][10]
<Error> found in Line 14: type mismatch, LHS= integer [10], RHS= integer [10][10]
<Error> found in Line 15: type mismatch, LHS= integer, RHS= integer [10][10]
<Error> found in Line 16: type mismatch, LHS= integer, RHS= integer [10]
<Error> found in Line 18: 'd' is 3 dimension(s), but reference in 4 dimension(s)
<Error> found in Line 18: 'c' is 3 dimension(s), but reference in 4 dimension(s)
<Error> found in Line 19: 'd' is 3 dimension(s), but reference in 4 dimension(s)
<Error> found in Line 19: 'd' is 3 dimension(s), but reference in 4 dimension(s)
<Error> found in Line 19: 'c' is 3 dimension(s), but reference in 4 dimension(s)
<Error> found in Line 21: program end ID inconsist with file name
*/
