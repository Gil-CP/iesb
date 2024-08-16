#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    struct lista *adj;
    int visitado;
} vertice;

typedef struct lista
{
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void mostrar_lista(lista *l);
void incluir_final(lista *l, int x);
void incluir_vertice_lista_adjacencia(vertice *v, int valor);
void dfs(int raiz , vertice * vertices);
int main()
{

    int qtd_vertices, qtd_arestas,i,a,b;
    

    vertice *vertices;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertices = (vertice *)calloc(sizeof(vertice), qtd_vertices + 1);

    for(i=0;i<qtd_arestas;i++)
    {   
        scanf("%d %d",&a,&b);
        incluir_vertice_lista_adjacencia(&vertices[a],b);
        // incluir_vertice_lista_adjacencia(&vertices[b],a);
    }

    printf("Lista da Adjacencia: \n");
    for(i=1;i<=qtd_vertices;i++)
    {
        printf("Vertice: %d -> ",i);
        mostrar_lista(vertices[i].adj);
        printf("\n");
    }

    printf("DFS: ");
    dfs(1,vertices);

    return 0;
}

void dfs(int raiz , vertice * vertices)
{
    printf("%d ",raiz);
    vertices[raiz].visitado = 1;

    registro * aux;
    aux = vertices[raiz].adj->inicio;

    while(aux!=NULL)
    {
        if (vertices[aux->valor].visitado == 0)
        {
            dfs(aux->valor,vertices);
        }
        aux = aux->prox;
    }

}

void incluir_vertice_lista_adjacencia(vertice *v, int valor)
{
    if (v->adj == NULL)
    {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if (v->adj->inicio == NULL)
    {
        v->adj->inicio = novo;
        v->adj->final = novo;
    }
    else
    {
        v->adj->final->prox = novo;
        v->adj->final = novo;
    }
}

lista *aloca_lista()
{
    lista *novo = (lista *)calloc(sizeof(lista), 1);
    return novo;
}

registro *aloca_registro()
{
    registro *novo = (registro *)calloc(sizeof(registro), 1);
    return novo;
}

void incluir_final(lista *l, int x)
{
    if (l == NULL)
    {
        printf("\n Lista Nula");
        return;
    }

    registro *novo;

    novo = aloca_registro();
    novo->valor = x;
    novo->prox = NULL;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->final = novo;
    }
    else
    {
        l->final->prox = novo;
        l->final = novo;
    }
}

void mostrar_lista(lista *l)
{

    registro *aux;
    if (l == NULL)
    {
        return ;
    }

    if (l->inicio == NULL)
    {
        return ;
    }

    aux = l->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}
