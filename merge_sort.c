#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000

void intercala(int vet[], int ini, int meio, int fim) {
    int i = ini, j = meio+1, k = 0;
    int *aux = malloc(sizeof(int) * (fim-ini+1));

    while ((i <= meio) && (j <= fim)) {
        if (vet[i] <= vet[j]) {
            aux[k] = vet[i];
            i++;
        } else {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        aux[k] = vet[i];
        k++;
        i++;
    }

    while (j <= fim) {
        aux[k] = vet[j];
        k++;
        j++;
    }

    for (k = ini; k <= fim; k++) {
        vet[k] = aux[k - ini];
    }

    free(aux);
}

void mergeSort(int vet[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        
        mergeSort(vet, ini, meio);
        mergeSort(vet, meio+1, fim);
        intercala(vet, ini, meio, fim);
    }
}

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

int main() {
    clock_t ini_time, end_time;
    int qtd = qtdElementos();
    int list[qtd];
    float tempo;
    
    system("clear");
    randomList(list, qtd);
    ini_time = clock();
    mergeSort(list, 0, qtd-1);
    end_time = clock();
    tempo = (double)(end_time - ini_time) / CLOCKS_PER_SEC;

    printf("Estatísticas:\n\n");
    printf("Quantidade de elementos: %d\n", qtd);
    printf("Tempo gasto: %f segundos\n", tempo);

    return 0;
}