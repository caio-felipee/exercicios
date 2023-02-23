import string

word = sorted(set(x for x in input()))
alphabet = list(string.ascii_lowercase)

size = len(alphabet)
flag = True

for i in range(size):
    if len(word) - 1 < i or not word[i] == alphabet[i]:
        flag = False
        print(alphabet[i])
        break

if flag:
    print("None")