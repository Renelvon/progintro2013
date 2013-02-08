#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;

    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int low = 0, high = n - 1;
    int mind = a[low] + a[high];
    while (low < high) {
        if (abs(a[low] + a[high]) < abs(mind)) {
            mind = a[low] + a[high];
        }
        if (abs(a[low]) > abs(a[high])) {
            ++low;
        } else {
            --high;
        }
    }

    printf("%d\n", mind);
    return 0;
}
