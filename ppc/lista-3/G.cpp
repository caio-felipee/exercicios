#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int tests;

    cin >> tests;

    for(int test = 1; test <= tests; test++) {
        int num_subjects, days;
        string sub;

        map<string, int> subjects;

        cin >> num_subjects;

        while(num_subjects--) {
            cin >> sub >> days;

            subjects[sub] = days;
        }

        cin >> days >> sub;

        cout << "Case " << test << ": ";

        if(subjects.count(sub)) {
            int time = subjects[sub];

            if(time <= days) puts("Yesss");
            else if(time <= days + 5) puts("Late");
            else puts("Do your own homework!");
        }
        
        else puts("Do your own homework!");

    }
}