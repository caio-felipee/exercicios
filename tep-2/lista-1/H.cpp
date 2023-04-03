#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string str;

    cin >> str;

    set<char> param;

    for(auto x : str)
        param.insert(x);
    
    if(param.size()&1)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";
    
    cout << "\n";
}