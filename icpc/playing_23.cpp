// caio-felipee
//

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

auto solve()
{
    int n;
    cin >> n;

    vi amount(14, 4);
    
    int john = 0, mary = 0;
    for(int i = 0; i < 2; i++)
    {
        int t;
        cin >> t;
        john += min(t, 10);
        amount[t]--;
    }

    for(int i = 0; i < 2; i++)
    {
        int t;
        cin >> t;
        mary += min(t, 10);
        amount[t]--;
    }

    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        john += min(t, 10);
        mary += min(t, 10);
        amount[t]--;
    }

    for(int i = 1; i <= 13; i++)
    {
        if(amount[i] <= 0)
            continue;

        if(mary + min(i, 10) == 23 or (john + min(i, 10) > 23 and mary + min(i, 10) <= 23))
            return i;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--)
    {
        cout << solve() << "\n";
    }
}
