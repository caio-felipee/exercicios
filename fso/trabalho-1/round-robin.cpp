#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

auto calc_it(int amount, int time)
{
    return (amount / time) + (amount % time > 0);
}

int main()
{
    int N, T, pid, time;
    cin >> N >> T;

    vector<ii> ps;
    for(int i = 1; i <= N; i++)
    {
        cin >> pid >> time;
        time *= 1000;
        
        ps.emplace_back(pid, time);
    }
    
    int total = 0;
    for(int i = 1; i <= N; i++)
    {
        int bt = -1, bi = -1, amount = 0;
        for(int j = 0; j < N; j++)
        {
            auto [pid, time] = ps[j];

            if(time <= 0)
                continue;
            
            auto it = calc_it(time, T);
            if(bt == -1 or (bt > it))
            {
                bt = it;
                bi = j;
            }

            ++amount;
        }

        if(bi < 0)
            break;

        total += (--amount * T * (bt - 1));
        for(int j = 0; j < bi; j++)
        {
            auto &[pid, time] = ps[j];

            if(time > 0)
            {
                time -= T * bt;
                total += T;
            }
        }

        for(int j = bi + 1; j < N; j++)
        {
            auto &[pid, time] = ps[j];

            if(time > 0)
                time -= T * (bt - 1);
        }

        auto &[pid, time] = ps[bi];
        auto rm = (bt - 1) * T;
        total += rm; 
        total += min(T, time - rm);
        time = 0;

        cout << pid << " (" << total << ")\n";

        for(int j = bi; j < N; j++)
        {
            auto &[p, t] = ps[j];
            auto rm = min(T, t);
            t -= rm;
            total += rm;

            if(rm > 0 and t <= 0)
            {
                cout << p << " (" << total << ")\n";
            }
        }
    }
}

