#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;

    cin >> N;

    map<string, int> shoes;
    
    bool is_possible = true;

    string model;
    int quantity;

    for(int i = 0; i < N; i++) {
        cin >> model >> quantity;

        shoes.insert({ model, quantity });
    }

    int requests;

    cin >> requests;

    for(int i = 0; i < requests; i++) {
        cin >> model >> quantity;

        shoes[model] -= quantity;

        if(shoes[model] < 0)
            is_possible = false;
    }

    if(is_possible)
        cout << "Sim" << "\n";
    else
        cout << "Nao" << "\n";
}