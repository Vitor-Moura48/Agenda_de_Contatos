contato* achar_contato(lista* lista_contatos, const char* busca_nome) {
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
    contato* contato_encontrado = achar_contato(lista_contatos, busca_nome);
    if (contato_encontrado != NULL) {
        // Contato encontrado
        printf("Digite os novos dados para o contato:\n");
        printf("Novo Nome: ");
        fgets(contato_encontrado->nome, sizeof(contato_encontrado->nome), stdin);
        contato_encontrado->nome[strcspn(contato_encontrado->nome, "\n")] = '\0';

        printf("Novo Numero: ");
        scanf("%d", &contato_encontrado->numero);

        getchar(); // limpar caractere

        printf("Novo Endereco: ");
        fgets(contato_encontrado->endereco, sizeof(contato_encontrado->endereco), stdin);
        contato_encontrado->endereco[strcspn(contato_encontrado->endereco, "\n")] = '\0';

        printf("Novo Email: ");
        fgets(contato_encontrado->email, sizeof(contato_encontrado->email), stdin);
        contato_encontrado->email[strcspn(contato_encontrado->email, "\n")] = '\0';

        printf("Contato editado com sucesso.\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}

