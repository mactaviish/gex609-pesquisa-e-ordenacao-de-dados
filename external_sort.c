#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000
#define MAX_MEM 3

void printList(int vet[], int qtd) {
    int i = 0;

    while (i < qtd) {
        printf("%d\n", vet[i]);
        i++;
    }
}

void randomList(int vet[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        vet[i] = 1 + (rand() % MAX);
    }
}

int qtdElementos() {
    int qtd;

    system("clear");
    printf("Quantidade de elementos: ");
    scanf("%d", &qtd);

    return qtd;
}

void externalSort(int vet[], int n) {
    int arq1[MAX_MEM], arq2[MAX_MEM], arq3[MAX_MEM], arq4[n];
    
    for (int i = 0; i < n; i++) {
        
    }
}

int main() {
    clock_t ini_time, end_time;
    int qtd = qtdElementos();
    int list[qtd];
    float tempo;

    printList(list, qtd);
    externalSort(list, qtd);
    printList(list, qtd);

    return 0;
}