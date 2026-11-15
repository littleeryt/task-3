#include <stdio.h>
 
/* F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) */
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
 
int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Term %d of the Fibonacci series = %d\n", n, fib(n));
    return 0;
}
