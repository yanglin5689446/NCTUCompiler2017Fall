//&S+
//&T-
//&D+
/**
 * semtest9.p: test for no declare name
 */
semtest9;

func1(a,b:integer);
begin
end
end func1

func2();
begin
end
end func2

begin
    a := b + c;
    func1 := a;
end
end semtest9
