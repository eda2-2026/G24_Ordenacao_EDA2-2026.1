#include <stdio.h>
#include "../include/estoque.h"

int main() {
    // Inicializando um estoque de exemplo desordenado
    PecaRoupa estoque[] = {
        {502, "Calca Jeans Premium", "M", 189.90, 12},
        {105, "Camiseta Basica Algodao", "G", 49.90, 35},
        {304, "Jaqueta Couro Sintetico", "GG", 299.50, 4},
        {201, "Vestido Estampado Verao", "P", 120.00, 8},
        {409, "Moletom com Capuz Unissex", "M", 150.00, 15},
        {603, "Bermuda Sarja Bege", "G", 89.90, 20}
    };
    
    int n = sizeof(estoque) / sizeof(estoque[0]);
    int opcao;
    
    do {
        printf("\n===================================================\n");
        printf("         GERENCIADOR DE ESTOQUE DE ROUPAS          \n");
        printf("===================================================\n");
        printf("1. Exibir estoque atual (sem alteracao)\n");
        printf("2. Ordenar por Preco       [Insertion Sort]\n");
        printf("3. Ordenar por Quantidade  [Bubble Sort]\n");
        printf("4. Ordenar por Codigo      [Shell Sort]\n");
        printf("5. Benchmark: Comparar desempenho dos algoritmos\n");
        printf("0. Sair\n");
        printf("===================================================\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) break;
        
        switch(opcao) {
            case 1:
                printf("\n--- VISÃO DO ESTOQUE ---\n");
                imprimir_estoque(estoque, n);
                break;
            case 2:
                insertion_sort_preco(estoque, n);
                printf("\n[OK] Estoque ordenado por PREÇO (Crescente) via Insertion Sort!\n");
                imprimir_estoque(estoque, n);
                break;
            case 3:
                bubble_sort_quantidade(estoque, n);
                printf("\n[OK] Estoque ordenado por QUANTIDADE (Crescente) via Bubble Sort!\n");
                imprimir_estoque(estoque, n);
                break;
            case 4:
                shell_sort_codigo(estoque, n);
                printf("\n[OK] Estoque ordenado por CÓDIGO (Crescente) via Shell Sort!\n");
                imprimir_estoque(estoque, n);
                break;
            case 5: {
                printf("\n===================================================\n");
                printf("   BENCHMARK — COMPARAÇÃO DE DESEMPENHO           \n");
                printf("   (Executado sobre o estado atual do estoque)     \n");
                printf("===================================================\n");

                Metricas mi = benchmark_insertion_sort(estoque, n);
                Metricas mb = benchmark_bubble_sort(estoque, n);
                Metricas ms = benchmark_shell_sort(estoque, n);

                printf("\n%-20s %-15s %-10s\n", "Algoritmo", "Comparacoes", "Trocas");
                printf("---------------------------------------------------\n");
                printf("%-20s %-15ld %-10ld\n", "Insertion Sort", mi.comparacoes, mi.trocas);
                printf("%-20s %-15ld %-10ld\n", "Bubble Sort",    mb.comparacoes, mb.trocas);
                printf("%-20s %-15ld %-10ld\n", "Shell Sort",     ms.comparacoes, ms.trocas);
                printf("---------------------------------------------------\n");
                printf("\n[NOTA] O benchmark nao altera o estoque exibido.\n");
                printf("[NOTA] Shell Sort tende a usar menos comparacoes\n");
                printf("       por operar com gaps decrescentes (O(n log n)).\n");
                break;
            }
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
    
    return 0;
}
