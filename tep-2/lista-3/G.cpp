#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string bin;

    cin >> bin;

    int i = bin.find('0');

    if(i == -1)
        i = 0;
    
    bin.erase(i, 1);

    cout << bin << "\n";
}