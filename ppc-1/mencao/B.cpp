#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int soro = 3, antibiotico = 5, reavaliacao = 12;
    bool flag = true;

    int hours;

    cin >> hours;

    cout << hours << " horas de tratamento:" << "\n";

    if(hours % soro == 0) {
        cout << "Troca do soro" << "\n";
        flag = false;
    }
    
    if(hours % antibiotico == 0) {
        cout << "Injecao de antibioticos" << "\n";
        flag = false;
    }
    
    if(hours % reavaliacao == 0) {
        cout << "Reavaliacao" << "\n";
        flag = false;
    }

    if(flag)
        cout << "Monitoramento dos sinais vitais" << "\n";
    
}