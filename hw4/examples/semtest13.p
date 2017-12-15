//&S
//&T-
//&D-
/**
 * semtest12.p: test for related
 */
semtest12;

begin
    var a : 1.23;
    var b : 10;
    var c : integer;
    var d : boolean;
    var f : boolean;
    var e : "1234";
    c := a and b;
    c := a and d;
    c := d and f;

    c := a or b;
    c := a or d;
    c := d or f;
    
    c := not b;
    c := not d;
    c := not f;
end
end semtest12
