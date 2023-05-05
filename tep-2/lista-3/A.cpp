#include <bits/stdc++.h>

using namespace std;

int main(void) {
    double a, b, c;

    cin >> a >> b >> c;

    cout << fixed << setprecision(10);

    if(!a) {
        if(!b && !c)
            cout << -1 << "\n";
        else if(!b) {
            cout << 0 << "\n";
        }
        else {
            cout << 1 << "\n";
            cout << -c / b << "\n";
        }
    }

    else {
        if(b * b < 4 * a * c) {
            cout << 0 << "\n";
        }

        else if(b * b == 4 * a * c) {
            cout << 1 << "\n";
            cout << -b / (2.0 * a) << "\n";
        }

        else {
            cout << 2 << "\n";

            double first_root = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
            double second_root = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);

            cout << min(first_root, second_root) << "\n";
            cout << max(first_root, second_root) << "\n";
        }
    }
}