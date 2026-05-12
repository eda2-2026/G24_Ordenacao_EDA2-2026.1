#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct {
    int codigo;
    char descricao[50];
    char tamanho[5];
    float preco;
    int quantidade;
} PecaRoupa;

typedef struct {
    long comparacoes;
    long trocas;
} Metricas;

void insertion_sort_preco(PecaRoupa estoque[], int n);
void bubble_sort_quantidade(PecaRoupa estoque[], int n);
void shell_sort_codigo(PecaRoupa estoque[], int n);

Metricas benchmark_insertion_sort(PecaRoupa estoque[], int n);
Metricas benchmark_bubble_sort(PecaRoupa estoque[], int n);
Metricas benchmark_shell_sort(PecaRoupa estoque[], int n);

void imprimir_estoque(PecaRoupa estoque[], int n);

#endif
