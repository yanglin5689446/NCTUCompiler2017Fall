//&S-
//&T-
//&D-
/**
 * semtest5.p: test for program name
 */
semtest15;

begin
    for i := 3 to 5 do // statements end do is a legal for statement, but
    
    end do
    for i := 5 to 3 do // statements end do is illegal.
    
    end do
    for i := -1 to -1 do // statements end do is illegal.
    
    end do

end
end semtest15

/*
<Error> found in Line 7: program beginning ID inconsist with file name
<Error> found in Line 13: loop parameter's lower bound >= uppper bound
<Error> found in Line 16: lower or upper bound of loop parameter < 0
<Error> found in Line 21: program end ID inconsist with file name
*/
