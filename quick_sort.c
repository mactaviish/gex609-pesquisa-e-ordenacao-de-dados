#include <stdio.h>

#define TAM 9

void printList(int vet[]) {
    int i = 0;

    while (i < TAM) {
        printf("%d ", vet[i]);
        i++;
    }
    printf("\n");
}

int particiona(int vet[], int ini, int fim) {
    int indexPivo = fim;
    int k = ini;
    int aux;

    for (int i = ini; i < fim; i++) {
        if (vet[i] <= vet[indexPivo]) {
            printList(vet);
            printf("%d <change> %d\n", vet[i], vet[k]);

            aux = vet[i];
            vet[i] = vet[k];
            vet[k] = aux;
            k++;
        }
    }
    
    if (vet[k] > vet[indexPivo]) {
            aux = vet[k];
            vet[k] = vet[indexPivo];
            vet[indexPivo] = aux;
            indexPivo = k;
    }

    return indexPivo;
}

void quickSort(int vet[], int ini, int fim) {
    int indexPivo;

    if (ini < fim) {
        indexPivo = particiona(vet, ini, fim);

        quickSort(vet, ini, indexPivo-1);
        quickSort(vet, indexPivo+1, fim);
    }
}

int main() {
    int list[] = {7,10,5,3,8,4,2,9,6};

    quickSort(list, 0, TAM-1);

    return 0;
}