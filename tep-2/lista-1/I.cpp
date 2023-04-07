#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int datasets;

    cin >> datasets;

    while(datasets--) {
        int M, N, i = 0;

        cin >> M >> N;

        vector<pair<int, int>> black_box; // value, pos

        int tmp;

        for(int i = 1; i <= M; i++) {
            cin >> tmp;

            black_box.push_back({ tmp, i });
        }

        sort(black_box.begin(), black_box.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first;
        });

        while(N--) {
            cin >> tmp;
            i++;

            int j = 0, index = 0;

            while(j < i) {
                if(black_box[index].second <= tmp)
                    j++;
                
                index++;
            }
        
            cout << black_box[index - 1].first << "\n";
        }

        if(datasets)
            cout << "\n";
    }
}