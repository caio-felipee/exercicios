from random import randint

letter_a = ["a", "A", "Á", "á"]
word = "Ola Mundo"
MAX = 100

words = []
for _ in range(MAX):
    words.append("")

    for x in word:
        if x == "a":
            x = letter_a
        
        if(isinstance(x, list)):
            x = x[randint(0, len(letter_a) - 1)]
        elif randint(0, 1):
          x = x.upper()
         
        words[-1] += x

print(*words, sep="\n")
