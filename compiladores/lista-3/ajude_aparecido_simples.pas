program ajudeAparecido(input, output);
var a, b, c, guess: LongInt;

begin
    read(a, b, c, guess);

    if (a + b + c = guess) then
        writeln('Acertou')
    else
        writeln('Errou');
end.
