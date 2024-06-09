program conversao(input, output);
var 
    current, answer: Double; 
    fromValue, toValue: char;

function celsius(value: Double; current: char): Double;
var
    result: Double;

begin
    result := value;

    if (current = 'F') then
        result := (value - 32) * (5 / 9)
    else if(current = 'K') then
        result := value - 273.15;

    celsius := result;
end;

function fahrenheit(value: Double; current: char): Double;
var
    result: Double;

begin
    result := value;

    if (current = 'C') then
        result := (value * (9 / 5)) + 32
    else if (current = 'K') then
        result := (1.8 * (value - 273.15)) + 32;

    fahrenheit := result;
end;

function kelvin(value: Double; current: char): Double;
var
    result: Double;

begin
    result := value;

    if (current = 'C') then
        result := value + 273.15
    else if (current = 'F') then
        result := ((value - 32) * (5 / 9)) + 273.15;

    kelvin := result;
end;

begin
    readln(fromValue);
    readln(toValue);
    readln(current);

    if (toValue = 'C') then
        answer := celsius(current, fromValue)
    else if (toValue = 'F') then
        answer := fahrenheit(current, fromValue)
    else
        answer := kelvin(current, fromValue);

    writeln(answer:0:2);
end.
