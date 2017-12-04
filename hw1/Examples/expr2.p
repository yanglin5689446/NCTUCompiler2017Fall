/**
 * expr1.p: expression
 */
//&T-
expr1;


begin

        var a, b: integer;
        a := 2;
        b:= 3;

        print 1+2*(3+4);
        print -1+2*(3+4);

        if 31+1 <> b*4 mod 123 then
                print "test";
        end if
        if not (a*31+1 <> b*4 mod 123) then
                print "test";
        end if
        
        if a > b > c then //error
        end if

        if not a + b then
        end if
        
        if a or b and c then

        end if

        // a:=b:=c;       //error

 
        if a+1 then
            a:=1;
            if a > 1 then
            else
            end if
        else
            a:=2;
        end if
end
end expr1
