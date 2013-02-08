#include <stdio.h>
#include <stdlib.h>

#define MY_MAX 1000000000

int main () {
    int n;

    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int mind = MY_MAX;
    // An n^2 loop!
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(a[i] + a[j]) < abs(mind)) {
                mind = a[i] + a[j];
                if (mind == 0) { // Is that an improvement?
                    break;
                }
            }
        }
    }

    printf("%d\n", mind);
    return 0;
}
