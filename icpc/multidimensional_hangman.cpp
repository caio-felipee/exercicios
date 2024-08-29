#include <bits/stdc++.h>

using namespace std;

struct node {
    int next[26];
    int amount = 0;
    bool output = false;

    node() {
        fill(begin(next), end(next), -1);
    }
};

pair<string, int> ans = {"", 0};

void add(string &s, vector<node>&trie, int index = 0, int v = 0, char spec = '*') {
    for(int i = index; i < s.size(); i++)
    {
        if(s[i] == '*')
        {
            for(int c = 0; c < 26; c++)
            {
                if(trie[v].next[c] == -1)
                {
                    trie[v].next[c] = trie.size();
                    trie.emplace_back();
                }

                add(s, trie, i + 1, trie[v].next[c], c + 'a');
            }
            
            return;
        }

        int c = s[i] - 'a';

        if(trie[v].next[c] == -1)
        {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }

        v = trie[v].next[c];
    }

    trie[v].output = true;
    if(index > 0)
        swap(s[index - 1], spec);

    string st = s;

    if(index > 0)
        swap(s[index - 1], spec);

    if(++trie[v].amount > ans.second)
    {
        ans.first = st;
        ans.second = trie[v].amount;
    }
    else if(trie[v].amount == ans.second and ans.first > st)
    {
        ans.first = st;
    }
}

auto solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<node> trie(1);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        add(s, trie);
    }

    cout << ans.first << " " << ans.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}
