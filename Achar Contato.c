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
