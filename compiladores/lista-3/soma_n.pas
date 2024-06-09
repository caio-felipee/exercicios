program somaN(input, output);
var
    n, buf, ans: LongInt;

begin
    readln(n);
    ans := 0;

    while n > 0 do
    begin
        n -= 1;
        
        readln(buf);

        ans += buf;
    end;

    writeln(ans);
end.
