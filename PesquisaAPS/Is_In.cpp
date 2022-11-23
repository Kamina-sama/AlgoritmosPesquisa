#include"Is_In.h"
extern int valores_visitados;

int is_in(int chave, int* vetor, int num_elementos) {
    valores_visitados = 0;
    for (int i = 0; i < num_elementos; ++i) {
        ++valores_visitados;
        if (vetor[i] == chave) return i;
    }
    return -1;
}

int is_in_bin(int chave, int* vetor, int num_elementos) {
    //caso base:
    if (num_elementos <= 1) {
        ++valores_visitados;
        if (*vetor == chave) return 0;
        else return -1;
    }
    //caso recursivo:
    int* meio = vetor + (num_elementos / 2);
    ++valores_visitados;
    if ((*meio) == chave) return (meio - vetor);
    if (chave < (*meio)) return is_in_bin(chave, vetor, (num_elementos / 2)); //caso a condição falhe, saberemos que chave>(*meio)
    int d = is_in_bin(chave, (meio + 1), (num_elementos / 2));
    //caso seja bem sucedido, d será a defasagem correta com relação a (meio+1), isso significa que meio+1+d apontar� para a chave encontrada, agora basta subtrair vetor para saber a defasagem com relação a este ponteiro.
    return (d == -1) ? -1 : meio + 1 + d - vetor;
}