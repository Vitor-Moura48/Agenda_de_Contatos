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
    printf("                    ================================\n");
    printf("                            LISTA DE CONTATOS\n");
    printf("                    ================================\n");

    printf("Descricao\n");
    printf("=================================================================\n\n");
    for (contato* contato_atual = lista_contatos->inicio; contato_atual != NULL; contato_atual = contato_atual->prox)
    {   
        printf("NOME      : %s \nNUMERO    : %d \nEndereco  : %s  \nEmail     : %s\n\n", contato_atual->nome, contato_atual->numero, contato_atual->endereco, contato_atual->email);
        printf("=================================================================\n");
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
            printf("\nContato encontrado:\n\n");
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
        printf("\nContato nao encontrado.\n");
    }
}

void removerContato(lista* lista_contatos) {
    getchar();

    char busca_nome[50];
    printf("Digite o nome do contato a ser removido: ");
    fgets(busca_nome, sizeof(busca_nome), stdin);
    busca_nome[strcspn(busca_nome, "\n")] = '\0';

    contato* atual = lista_contatos->inicio;
    contato* anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, busca_nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato com o nome %s nao encontrado.\n", busca_nome);
        return;
    }

    if (anterior == NULL) {
        lista_contatos->inicio = atual->prox;
        if (lista_contatos->inicio != NULL) {
            lista_contatos->inicio->ant = NULL;
        } else {
            lista_contatos->fim = NULL;
        }
    } else {
        anterior->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = anterior;
        } else {
            lista_contatos->fim = anterior;
        }
    }

    free(atual);

    printf("Contato com o nome %s removido com sucesso.\n", busca_nome);
}

int main()
{
    lista* lista_contatos = (lista*)malloc(sizeof(lista));
    lista_contatos->inicio = NULL;

    int opcoes = 1;

   
    do
    {   
        system("cls");
        printf("§§§§ Bem Vindo ao Sistema de Agenda de Contatos §§§§\n\n");
        printf("     MENU PRINCIPAL\n");
        printf("======================\n");
        printf("[1] ADICIONAR CONTATO\n");
        printf("[2] IMPRIMIR CONTATO\n");
        printf("[3] PROCURAR CONTATO\n");
        printf("[4] REMOVER CONTATO\n");
        printf("[0] ENCERRAR\n");
        printf("=====================\n");

        printf("*Escolha um dos comandos: ");
        scanf_s("%d", &opcoes);
        system("cls");

        switch (opcoes)
        {
        case 1: 
            system("cls");
            adicionar_contato(lista_contatos);
            printf("*Contato adicionado*\n");
            system("pause");
            break;

        case 2: 
            system("cls");
            imprimir_contatos(lista_contatos);
            system("pause");
            break;

        case 3: 
            system("cls");
            achar_contato(lista_contatos);
            system("pause");
            break;

        case 4: 
            system("cls");
            removerContato(lista_contatos, "pedro");;
            system("pause");
            break;
    }

    } while (opcoes != 0);

    return 0;
}
