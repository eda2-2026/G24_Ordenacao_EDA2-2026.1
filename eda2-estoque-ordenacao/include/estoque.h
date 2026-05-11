#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct {
    int codigo;
    char descricao[50];
    char tamanho[5];
    float preco;
    int quantidade;
} PecaRoupa;

// Funções de ordenação aplicadas a diferentes critérios
void insertion_sort_preco(PecaRoupa estoque[], int n);
void bubble_sort_quantidade(PecaRoupa estoque[], int n);
void shell_sort_codigo(PecaRoupa estoque[], int n);

// Função auxiliar para exibição
void imprimir_estoque(PecaRoupa estoque[], int n);

#endif
