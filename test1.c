#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    int result;
    scanf("%d", &result);

    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        result = gcd(result, x);
    }
    printf("%d\n", result);

    return 0;
}