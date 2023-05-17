#include <stdio.h>

#define MAX_SIZE 100

int fila[MAX_SIZE];
int end;
int start;

void enqueue()
{
    if (end == MAX_SIZE)
    {
        printf("\nA ja esta fila esta cheia.\n\n");
        return;
    }

    int number;
    printf("Informe um numero: ");
    scanf("%d", &number);

    fila[end] = number;
    printf("\nNumero enfileirado.\n\n");
    end++;
}

void denqueue()
{
    if (start == end)
    {
        printf("\nAcao impossivel. A fila esta vazia.\n\n");
    }
    else
    {
        printf("\nNumero desenfileirado!\n\n");
        start++;
    }
}

void display()
{
    if (start == end)
    {
        printf("A fila esta vazia.\n\n");
    }
    else
    {
        printf("|");
        for (int i = start; i < end; i++)
        {
            printf(" %d |", fila[i]);
        }
        printf("\n\n");
    }
}

void clearQueue()
{
    end = 0;
    start = 0;
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

void hubfunction(int option)
{

    do
    {
        
    menu();

    scanf("%d", &option);

    switch (option)
    {

    case 1:
        enqueue();
        break;
    case 2:
        denqueue();
        break;
    case 3:
        display();
        break;
    case 4:
        clearQueue();
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
    int option = 0;

    end = 0;
    start = 0;

    hubfunction(option);

    return 0;
}