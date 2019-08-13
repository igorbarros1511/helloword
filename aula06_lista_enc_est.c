
#define MAX 100

/* Estruturas do TAD LISTA_ENC_EST */
struct nodo {
    float info;
    int proximo;
};

typedef struct nodo Nodo;

struct lista {
    int ind_pri_ele;
    int ind_nodo_livre;
    Nodo elementos[MAX];    /* #define max 100, por exemplo */
};

typedef struct lista Lista;

void inicializa (Lista *l) {
    int i;
    l->ind_pri_ele    = -1;
    l->ind_nodo_livre = 0;
    for (i = 0; i < MAX - 1; i++)
        l->elementos[i].proximo = i + 1;
    l->elementos[i].proximo = -1;
}

int vazia (Lista *l) {
    return (l->ind_pri_ele == -1);
}

int tamanho (Lista *l) {
    int cont=0, ind=l->ind_pri_ele;

    while (ind != -1) {
        cont++;
        ind = l->elementos[ind].next;
    }

    return cont;
}

void ins (LISTA_ENC_EST *l, int pos, float val) {
if (pos<1 || pos> tam(l)+1) {
printf("\nPosicao invalida!");
exit (1);
} else {
if (l->ind_nodo_livre != -1) {
int aux;
if (pos==1) {
l->elementos[l->ind_nodo_livre].inf=val;
aux=l->elementos[l->ind_nodo_livre].next;
l->elementos[l->ind_nodo_livre].next=l-

>ind_pri_ele;

l->ind_pri_ele=l->ind_nodo_livre;

l->ind_nodo_livre=aux;
}
else {
int ind;
for (ind=l->ind_pri_ele; --pos-1; ind=l-

>elementos[ind].next);

l->elementos[l->ind_nodo_livre].inf=val;
aux=l->elementos[l->ind_nodo_livre].next;
l->elementos[l->ind_nodo_livre].next=l-

>elementos[ind].next;

l->elementos[ind].next=l->ind_nodo_livre;
l->ind_nodo_livre=aux;
}
} else {
printf("\nImpossivel inserir novos
elementos.\nMemoria insuficiente.");
exit (2); } } }

float recup (LISTA_ENC_EST *l, int pos)
{
if (pos<1 || pos> tam(l))
{
printf("\nPosicao invalida!");
exit (1);
}
else
{
int ind=l->ind_pri_ele;
while (--pos)
ind = l->elementos[ind].next;
return l->elementos[ind].inf;
}
}