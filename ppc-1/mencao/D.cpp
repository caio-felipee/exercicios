#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M;

    cin >> N >> M;

    vector<pair<int, int>> values(N); // original position, value
    vector<pair<int, int>> debts(M);

    int value;

    for(int i = 1; i <= N; i++) {
        cin >> value;

        values[i - 1] = { i, value };
    }
    
    sort(values.begin(), values.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    for(int i = 1; i <= M; i++) {
        cin >> value;

        debts[i - 1] = { i, value };
    }
    
    sort(debts.begin(), debts.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int i = 0, j = 0, paid = 0;
    vector<pair<int, int>> payments;
    
    while(j < M && i < N) {
        if(values[i].second >= debts[j].second) {
            paid++;
            payments.push_back({ values[i].first, debts[j].first });
            j++;
        }

        i++;
    }

    cout << paid << "\n";

    for(auto x : payments) 
        cout << x.first << " " << x.second << "\n";
}