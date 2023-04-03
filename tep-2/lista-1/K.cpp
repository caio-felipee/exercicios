#include <bits/stdc++.h>

using namespace std;

void print_backwards(stack<char> *str) {
    char c = (*str).top();
    
    (*str).pop();
    
    if(!(*str).empty())
        print_backwards(str);
    
    cout << c;
}   

int main(void) {
    stack<char> str;

    string line;

    cin >> line;

    for(auto x : line) {
        if(x == 'B') {
            if(!str.empty()) {
                str.pop();
            }
        }

        else {
            str.push(x);
        }
    }

    print_backwards(&str);

    cout << "\n";
}