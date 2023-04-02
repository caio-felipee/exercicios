#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string buffer, concat;
    set<string> words;

    while(cin >> buffer) {
        concat += buffer;

        if(concat.back() == '-') {
            concat.pop_back();
            continue;
        }

        transform(concat.begin(), concat.end(), concat.begin(), ::tolower);

        string nw;

        for(int i = 0; i < concat.size(); i++) {
            if(concat[i] == '-' || (concat[i] >= 'a' && concat[i] <= 'z')) {
                nw += concat[i];
            }
            
            else {
                if(nw.size() > 0) words.insert(nw);
                nw.clear();
            }
        }

        if(nw.size() > 0) words.insert(nw);

        concat.clear();
    }

    for(string word : words) {
        cout << word << "\n";
    }
}