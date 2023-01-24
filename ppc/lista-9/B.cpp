#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string str;

    cin >> str;

    int strlen = str.length();

    cout << str[0] << strlen - 2 << str[strlen - 1] << "\n";
    return 0;
}