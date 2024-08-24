#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int N;
        cin >> N;

        cout << (N % 4 ? "NO" : "YES") << "\n";
    }

    return 0;
}
