#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> houses;
    int num, buf;

    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> buf;

        houses.push_back(buf);
    }

    sort(houses.begin(), houses.end(), greater<int>());

    cout << houses[0] - houses[houses.size() - 1] << endl;
}