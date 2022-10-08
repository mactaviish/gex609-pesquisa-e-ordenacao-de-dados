#include <stdio.h>

int main() {
    int i, j, aux, minPos;
    int list[] = {7,10,5,3,8,4,2,9,6};
    int n = sizeof(list)/sizeof(list[0]);

    for(i = 0; i <= n-2; i++) {
        minPos = i;
        for(j = i+1; j <= n-1; j++) {
            if (list[j] < list[minPos]) {
                minPos = j;
            }
        }
        aux = list[i];
        list[i] = list[minPos];
        list[minPos] = aux;
    }

    for(i = 0; i < n; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}