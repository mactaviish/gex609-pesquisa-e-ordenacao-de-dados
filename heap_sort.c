#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000

void printList(int vet[], int qtd) {
    int i = 0;

    while (i < qtd) {
        printf("%d\n", vet[i]);
        i++;
    }
}

void troca(int vet[], int a, int b) {
    int aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
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

void criaHeap(int vet[], int i, int n) {
    int maior = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if ((left < n) && (vet[left] > vet[i]))
        maior = left;

    if ((right < n) && (vet[right] > vet[maior]))
        maior = right;

    if (maior != i) {
        troca(vet, i, maior);
        criaHeap(vet, maior, n);
    }
}

void heapSort(int vet[], int n) {
    for (int k = (n/2)-1; k >= 0; k--)
        criaHeap(vet, k, n);

    for (int k = n-1; k >= 1; k--) {
        troca(vet, 0, k);
        criaHeap(vet, 0, k);
    }
}

int main() {
    clock_t ini_time, end_time;
    int qtd = qtdElementos();
    int list[qtd];
    float tempo;

    system("clear");
    randomList(list, qtd);
    ini_time = clock();
    heapSort(list, qtd);
    end_time = clock();
    tempo = (double)(end_time - ini_time) / CLOCKS_PER_SEC;

    printf("Estatísticas:\n\n");
    printf("Quantidade de elementos: %d\n", qtd);
    printf("Tempo gasto: %f segundos\n", tempo);

    return 0;
}