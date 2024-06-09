program ajudeAparecido(input, output);
var
    amount, sum, guess, buf: LongInt;

begin
    readln(amount);
    
    sum := 0;
    while amount > 0 do
        begin
            amount -= 1;
            
            read(buf);
            sum += buf;
        end;
    
    readln(guess);

    if guess = sum then
        writeln('Acertou')
    else
        writeln('Errou');
end.
