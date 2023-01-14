#include <bits/stdc++.h>

using namespace std;

int find_set(int x, vector<int> &ps) {
    return ps[x] == x ? x : (ps[x] = find_set(ps[x], ps));
}

bool same_set(int x, int y, vector<int> &ps) {
    return find_set(x, ps) == find_set(y, ps);
}

void union_set(int x, int y, vector<int> &ps, vector<int> &size) {
    if(same_set(x, y, ps))
        return;
    
    int p = find_set(x, ps);
    int q = find_set(y, ps);

    if(size[p] < size[q])
        swap(p, q);
    
    ps[q] = p;
    size[p] += size[q];
}

int main(void) {
    int n, m, c, a, b;

    cin >> n >> m;
    cin >> c;

    vector<int> size(n + 1, 1), ps(n + 1);

    iota(ps.begin(), ps.end(), 0);

    while(c--) {
        cin >> a >> b;

        union_set(a, b, ps, size);
    }

    set<int> groups;

    int valid = 0, highest = 0;

    for(int i = 1; i <= n; i++) {
        int set = find_set(i, ps);

        if(groups.count(set))
            continue;
        else
            groups.insert(set);
        
        if(size[set] >= m) {
            valid++;

            if(size[set] > highest) {
                highest = size[set];
            }
        }
    }
    
    if(valid > 0)
        cout << valid << " " << highest << "\n";
    else
        cout << valid << "\n";
    
    return 0;
}