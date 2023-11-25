#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do contato
struct Contato {
    char nome[50];
    char telefone[15];
    struct Contato* proximo;
};

// Função para adicionar um novo contato à lista
void adicionarContato(struct Contato** lista, char nome[], char telefone[]) {
    struct Contato* novoContato = (struct Contato*)malloc(sizeof(struct Contato));
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->telefone, telefone);
    novoContato->proximo = *lista;
    *lista = novoContato;
    printf("Contato adicionado com sucesso!\n");
}

// Função para exibir todos os contatos na lista
void exibirContatos(struct Contato* lista) {
    printf("Lista de contatos:\n");
    while (lista != NULL) {
        printf("Nome: %s\nTelefone: %s\n\n", lista->nome, lista->telefone);
        lista = lista->proximo;
    }
}

// Função para editar um contato na lista
void editarContato(struct Contato* lista, char nome[]) {
    while (lista != NULL) {
        if (strcmp(lista->nome, nome) == 0) {
            printf("Novo nome para %s: ", nome);
            scanf("%s", lista->nome);
            printf("Novo telefone para %s: ", nome);
            scanf("%s", lista->telefone);
            printf("Contato editado com sucesso!\n");
            return;
        }
        lista = lista->proximo;
    }
    printf("Contato não encontrado.\n");
}

// Função para liberar a memória alocada para a lista de contatos
void liberarLista(struct Contato* lista) {
    struct Contato* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}

int main() {
    struct Contato* lista = NULL;
    int opcao;
    char nome[50];

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Exibir Contatos\n");
        printf("3. Editar Contato\n");
        printf("4. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                {
                    char novoNome[50], novoTelefone[15];
                    printf("Nome do novo contato: ");
                    scanf("%s", novoNome);
                    printf("Telefone do novo contato: ");
                    scanf("%s", novoTelefone);
                    adicionarContato(&lista, novoNome, novoTelefone);
                    break;
                }
            case 2:
                exibirContatos(lista);
                break;
            case 3:
                printf("Nome do contato a ser editado: ");
                scanf("%s", nome);
                editarContato(lista, nome);
                break;
            case 4:
                liberarLista(lista);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

