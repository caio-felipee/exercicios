#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int round;

    while(cin >> round and round != -1) {
        string solution, guess;

        cin >> solution >> guess;

        int wrong = 0;
        int state = 0;

        set<char> s(solution.begin(), solution.end());
        set<char> g;

        cout << "Round " << round << "\n";

        for(auto c : guess) {
            if(s.find(c) != s.end())
                g.insert(c);
            else
                wrong++;
            
            if(wrong >= 7) {
                state = 1;
                break;
            }

            if(g.size() == s.size()) {
                state = 2;
                break;
            }
        }

        if(not state)
            cout << "You chickened out." << "\n";
        else if(state == 1)
            cout << "You lose." << "\n";
        else
            cout << "You win." << "\n";        
    }
}