#include <stdio.h>
#include <string.h>

int get_sum(int num) {
    int len, sum = 0;
    char temp[1001];

    sprintf((char*)temp, "%u", num);

    len = strlen(temp);

    while(len--) sum += (temp[len] - '0');

    return sum;
}

int get_sum_str(char *digits, int index, int startingAt) {
    if(*(digits + index) == 0) return startingAt;
    int buf = *(digits + index) - '0';

    return get_sum_str(digits, index + 1, startingAt + buf);
}

int main(void) {
    char digits[1001];

    while(scanf(" %[^\n]", digits)) {
        if(digits[0] == '0' && digits[1] == 0) break;
        
        int sum = 0, degree = 1;

        sum = get_sum_str(digits, 0, 0);
        
        while(sum > 9) {
            sum = get_sum(sum);
            degree++;
        }

        sum == 9 ? printf("%s is a multiple of 9 and has 9-degree %d.\n", digits, degree) : printf("%s is not a multiple of 9.\n", digits);
    }
}