#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Cópia de vetores
void copiar(int32_t *destino, int32_t *origem, int32_t n){
    for(int32_t i = 0; i < n; i++){
        destino[i] = origem[i];
    }
}

// Intercalação de vetores
void intercalar(int32_t* S, int32_t* E, int32_t i, int32_t m, int32_t j) {
    // Índices dos vetores
    int32_t i1 = i, i2 = m + 1, k = i;
    // Iteração enquanto houver elementos
    while(i1 <= m && i2 <= j) {
        // Comparação dos elementos
        if(E[i1] <= E[i2]) S[k++] = E[i1++];
        else S[k++] = E[i2++];
    }
    // Cópia dos subvetores
    if(i1 > m) copiar(&S[k], &E[i2], j - i2 + 1);
    else copiar(&S[k], &E[i1], m - i1 + 1);
    copiar(&E[i], &S[i], j - i + 1);
}

// Mergesort recursivo
void mergesort(int32_t* S, int32_t* E, int32_t i, int32_t j) {
    // Caso base
    if(i < j) {
        // Índice do meio do vetor
        int32_t m = i + (j - i) / 2;
        // Divisão em subvetores
        mergesort(S, E, i, m);
        mergesort(S, E, m + 1, j);
        // Combinação dos resultados
        intercalar(S, E, i, m, j);
    }
}

int main(){
    // Vetor de entrada
    int32_t vetor[] = {23, 32, 54, 92, 74, 23, 1, 43, 63, 12};
    // Tamanho do vetor
    int32_t n = sizeof(vetor) / sizeof(vetor[0]);
    // Vetor auxiliar
    int32_t* aux = (int32_t*)malloc(n * sizeof(int32_t));

    // Chamada do mergesort
    mergesort(aux, vetor, 0, n - 1);

    // Impressão do vetor ordenado
    for(int32_t i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberação da memória alocada
    free(aux);

    return 0;
}