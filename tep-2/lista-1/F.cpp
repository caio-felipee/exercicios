#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, Q;

    cin >> N >> Q;

    vector<tuple<int, bool, int>> v; // bool: is_beginning

    int S, T, X;

    while(N--) {
        cin >> S >> T >> X;    

        v.push_back(make_tuple(S - X, true, X));
        v.push_back(make_tuple(T - X, false, X));
    }

    sort(v.begin(), v.end());

    set<int> t;
    int index = 0, size = v.size();

    while(Q--) {
        int D;

        cin >> D;
        
        for(int i = index; i < size; i++) {
            auto x = v[i];

            if(get<0>(x) > D)
                break;

            index++; 

            if(get<1>(x)) {
                t.insert(get<2>(x));
            }

            else {
                t.erase(get<2>(x));
            }
        
        }

        cout << (t.empty() ? -1 : *t.begin()) << "\n";
    }
}