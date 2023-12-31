# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <string.h>
# include <windows.h>

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
        HANDLE informacoes_console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(informacoes_console, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("\nContato nao encontrado.\n");
        SetConsoleTextAttribute(informacoes_console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
        HANDLE informacoes_console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(informacoes_console, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("Contato com o nome %s nao encontrado.\n", busca_nome);
        SetConsoleTextAttribute(informacoes_console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        return;
    }

    if (anterior == NULL) {
        lista_contatos->inicio = atual->prox;
        if (lista_contatos->inicio != NULL) {
            lista_contatos->inicio->ant = NULL;
        }
        else {
            lista_contatos->fim = NULL;
        }
    }
    else {
        anterior->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = anterior;
        }
        else {
            lista_contatos->fim = anterior;
        }
    }

    free(atual);

    printf("Contato com o nome %s removido com sucesso.\n", busca_nome);
}

contato* achar_contatos(lista* lista_contatos, const char* busca_nome) {
    contato* contato_atual = lista_contatos->inicio;
    while (contato_atual != NULL) {
        if (strcmp(busca_nome, contato_atual->nome) == 0) {
            return contato_atual; // Contato encontrado
        }
        contato_atual = contato_atual->prox;
    }
    return NULL; // Contato não encontrado
}

void editar_contato(lista* lista_contatos) {
    getchar(); //limpar caractere
    char busca_nome[50];
    printf("Digite o nome do contato a ser editado: ");
    fgets(busca_nome, sizeof(busca_nome), stdin);
    busca_nome[strcspn(busca_nome, "\n")] = '\0';
    contato* contato_encontrado = achar_contatos(lista_contatos, busca_nome);
    if (contato_encontrado != NULL) {
        // Contato encontrado
        printf("Digite os novos dados para o contato:\n");
        printf("Novo Nome: ");
        fgets(contato_encontrado->nome, sizeof(contato_encontrado->nome), stdin);
        contato_encontrado->nome[strcspn(contato_encontrado->nome, "\n")] = '\0';

        printf("Novo Numero: ");
        scanf_s("%d", &contato_encontrado->numero);

        getchar(); // limpar caractere

        printf("Novo Endereco: ");
        fgets(contato_encontrado->endereco, sizeof(contato_encontrado->endereco), stdin);
        contato_encontrado->endereco[strcspn(contato_encontrado->endereco, "\n")] = '\0';

        printf("Novo Email: ");
        fgets(contato_encontrado->email, sizeof(contato_encontrado->email), stdin);
        contato_encontrado->email[strcspn(contato_encontrado->email, "\n")] = '\0';

        printf("Contato editado com sucesso.\n");
    }
    else {
        printf("Contato nao encontrado.\n");
    }
}

void salvar_contatos(lista* lista_contatos, const char* nome_arquivo) {
    FILE* arquivo;
    if (fopen_s(&arquivo, nome_arquivo, "wb") != 0) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    contato* contato_atual = lista_contatos->inicio;
    while (contato_atual != NULL) {
        fwrite(contato_atual, sizeof(contato), 1, arquivo);
        contato_atual = contato_atual->prox;
    }

    fclose(arquivo);
}

void carregar_contatos(lista* lista_contatos, const char* nome_arquivo) {
    FILE* arquivo;
    if (fopen_s(&arquivo, nome_arquivo, "rb") != 0) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    contato novo_contato;
    while (fread(&novo_contato, sizeof(contato), 1, arquivo) == 1) {
        contato* novo = (contato*)malloc(sizeof(contato));
        *novo = novo_contato;
        novo->prox = NULL;
        novo->ant = NULL;

        if (lista_contatos->inicio == NULL) {
            lista_contatos->inicio = novo;
            lista_contatos->fim = novo;
        }
        else {
            lista_contatos->fim->prox = novo;
            novo->ant = lista_contatos->fim;
            lista_contatos->fim = novo;
        }
    }

    fclose(arquivo);
}

int main()
{
    HANDLE informacoes_console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(informacoes_console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    lista* lista_contatos = (lista*)malloc(sizeof(lista));
    lista_contatos->inicio = NULL;

    int opcoes = 1;

    const char* nome_arquivo = "contatos.dat";

    carregar_contatos(lista_contatos, nome_arquivo);

    do
    {
        system("cls");
        printf("                              §§§§ Bem Vindo ao Sistema de Agenda de Contatos §§§§\n\n");
        printf("                                                     MENU PRINCIPAL\n");
        printf("                                             ===========================\n");
        printf("                                             [1]    ADICIONAR CONTATO \n");
        printf("                                             [2]    IMPRIMIR CONTATO  \n");
        printf("                                             [3]    PROCURAR CONTATO  \n");
        printf("                                             [4]    REMOVER CONTATO   \n");
        printf("                                             [5]    EDITAR CONTATO   \n");
        printf("                                             [0]    ENCERRAR SISTEMA  \n");
        printf("                                             ===========================\n");

        printf("\n                                             *Escolha um dos comandos: ");
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
            removerContato(lista_contatos);
            system("pause");
            break;
        case 5:
            system("cls");
            editar_contato(lista_contatos);
            system("pause");
            break;
        }

        salvar_contatos(lista_contatos, nome_arquivo);

    } while (opcoes != 0);

    return 0;
}
