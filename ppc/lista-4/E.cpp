#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int entries;
    vector<int> numbers;
    
    cin >> entries;

    for(int i = 0; i < entries; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    for(int number : numbers) cout << number << "\n";
}