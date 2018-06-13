#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

struct email {
    char origem[10];
    char destino[10];
    char texto[10];
    int dia;
    int mes;
    int ano;
    struct email* prox;
};

typedef struct email Email;
Email email_digitar();
void email_imprimir(Email* a);

Email* lista_cria();
int lista_vazia(Email* a);
Email* email_insere(Email*a, Email*b);

Email* email_retira(Email* a, int b, int c, int d);
void email_imprime (Email* a);

void email_localiza(Email* a, int b, int c, int d);
int email_existe(Email* a, int b, int c, int d);

#endif // EMAIL_H_INCLUDED
