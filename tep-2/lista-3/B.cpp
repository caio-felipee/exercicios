#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int round;

    while(cin >> round && round != -1) {
        string solution, guess;

        cin >> solution >> guess;

        string ans = "You chickened out.";
        set<char> sl(solution.begin(), solution.end());
        set<char> gs;
        
        int wrong = 0;

        for(auto letter : guess) {
            if(gs.find(letter) != gs.end())
                continue;
            
            if(sl.find(letter) != sl.end())
                sl.erase(letter);
            else
                wrong++;
            
            if(wrong >= 7) {
                ans = "You lose.";
                break;
            }

            if(!sl.size()) {
                ans = "You win.";
                break;
            }

            gs.insert(letter);
        }

        cout << "Round " << round << "\n" << ans << "\n";
    }
}