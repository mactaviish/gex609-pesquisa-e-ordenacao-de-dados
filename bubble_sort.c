#include <stdio.h>

int main() {
    int i, j, aux;
    int list[] = {7,10,5,3,8,4,2,9,6};
    int n = sizeof(list)/sizeof(list[0]);

    for(i = n-1; i >= 1; i--) {
        for(j = 0; j < i; j++) {
            if (list[j] > list[j+1]) {
                aux = list[j];
                list[j] = list[j+1];
                list[j+1] = aux;
            }
        }
    }

    for(i = 0; i < n; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}