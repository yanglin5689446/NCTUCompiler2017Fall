//&S-
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
    var e : "1234";
    c := a > b;
    c := a > b;
    c := a > d;
    c := a > e;
    c := d > b;
    c := e > b;

    c := a < b;
    c := a < b;
    c := a < d;
    c := a < e;
    c := d < b;
    c := e < b;

    c := a >= b;
    c := a >= b;
    c := a >= d;
    c := a >= e;
    c := d >= b;
    c := e >= b;

    c := a <= b;
    c := a <= b;
    c := a <= d;
    c := a <= e;
    c := d <= b;
    c := e <= b;

    c := a = b;
    c := a = b;
    c := a = d;
    c := a = e;
    c := d = b;
    c := e = b;

    c := a <> b;
    c := a <> b;
    c := a <> d;
    c := a <> e;
    c := d <> b;
    c := e <> b;

end
end semtest12
