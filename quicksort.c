#include <stdio.h>
#include <stdint.h>

void trocar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//Particionamento do Quicksort (Hoare)
int hoare(int *V, int i, int j){
    //Declaração do pivô e índices
    int P = V[i], x = i - 1, y = j + 1;
    //Particionando o vetor pelo pivô
    while(1){
        while(V[--y] > P);
        while(V[++x] < P);
        if(x < y) trocar(&V[x], &V[y]);
        else return y;
    }
}

// Particionamento do Quicksort (Hoare randômico)
void hoare_rand(int *V, int i, int j){
    trocar(&V[i], &V[i + rand() % (j - i + 1)]);
    return hoare(V, i, j);
}

// Algoritmo de seleção (Hoare)
int selecaoHoare(int* V, int i, int j, int k) {
    // Caso base
    if(i == j) return i;
    // Recorrência
    else {
        int m = hoare(V, i, j);
        if(m - i + 1 >= k) return selecaoHoare(V, i, m, k);
        else return selecaoHoare(V, m + 1, j, k - (m - i + 1));
    }
}

//Quicksort recursivo Hoare
void quicksortHoare(int *V,  int i, int j){
    //Caso base
    if(i < j){
        //Particionamento do vetor
        int pivo = hoare(V, i, j);
        //Divisão em subvetores
        quicksortHoare(V, i, pivo);
        quicksortHoare(V, pivo + 1, j);
    }
}

//Particionamento do Quicksort (Lomuto)
int lomuto(int *V, int i, int j){
    //Declaração do pivô e índices
    int P = V[j], x = i - 1, y = i;
    //Particionando o vetor pelo pivô
    for(y = i; y < j; y++){
        if(V[y] <= P) trocar(&V[++x], &V[y]);
    }
    //Posicionando o pivô no vetor
    trocar(&V[++x], &V[j]);
    return x;
}

//Particionamento do Quicksort (Lomuto randômico)
void lomuto_rand(int *V, int i, int j){
    trocar(&V[j], &V[i + rand() % (j - i + 1)]);
    return lomuto(V, i, j);
}


// Algoritmo de seleção (Lomuto)
int selecaoLomuto(int* V, int i, int j, int k) {
    // Caso base
    if(i == j) return i;
    // Recorrência
    else {
        int m = lomuto(V, i, j);
        if(m - i + 1 >= k) return selecaoLomuto(V, i, m, k);
        else return selecaoLomuto(V, m + 1, j, k - (m - i + 1));
    }
}

//Quicksort recursivo Lomuto
void quicksortLomuto(int *V,  int i, int j){
    //Caso base
    if(i < j){
        //Particionamento do vetor
        int pivo = lomuto(V, i, j);
        //Divisão em subvetores
        quicksortLomuto(V, i, pivo - 1);
        quicksortLomuto(V, pivo + 1, j);
    }
}

int main(){

    return 0;
}