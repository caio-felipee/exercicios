#include <bits/stdc++.h>

using namespace std;

/* Este problema envolve uma função (somatório).
*  Ao depender do tamanho, não é possível resolver
*  pelo método de somatório tradicional.
*
* Portanto, ao separar a função em partes, obtive
* a fórmula da soma: l² + l - k².
* Com uma análise mais profunda, portanto, observei
* que é f(x) = x / 2 para números pares e 
* f(x) = ((x + 1) / 2) * (-1) para números ímpares.
*/


int main(void) {
    long long int x;
    long long sum;

    cin >> x;

    if(x % 2 == 0)
        sum = x / 2;
    else
        sum = ((x + 1) / 2) * (-1);
    
    cout << sum << "\n";
}