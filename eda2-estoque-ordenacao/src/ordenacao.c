#include <stdio.h>
#include "../include/estoque.h"

// 1. Insertion Sort: Ordena por PREÇO (Crescente)
// Algoritmo simples, natural e estável com complexidade O(n^2).
void insertion_sort_preco(PecaRoupa estoque[], int n) {
    int i, j;
    PecaRoupa chave;
    for (i = 1; i < n; i++) {
        chave = estoque[i];
        j = i - 1;
        while (j >= 0 && estoque[j].preco > chave.preco) {
            estoque[j + 1] = estoque[j];
            j--;
        }
        estoque[j + 1] = chave;
    }
}

// 2. Bubble Sort: Ordena por QUANTIDADE (Crescente)
// Realiza comparações adjacentes sucessivas, "borbulhando" os maiores valores.
void bubble_sort_quantidade(PecaRoupa estoque[], int n) {
    int i, j, trocou;
    PecaRoupa temp;
    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (estoque[j].quantidade > estoque[j + 1].quantidade) {
                temp = estoque[j];
                estoque[j] = estoque[j + 1];
                estoque[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break; // Otimização caso o vetor já esteja ordenado
    }
}

// 3. Shell Sort: Ordena por CÓDIGO (Crescente)
// Criado por Donald Shell (1959), atua refinando o Insertion Sort em múltiplos segmentos.
void shell_sort_codigo(PecaRoupa estoque[], int n) {
    int gap, i, j;
    PecaRoupa chave;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            chave = estoque[i];
            j = i;
            while (j >= gap && estoque[j - gap].codigo > chave.codigo) {
                estoque[j] = estoque[j - gap];
                j -= gap;
            }
            estoque[j] = chave;
        }
    }
}

// Função para exibir o estoque formatado em tabela no terminal
void imprimir_estoque(PecaRoupa estoque[], int n) {
    printf("\n%-8s %-28s %-8s %-12s %-10s\n", "CÓDIGO", "DESCRIÇÃO", "TAMANHO", "PREÇO (R$)", "QUANTIDADE");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-8d %-28s %-8s %-12.2f %-10d\n", 
               estoque[i].codigo, 
               estoque[i].descricao, 
               estoque[i].tamanho, 
               estoque[i].preco, 
               estoque[i].quantidade);
    }
    printf("-----------------------------------------------------------------------\n");
}
