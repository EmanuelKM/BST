#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

int main()
{
    ABP * arvore;
    int input = -1;
    int num, val1, val2;

    arvore = criaArvore();

    do{
        printf("1 - inserir na arvore\n2 - mostrar arvore\n3 - inverter arvore\n4 - testar ABP\n5 - mostrar caminho entre dois valores\n0 - sair\n");
        scanf("%d",&input);

        switch (input)
        {
            case 1:
                printf("Insira um numero: ");
                scanf("%d",&num);

                arvore = InsereArvore(arvore, num);
                break;

            case 2:
                printf("Arvore:\n");
                mostraABP(arvore);
                break;

            case 3:
                arvore = inverteArvore(arvore);
                break;

            case 4:
                if(testaABP(arvore))
                {
                    printf("Eh ABP\n");
                }

                else
                {
                    printf("Nao eh ABP\n");
                }
                break;

            case 5:
                printf("Insira o valor de inicio: "); scanf("%d",&val1);
                printf("Insira o valor de chegada: "); scanf("%d",&val2);
                printf("Caminho: ");
                mostraCaminho(val1,val2,arvore);
                printf("\n"); //quebra de linha inserida para melhorar display no terminal
                break;
        }
    }while(input != 0);

    return 0;
}

