#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> p_amount(N);
    for(auto &x : p_amount)
        cin >> x;

    queue<pair<int, queue<int>>> es;
    for(int i = 0; i < N; i++)
    {
        queue<int> tmp;
        while(p_amount[i]--)
        {
            int t;
            cin >> t;
            tmp.emplace(t);
        }
        
        es.emplace(i + 1, tmp);
    }

    int curr = 0;
    while(es.size()) {
        auto &[id, q] = es.front();
        
        while(q.size()) {
            auto &f = q.front();

            if(f) {
                f = 0;
                break;
            }

            q.pop();
            curr += 10;
        }

        if(q.empty())
            cout << id << " (" << curr << ")\n";
        else
            es.emplace(id, q);
        es.pop();
    }
}
