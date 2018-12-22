#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBITO 0.0229
#define TARIFA 0.0379 //Recebimento em 14 Dias

void CalculaMaquineta( float valor, float taxas[], float taxasOnline[])
{
    int i;
    float taxaTotal;
    float valorPorParcela;
    float valorFinal;

    valorFinal = valor/( 1.00 - DEBITO );

    printf("\n####### NO DEBITO\n");
    printf( "\n1x de R$ %.2f..................Total: R$ %.2f",valorFinal,valorFinal);
    printf("\n\n");

    printf("####### NO CREDITO\n");
    for(i=0; i<12; i++)
    {
        taxaTotal = taxas[i] + TARIFA;
        valorFinal = valor/( 1.00 - taxaTotal );
        valorPorParcela = valorFinal/(i+1);

        printf( "\n%dx de R$ %.2f..................Total: R$ %.2f",(i+1),valorPorParcela, valorFinal);
    }
    printf("\n\n");

    printf("####### NO APLICATIVO ONLINE\n");
    for(i=0; i<12; i++)
    {
        taxaTotal = taxasOnline[i];
        valorFinal = valor/( 1.00 - taxaTotal );
        valorPorParcela = valorFinal/(i+1);

        printf( "\n%dx de R$ %.2f..................Total: R$ %.2f",(i+1),valorPorParcela, valorFinal);
    }
    printf("\n\n");
}

int main()
{
    int input;
    float value;

    float taxas[] = {
        0.0, //1x é somente a Tarifa
        0.0409,
        0.0541,
        0.0670,
        0.0796,
        0.092,
        0.1041,
        0.1161,
        0.1278,
        0.1392,
        0.1505,
        0.1615
    };

    float taxasOnline[] = {
        0.05,
        0.0721,
        0.0933,
        0.1135,
        0.1296,
        0.1420,
        0.1541,
        0.1661,
        0.1778,
        0.1892,
        0.200,
        0.2115
    };


    do
    {
       printf("______________________________________\n");
       printf("::: CALCULADORA DE VENDA :::\n");
       printf("______________________________________\n\n");


        printf ("\nValor a Receber R$?\n");
        scanf(" %f", &value);

        CalculaMaquineta(value, taxas, taxasOnline);

    }while(1);

    return 0;
}
