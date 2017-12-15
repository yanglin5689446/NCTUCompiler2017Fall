//&S-
//&T-
//&D-
/**
 * semtest8.p: test for array boundary
 */
semtest8;

begin
    var a: array 1 to 3 of array 1 to 3 of integer;
    var b: array 1 to 3 of array 1 to 3 of integer;
    var c: array 3 to 1 of array 1 to 3 of integer;
    var c: array 0 to 1 of array 1 to 3 of integer;

end
end semtest8
