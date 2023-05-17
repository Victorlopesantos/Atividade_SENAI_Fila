#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct 
{
    int *fila;
    int end;
    int start;
} Fila;

void enqueue(Fila *fila) 
{
    
    if (fila->fila == NULL)
    {
        fila->fila = (int *)malloc(MAX_SIZE * sizeof(int));

        if (fila->fila == NULL)
        {
            printf("Falha na alocacao de memoria. Encerrando o programa.\n");
            exit(1);
        }
    }

    if (fila->end == MAX_SIZE) 
    {
        printf("\nA fila esta cheia.\n\n");
        return;
    }

    int number;
    printf("Informe um numero: ");
    scanf("%d", &number);

    fila->fila[fila->end] = number;
    fila->end++;
    printf("\nNumero enfileirado.\n\n");
}

void denqueue(Fila *fila) 
{

    if (fila->start == fila->end) 
    {
        printf("\nAcao impossivel. A fila esta vazia.\n\n");
    } 
    else 
    {
        printf("\nNumero desenfileirado!\n\n");
        fila->start++;
    }
}

void display(Fila *fila) 
{

    if (fila->start == fila->end) 
    {
        printf("A fila esta vazia.\n\n");
    } 
    else 
    {
        printf("Fila: ");
        for (int i = fila->start; i < fila->end; i++) 
        {
            printf("%d ", fila->fila[i]);
        }

        printf("\nTotal de elementos na fila: %d\n\n", fila->end - fila->start); // Conta quantos elementos estão na fila.
    }
}

void clearQueue(Fila *fila) 
{

    fila->end = 0;
    fila->start = 0;
    printf("\nA fila foi zerada.\n\n");
}

void menu() 
{

    printf("=== MENU ===\n");
    printf("1. Enfileirar\n");
    printf("2. Desenfileirar\n");
    printf("3. Exibir fila\n");
    printf("4. Limpar fila\n");
    printf("5. Sair\n");
    printf("============\n");
}

void hubFunction(int option, Fila *fila)
{
    do 
    {
        menu();
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                enqueue(&fila);
                break;
            case 2:
                denqueue(&fila);
                break;
            case 3:
                display(&fila);
                break;
            case 4:
                clearQueue(&fila);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida\n\n");
                break;
        }
    } while (option != 5);
}

int main() 
{

    Fila fila;
    fila.fila = NULL;
    fila.end = 0;
    fila.start = 0;

    int option = 0;

    hubFunction(option, &fila);

    free(fila.fila); // Liberação da memória alocada

    return 0;
}