#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "email.h"

Email email_digitar()
{
    Email a;
    printf("\nDigite a data dd/mm/aaaa:");
    scanf("%d%*c%d%*c%d", &a.dia, &a.mes, &a.ano);
    printf("\nDigite o seu email: ");
    scanf("%s", a.origem);
    printf("\nDigite o destinatario: ");
    scanf("%s", a.destino);
    printf("\nDigite seu texto: ");
    //gets(a.texto);
    scanf("%s", a.texto);
    return a;
}

void email_imprimir(Email *a)
{
    system("CLS");
    printf("\n#####################################################\n\n\tData: %d\/%d\/%d", a->dia, a->mes, a->ano);
    printf("\nEmail de:%s\nPara:%s", a->origem, a->destino);
    printf("\nTexto:\n%s\n\n", a->texto);
    system("PAUSE");
 }

Email* lista_cria()
{
    return NULL;
}

int lista_vazia(Email* a){
    if(a==NULL) return 1;
    else return 0;
}

Email* email_insere(Email*a, Email*b)
{
    Email* ant=NULL;
    Email* p;
    Email* novo;
    p=a;
    int bdi, pdi;
    bdi = b->ano * 10000 + b->mes * 100 + b->dia;
    if (p != NULL) pdi = p->ano * 10000 + p->mes * 100 + p->dia;
    while(p != NULL && pdi < bdi)
    {
         ant = p;
         p = p->prox;
         //if (p != NULL) pdi = p->ano * 10000 + p->mes * 100 + p->dia;
    }
    novo=(Email*)malloc(sizeof(Email));
    novo->ano=b->ano;
    novo->mes=b->mes;
    novo->dia=b->dia;
    strcpy(novo->origem, b->origem);
    strcpy(novo->destino, b->destino);
    strcpy(novo->texto, b->texto);
    //novo->prox=b->prox;
    if (ant==NULL)
    {
        novo->prox=a;
        a=novo;
    }
    else
    {
        novo->prox=ant->prox;
        ant->prox=novo;
    }
    return a;
}

Email* email_retira(Email* l, int d, int m, int a)
{
    Email* ant=NULL;
    Email* p=l;
    int bdi, pdi;
    bdi = a * 10000 + m * 100 + d ;
    while (p!=NULL && (p->ano * 10000 + p->mes * 100 + p->dia)!=bdi)
    {
        ant=p;
        p=p->prox;
    }
    if(p == NULL) return l;
    if (ant == NULL)
    {
        l=p->prox;
    }
    else
     {
         ant->prox = p->prox;
     }
    free(p);
    return l;
}

void email_imprime (Email *l){
    Email* p;
    for (p=l; p!=NULL; p=p->prox){
            printf("\nDestino:%s\tData:%d/%d/%d", p->destino, p->dia, p->mes, p->ano);
        }
}

void email_localiza(Email* l, int b, int c, int d){
    Email* p;
    int bdi;
    bdi = d * 10000 + c * 100 + b;
    for(p=l ; p!=NULL ; p=p->prox){
        if((p->ano * 10000 + p->mes * 100 + p->dia)==bdi)
        email_imprimir(p);
    }
}

int email_existe(Email* a, int b, int c, int d){
    Email* p;
    int bdi;
    bdi = d * 10000 + c * 100 + b;
    for(p=a ; p!=NULL ; p=p->prox){
        if((p->ano * 10000 + p->mes * 100 + p->dia)==bdi)
        return 1;
    }
    return 0;
}
