#include <stdio.h>

static long int fib[4096] = {0};

long int fibonacci(int n) {
    if(n == 0) return 0;
    if(n <= 2) return 1;
    if(!fib[n]) fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    
    return fib[n];
}