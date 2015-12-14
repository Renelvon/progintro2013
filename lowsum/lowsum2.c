/* NTUA ECE Progintro Exercise lowsum
 *
 * Given a sorted array, find the sum of two distinct numbers
 * that is closer to 0
 */
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;

    // Reading
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // Use two indexes
    int low = 0, high = n - 1;
    int mind = a[low] + a[high];
    while (low < high) {
        if (abs(a[low] + a[high]) < abs(mind)) {
            mind = a[low] + a[high];
        }
        // always try to get closer to 0
        if (abs(a[low]) > abs(a[high])) {
            ++low;
        } else {
            --high;
        }
    }
    
    // Print result
    printf("%d\n", mind);
    return 0;
}
