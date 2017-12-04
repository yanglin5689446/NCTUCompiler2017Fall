/**
 * expr1.p: expression
 */
//&T-
expr1;
func1(x, y: integer; z: string): boolean;
begin

end
end func1

func2(a: boolean): string;
begin

end

end func2

func3(); // procedure
begin

end

end func3
func4(b: real); // procedure
begin

end

end fuc4

func5(): integer;
begin

end
     
end func5
begin

        var a, b: integer;
        a := 2;
        b:= 3;

        print 1+2*(3+4);

        if a*3+1 <> b*4 mod 123 then
                print "test";
        end if
        
end
end expr1
