#include <stdio.h>
#include <stdint.h>

//O tipo uint32_t é um tipo de dado definido no cabeçalho <stdint.h> em C, que representa um inteiro sem sinal de 32 bits. É usado para garantir que a variável tenha o mesmo tamanho em todas as arquiteturas e sistemas, independentemente da plataforma.


void ordenarLista(uint32_t vetor[], uint32_t tamanho){
    for(uint32_t i = 0; i < tamanho - 1; i++){
        uint32_t indiceMenor = i;
        for(uint32_t j = i + 1; j < tamanho; j++){
            if(vetor[j] < vetor[indiceMenor]){
                indiceMenor = j;
            }
        }

        uint32_t aux = vetor[i];
        vetor[i] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }
}

int main(){
    int32_t vetor[] = {23, 32, 54, 92, 74, 23, 1, 43, 63, 12};
    int tamanho = sizeof(vetor)/sizeof(int);

    ordenarLista(vetor, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
}