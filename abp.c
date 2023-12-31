#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

ABP* criaArvore(void){
    return NULL;
}

ABP* InsereArvore(ABP *a, int ch)
{
     if (a == NULL)
     {
         a =  (ABP*) malloc(sizeof(ABP));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}

int testaABP(ABP *a)
{
    //se a arvore estiver vazia, devolver verdadeiro
    if(a == NULL)
    {
        return 1;
    }

    //a seguinte logica foi adicionada para evitar seg-fault
    //se a arvore nao tiver algum dos filhos
    else if((a->esq == NULL) || (a->dir == NULL))
    {
        //se a arvore nao tiver filhos, eh uma ABP
        if((a->esq == NULL) && (a->dir == NULL))
        {
            return 1;
        }

        //se tiver filhos em apenas um dos lados, ver se eh ABP
        else if(a->esq != NULL)
        { 
            if(a->esq->info < a->info)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        else
        {
            if(a->dir->info > a->info)
            {
                return 1;
            }

            else
            {
                return 0;
            }
        }
    }

    //se a arvore tiver os dois filhos
    else
    {
        //se os dois filhos obedecem o criterio de uma ABP
        //testar se as subarvores sao ABP
        if((a->esq->info < a->info) && (a->dir->info > a->info))
        {
            return (testaABP(a->esq) && testaABP(a->dir));
        }

        //senao, devolver falso
        else
        {
            return 0;
        }
    }
}

ABP* inverteArvore(ABP *a)
{
    if(a->esq == NULL || a->dir == NULL)
    {
        return a;
    }

    else 
    {
        //troca de ponteiros
        ABP * aux;
        aux = a->esq;
        a->esq = a->dir;
        a->dir = aux;

        inverteArvore(a->esq);
        inverteArvore(a->dir);

        return a;
    }
}

int encontraValor(int valor, ABP *a)
{
    if(a == NULL)
    {
        return 0;
    }

    else if(a->info == valor)
    {
        return 1;
    }

    else
    {
        if(valor <= a->info)
        {
            return encontraValor(valor, a->esq);
        }
        else
        {
            return encontraValor(valor, a->dir);
        }
    }
}

//funcao considera que existe um caminho entre raiz e val1
void percorrePrimCaminho(int val1, ABP *a)
{
    if(a->info == val1)
    {
        printf("%d ", a->info);
    }

    else
    {
        if(val1 <= a->info)
        {
            percorrePrimCaminho(val1, a->esq);
            printf("%d ",a->info);
        }

        else
        {
            percorrePrimCaminho(val1, a->dir);
            printf("%d ",a->info);
        }
    }
}

//funcao considera que existe um caminho entre raiz e val2
void percorreSegunCaminho(int val2, ABP *a)
{
    //se val 2 for a raiz, a raiz ja tera sido mostrada na execucao da outra funcao
    if(a->info != val2)
    {
        if(val2 <= a->info)
        {
            if(a->esq != NULL)
            {
                printf("%d ",a->esq->info);
                percorreSegunCaminho(val2, a->esq);
            }
        }

        else
        {
            if(a->dir != NULL)
            {
                printf("%d ",a->dir->info);
                percorreSegunCaminho(val2, a->dir);
            }
        }
    }
}

void mostraCaminho(int val1, int val2, ABP *a)
{
    //se nao houver um caminho da raiz ate qualquer um dos dois valores, caminho nao existe
    if(!(encontraValor(val1,a) && encontraValor(val2,a)))
    {
        printf("Caminho nao existe\n");
    }

    else if(val1 == val2)
    {
        printf("Valores iguais, caminho vazio\n");
    }

    else if(val1 <= a->info && val2 <= a->info)
    {
        mostraCaminho(val1, val2, a->esq);
    }

    else if(val1 > a->info && val2 > a->info)
    {
        mostraCaminho(val1, val2, a->dir);
    }
    
    else
    {
        percorrePrimCaminho(val1, a);
        percorreSegunCaminho(val2, a);
    }
}

void mostraABP(ABP *a)
{
    if(a != NULL)
    {
        printf("%d\n",a->info);
        mostraABP(a->esq);
        mostraABP(a->dir);
    }
}