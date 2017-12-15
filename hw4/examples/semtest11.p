//&S-
//&T-
//&D-
/**
 * semtest11.p: test for mul div
 */
semtest11;

begin
    var a : 1.23;
    var b : 10;
    var c : integer;
    var d : boolean;
    var e : "1234";
    c := a * b;
    c := a / b;

    c := a * d;
    c := a / d;
    c := d * b;
    c := d / b;
    
    c := a * e;
    c := a / e;
    c := e * b;
    c := e / b;
    
end
end semtest11
