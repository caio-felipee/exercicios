#include <bits/stdc++.h>

using namespace std;

void print(stack<char> s)
{
    if(s.empty())
    {
        cout << "nil\n";
        return;
    }

    string ans = "";
    while(not s.empty())
    {
        auto top = s.top();
        s.pop();

        ans += top;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

void solve(string st)
{
    stack<char> s;

    for(auto c : st)
    {
        if(s.empty() or s.top() == toupper(c))
            s.emplace(toupper(c));
        else
            s.pop();

        print(s);
    }

    cout << (s.empty() ? "Aceito" : "Rejeito") << "\n";
}

int main()
{
    string st;
    while(cin >> st and not cin.eof())
        solve(st);
}
