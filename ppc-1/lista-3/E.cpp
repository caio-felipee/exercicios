#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int tests, budget, ingredients, recipes, i_value, menu_length;

    string bind_name, i_name, menu_name;

    cin >> tests;

    while(tests--) {
        cin.ignore();
        getline(cin, bind_name);

        cin >> ingredients >> recipes >> budget;

        map<string, int> ingredient;
        set<pair<int, string>> menu;

        while(ingredients--) {
            cin >> i_name >> i_value;

            ingredient[i_name] = i_value;
        }

        for(int i = 0; i < recipes; i++) {
            cin.ignore();
            getline(cin, menu_name);

            cin >> menu_length;

            int units, total = 0;
            string name;

            while(menu_length--) {
                cin >> name >> units;

                total += ingredient[name] * units;
            }

            menu.insert({ total, menu_name });
        }
        
        transform(bind_name.begin(), bind_name.end(), bind_name.begin(), ::toupper);
        cout << bind_name << endl;

        bool tooexpensive = true;

        for(auto element : menu) {
            if(element.first <= budget) {
                tooexpensive = false;

                cout << element.second << endl;
                continue;
            }
        }

        if(tooexpensive) puts("Too expensive!");

        cout << endl;
    }
}