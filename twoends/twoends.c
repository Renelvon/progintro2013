#include <stdio.h>

int main () {
    int n;

    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int i = 0, j = n - 1;
    int bests = 0, s1 = 0, s2 = 0;

    while (i <= j) {
        if (s1 < s2) {
            s1 += a[i];
            ++i;
        } else {
            s2 += a[j];
            --j;
        }
        if (s1 == s2) {
            bests = s1;
        }
    }

    printf("%d\n", bests);
    return 0;
}
