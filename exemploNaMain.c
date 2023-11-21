#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do contato
struct Contato {
    char nome[50];
    char telefone[15];
    struct Contato* proximo;
};

// Função principal
void removerContato(struct Contato** lista, char nome[]) {
    struct Contato* atual = *lista;
    struct Contato* anterior = NULL;

    while (atual != NULL && strcasecmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Contato com o nome %s nao encontrado.\n", nome);
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    // Libera a memória do nó removido
    free(atual);

    printf("Contato com o nome %s removido com sucesso.\n", nome);
}

// Função de teste pra imprimir lista de contatos
void imprimirLista(struct Contato* lista) {
    while (lista != NULL) {
        printf("Nome: %s, Telefone: %s\n", lista->nome, lista->telefone);
        lista = lista->proximo;
    }
}

// Função pra liberar a memória alocada na lista
void liberarLista(struct Contato* lista) {
    while (lista != NULL) {
        struct Contato* temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}

// Main pra testar a remoção de contatos
int main() {
    struct Contato* lista = NULL;

    // Adiciona alguns contatos à lista (apenas para exemplo)
    struct Contato* contato1 = (struct Contato*)malloc(sizeof(struct Contato));
    strcpy(contato1->nome, "Joao");
    strcpy(contato1->telefone, "123456789");
    contato1->proximo = NULL;

    struct Contato* contato2 = (struct Contato*)malloc(sizeof(struct Contato));
    strcpy(contato2->nome, "Maria");
    strcpy(contato2->telefone, "987654321");
    contato2->proximo = NULL;

    contato1->proximo = contato2;
    lista = contato1;

    printf("Lista antes da remocao:\n");
    imprimirLista(lista);

    removerContato(&lista, "Joao");

    printf("\nLista apos a remocao:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}
