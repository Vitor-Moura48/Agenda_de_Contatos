# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <string.h>

typedef struct contato {
    char nome[50];
    int numero;
    char endereco[50];
    char email[50];
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

    getchar();
    printf("Digite o nome: ");
    fgets(novo_contato->nome, sizeof(novo_contato->nome), stdin);
    novo_contato->nome[strcspn(novo_contato->nome, "\n")] = '\0';

    printf("Digite o numero: ");
    scanf_s("%d", &novo_contato->numero);

    getchar();
    printf("Digite o endereco residencial: ");
    fgets(novo_contato->endereco, sizeof(novo_contato->endereco), stdin);
    novo_contato->endereco[strcspn(novo_contato->endereco, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(novo_contato->email, sizeof(novo_contato->email), stdin);
    novo_contato->email[strcspn(novo_contato->email, "\n")] = '\0';

    if (lista_contatos->inicio == NULL)
    {
        lista_contatos->inicio = novo_contato;
        lista_contatos->fim = novo_contato;
    }
    else
    {

        if (strcmp(novo_contato->nome, lista_contatos->inicio->nome) < 0)
        {
            novo_contato->prox = lista_contatos->inicio;
            lista_contatos->inicio->ant = novo_contato;
            lista_contatos->inicio = novo_contato;

        }
        else if (strcmp(novo_contato->nome, lista_contatos->fim->nome) > 0)
        {
            novo_contato->ant = lista_contatos->fim;
            lista_contatos->fim->prox = novo_contato;
            lista_contatos->fim = novo_contato;
        }

        else
        {
            for (; strcmp(novo_contato->nome, contato_atual->prox->nome) > 0 && contato_atual->prox != NULL;)
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

void achar_contato(lista* lista_contatos) {
    getchar();

    char busca_nome[50];
    printf("Digite o nome do contato a ser buscado: ");
    fgets(busca_nome, sizeof(busca_nome), stdin);

    busca_nome[strcspn(busca_nome, "\n")] = '\0';

    contato* contato_atual = lista_contatos->inicio;
    int achou = 0;

    while (contato_atual != NULL) {
        if (strcmp(busca_nome, contato_atual->nome) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", contato_atual->nome);
            printf("Numero: %d\n", contato_atual->numero);
            printf("Endereço: %s\n", contato_atual->endereco);
            printf("Email: %s\n", contato_atual->email);
            achou = 1;
            break;
        }
        contato_atual = contato_atual->prox;
    }

    if (!achou) {
        printf("Contato nao encontrado.\n");
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
        printf("PROCURAR CONTATO <3>\n");
        printf("ENCERRAR <0>\n");
        printf("=============================\n");

        printf("*Escolha um dos comandos: ");
        scanf_s("%d", &opcoes);
        system("cls");

        switch (opcoes)
        {
        case 1: adicionar_contato(lista_contatos);
            system("cls");
            printf("<Contato adicionado>");
            continuar();
            system("cls");
            break;

        case 2: imprimir_contatos(lista_contatos);
            continuar();
            system("cls");
            break;

        case 3: achar_contato(lista_contatos);
            continuar();
            system("cls");
            break;
        }

    } while (opcoes != 0);

    return 0;
}
