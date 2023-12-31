typedef struct arvore{
    int info;
    struct arvore *dir;
    struct arvore *esq;
}ABP;

ABP* criaArvore(void);

ABP* InsereArvore(ABP *a, int ch);

int testaABP(ABP *a);

ABP* inverteArvore(ABP *a);

//mostra caminho
int encontraValor(int valor, ABP *a);

void percorrePrimCaminho(int val1, ABP *a);

void percorreSegunCaminho(int val2, ABP *a);

void mostraCaminho(int val1, int val2, ABP *a);

//funcao extra criada para visualizacao da abp
void mostraABP(ABP *a);