#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int N, M;
        cin >> N >> M;
        
        cout << (N % M ? "NO" : "YES") << "\n";
    }

    return 0;
}
