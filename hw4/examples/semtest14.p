//&S+
//&T-
//&D-
/**
 * semtest5.p: test for mod
 */
test;

begin
    var a : 1.23;
    var b : 10;
    var c : integer;
    var str : "aweqwewq";
    var str1 ,str2: string;
    var bool : boolean;
    c := a + b;
    c := a + str;
    c := str + b;
    c := str + str; //string concate
    c := bool + b;
    c := a + bool;
    c := bool + bool;

    c := a - b;
    c := a - str;
    c := str - b;
    c := str - str;
    c := str - str;
    c := bool - b;
    c := a - bool;
    c := bool - bool;


end
end ttest
