#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int creatures, relations;

    while(std::cin >> creatures >> relations) {
        if(creatures == 0) break;

        map<string, vector<string>> animal;

        while(creatures--) {
            string a;

            cin >> a;

            animal.insert({ a, {} });
        }

        while(relations--) {
            string a, b;

            cin >> b >> a;
            
            animal[b].push_back(a);
            animal[a].push_back(b);
        }

        int ans = 0;
        set<string> examinated;
        stack<string> toExam;

        for(auto a : animal) {
            int tt = 0;

            if(examinated.find(a.first) == examinated.end()) {
                examinated.insert(a.first);
                toExam.push(a.first);

                while(!toExam.empty()) {
                    tt++;
                    string c = toExam.top();
                    toExam.pop();

                    for(auto d : animal[c]) {
                        if(examinated.find(d) == examinated.end()) {
                            examinated.insert(d);
                            toExam.push(d);
                        }
                    }
                }
            }

            if(tt > ans) ans = tt;
        }

        cout << ans << "\n";
    }
}