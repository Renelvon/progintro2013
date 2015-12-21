/* NTUA ECE Progintro Exercise twoends
 *
 * Given an array of positive numbers find the largest sum
 * that is equal starting from both ends
 * Σ a[0..i] == Σ a[j..N-1] with i < j
 */
#include <stdio.h>

int main () {
    int n;
    
    // Reading
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    // Use two indices
    int i = 0, j = n - 1;
    int bests = 0, s1 = 0, s2 = 0;

    while (i <= j) {
        // Always increase the smaller sum
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
