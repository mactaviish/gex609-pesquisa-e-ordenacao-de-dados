#include <stdio.h>

int main() {
    int i, j, p;
    int list[] = {7,10,5,3,8,4,2,9,6};
    int n = sizeof(list)/sizeof(list[0]);

    for(i = 1; i <= n-1; i++) {
        p = list[i];
        for(j = i; (i >= 1) && (p < list[j-1]); j--) {
            list[j] = list[j-1];
        }
        list[j] = p;
    }

    for(i = 0; i < n; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}