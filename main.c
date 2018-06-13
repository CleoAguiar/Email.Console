#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "email.h"

int main()
{
    Email* lista, *del;
    Email aux;
    int i, a, dia, mes, ano, existe, vazia, sair;
    char* conf[1], esc;
    lista=lista_cria();
    //desenvolvendo o programa
    while (a!=0)
    {
        printf ("\n\tEmail\n\n1-Escrever email\n2-Remover email\n3-Listar emails\n4-Localizar email\n0-Sair\n\nEscolha entre as opcoes:");
        scanf ("%d", &a);
        if (a==1)//Escrever email
        {
            system("cls");
            printf("\tNovo email [esc sair]\n");
            printf("\n");
            esc=getch();
            if (esc!=27){
            system("CLS");
            printf("\tNovo email\n");
            printf("\n");
            aux=email_digitar();
            lista=email_insere(lista, &aux);
            printf("\n\nEmails existentes\n");
            email_imprime(lista);
            printf("\n\n");
            system("PAUSE");
            system("CLS");
            }
        }
        if (a==2)//Remover email
        {
            system("CLS");
            vazia=lista_vazia(lista);
            if (vazia==1) {
            printf("\n\tQue pena voce ainda nao enviou nenhum email\n\n");
            system("PAUSE");
            }
            else {
                printf("\tEmails [esc sair]\n");
                email_imprime(lista);
                printf("\n");
                esc=getch();
                if (esc!=27){
                system("CLS");
                printf("\tEmails\n");
                email_imprime(lista);
                printf("\n");
                printf("\n\nDigite a data:");
                scanf("%d%*c%d%*c%d", &dia, &mes, &ano);
                existe=email_existe(lista, dia, mes, ano);
                if (existe==1){
                system("CLS");
                printf("\nDeseja realmente remover este item [s/n]: ");
                scanf("%s", conf);
                if ( strcmp(conf, "s") == 0){
                del=email_retira(lista, dia, mes, ano);
                printf("\n\tREMOVIDO COM SUCESSO!\n\n");
                printf("\n\nEmails existentes\n");
                email_imprime(lista);
                printf("\n\n");
                system("PAUSE");
                }
                }
                }
            }
        }
        if (a==3)//Listar email
        {
            system("CLS");
            vazia=lista_vazia(lista);
            if (vazia==1) {
            printf("\n\tQue pena voce ainda nao enviou nenhum email\n\n");
            system("PAUSE");
            }
            else {
            printf("\n\tEmails\n");
            email_imprime(lista);
            printf("\n\n");
            system("PAUSE");
            system("CLS");
            }
        }
        if (a==4)//Localizar email
        {
        system("CLS");
        printf("\tEmails [esc sair]\n");
        email_imprime(lista);
        printf("\n");
        esc=getch();
        if (esc!=27){
        system("CLS");
        printf("\tEmails\n");
        email_imprime(lista);
        printf("\n");
        printf("\n\nDigite a data:");
        scanf("%d%*c%d%*c%d", &dia, &mes, &ano);
        sair=ano * 10000 + mes * 100 + dia;
        if (sair!=0)
        email_localiza(lista, dia, mes, ano);
        }
        }
        system("CLS");
    }
    return 0;
}
