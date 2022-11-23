#include<cstdlib>
#include<cstdio>
#include<chrono>
#include<iostream>
#include"Is_In.h"
#include"Auxiliar.h"
using namespace std;

int valores_visitados = 0;

static void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

static void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

static void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

static int* criar_vetor(size_t tamanho) {
    int* vet = new int[tamanho];
	for (int i = 0; i < tamanho; ++i) vet[i] = (int)rand();
	return vet;
}

static void teste_aux(int* vetor, size_t tamanho) {
    printf("teste com vetor de tamanho %zu \n", tamanho);
    int pos = rand() % tamanho;
    int chave = vetor[pos];
    printf("chave %i na posicao %i \n", chave, pos);
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int resultado = is_in(chave, vetor, tamanho);
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    printf("resultado is_in: %i com %i valores visitados \n", resultado, valores_visitados);
    std::cout << "Tempo usado = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "microsegundos[µs]" << std::endl;
    printf("ordenando vetor para teste com is_in_bin...\n");
    quickSort(vetor, 0, tamanho - 1);
    valores_visitados = 0;
    begin = std::chrono::steady_clock::now();
    resultado = is_in_bin(chave, vetor, tamanho);
    end= std::chrono::steady_clock::now();
    printf("resultado is_in_bin: %i com %i valores visitados \n", resultado, valores_visitados);
    std::cout << "Tempo usado = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "microsegundos[µs]" << std::endl;
    printf("\n");
}

void teste(size_t tamanho) {
    int* v = criar_vetor(tamanho);
    teste_aux(v, tamanho);
    delete v;
}