#include <bits/stdc++.h>

using namespace std;

vector<long long> xs(200000);

int main(void) {
    long long x;

    while(cin >> x and not cin.eof()) {
        string tmp;

        getline(cin, tmp);
        getline(cin, tmp);

        stringstream input;

        input << tmp;

        long long t, i = 0;

        while(input >> xs[i++]);        

        i -= 2;

        long long ans = 0;
        long long power = 1;

        for(int j = i; j > 0; j--) {
            long long p = power;

            if(power == 1)
                power = x;
            else
                power *= x;
            
            ans += (p * xs[j - 1] * (i - j + 1));
        }

        cout << ans << "\n";
    }
}