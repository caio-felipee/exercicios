#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M, tmp;

    while(cin >> N >> M && (N || M)) {
        set<int> cds;

        for(int i = 0; i < N; i++) {
            cin >> tmp;

            cds.insert(tmp);
        }

        for(int i = 0; i < M; i++) {
            cin >> tmp;

            cds.insert(tmp);
        }

        cout << N + M - cds.size() << endl;
    }
}