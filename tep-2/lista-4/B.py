from math import gcd

# n mod p

# Através de algumas pesquisas, descobri que os números primos
# em questão das raízes primitivas, possuem uma "fórmula" para
# determinar o número de raízes primitivas de p.

# Todos os números primos possuem ao menos uma raiz. Porém, para
# descobrir os valores, basta aplicar a fórmula Função Totiente de Euler.

"""
A função totiente, por vezes também chamada de função tociente, ou função phi, 
representada por φ(x), é, na teoria dos números, definida para um número natural x
como sendo igual à quantidade de números menores ou igual a x co-primos com respeito a ele.
"""

def phi(n):
    amount = 0        
    for k in range(1, n + 1):
        if gcd(n, k) == 1:
            amount += 1
    return amount

print(phi(int(input()) - 1))