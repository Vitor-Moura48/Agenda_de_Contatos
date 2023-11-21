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
