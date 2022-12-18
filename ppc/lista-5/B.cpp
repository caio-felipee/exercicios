#include <iostream>
#include <vector>

int main(void) {
    int num, index = 1;

    std::cin >> num;

    int buttons[num + 1], ans = 1, tmp;

    for(int i = 1; i <= num; i++) std::cin >> buttons[i];
    
    while(buttons[index] != 2) {
        if(!buttons[index]) {
            ans = -1;
            break;
        }

        ans++;
        tmp = buttons[index];
        buttons[index] = 0;
        index = tmp;
    }

    std::cout << ans << std::endl;
    return 0;
}