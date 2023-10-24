# include <stdio.h>
# include <stdlib.h>
# include <conio.h>


typedef struct contato {
    int numero;
    char nome[50];
    char endereco[50];
    struct contato* prox;
    struct contato* ant;
}contato;

typedef struct lista_contatos {
    contato* inicio;
    contato* fim;
}lista;


void continuar()
{
    printf("\n\ncontinuar <espaco>");
    while (getchar() == '\n');

}


void adicionar_contato(lista* lista_contatos)
{
    contato* novo_contato = (contato*)malloc(sizeof(contato));
    novo_contato->prox = NULL;
    novo_contato->ant = NULL;
    contato* contato_atual = lista_contatos->inicio;

    printf("Digite o numero: ");
    scanf_s("%d", &novo_contato->numero);

    getchar();
    printf("Digite o nome: ");
    fgets(novo_contato->nome, sizeof(novo_contato->nome), stdin);

    printf("Digite o endereco: ");
    fgets(novo_contato->endereco, sizeof(novo_contato->endereco), stdin);

    if (lista_contatos->inicio == NULL)
    {
        lista_contatos->inicio = novo_contato;
        lista_contatos->fim = novo_contato;
    }
    else
    {

        if (lista_contatos->inicio->numero > novo_contato->numero)
        {
            novo_contato->prox = lista_contatos->inicio;
            lista_contatos->inicio->ant = novo_contato;
            lista_contatos->inicio = novo_contato;

        }
        else if (lista_contatos->fim->numero < novo_contato->numero)
        {
            novo_contato->ant = lista_contatos->fim;
            lista_contatos->fim->prox = novo_contato;
            lista_contatos->fim = novo_contato;
        }

        else
        {
            for (; novo_contato->numero > contato_atual->prox->numero && contato_atual->prox != NULL;)
            {
                contato_atual = contato_atual->prox;
            }
            novo_contato->prox = contato_atual->prox;
            novo_contato->ant = contato_atual;

            contato_atual->prox = novo_contato;
            contato_atual->prox->ant = novo_contato;
        }
    }
}


void imprimir_contatos(lista* lista_contatos)
{
    for (contato* contato_atual = lista_contatos->inicio; contato_atual != NULL; contato_atual = contato_atual->prox)
    {
        printf("numero->%d \nnome->%s \nendereco->%s  ", contato_atual->numero, contato_atual->nome, contato_atual->endereco);
    }
}


int main()
{
    lista* lista_contatos = (lista*)malloc(sizeof(lista));
    lista_contatos->inicio = NULL;

    int opcoes = 1;

    printf("§§§§ Bem Vindo ao Sistema de Agenda de Contatos §§§§\n\n");
    do
    {
        printf("       MENU PRINCIPAL\n");
        printf("=============================\n");
        printf("ADICIONAR CONTATO <1>\n");
        printf("IMPRIMIR CONTATO <2>\n");
        printf("ENCERRAR <0>\n");
        printf("=============================\n");

        printf("*Escolha um dos comandos: ");
        scanf_s("%d", &opcoes);
        system("clear");

        switch (opcoes)
        {
        case 1: adicionar_contato(lista_contatos);
            system("clear");
            printf("<Contato adicionado>");
            continuar();
            system("clear");
            break;

        case 2: imprimir_contatos(lista_contatos);
            continuar();
            system("clear");
            break;
        }

    } while (opcoes != 0);

    return 0;
}
