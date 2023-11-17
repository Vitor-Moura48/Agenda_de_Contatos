#include <stdio.h>
#include <strings.h>

// Estrutura de exemplo pra representar um contato na agenda
struct Contato {
    char nome[50];
    char telefone[15];
};

// Remove o contato a partir do nome, eu usei a função "strcasecmp" que ignora maiúsculas e minúsculas na hora de verificar
void removerContato(struct Contato agenda[], int *numContatos, const char *nome) {
    int i, j;
    int encontrado = 0;

    for (i = 0; i < *numContatos; i++) {
        if (strcasecmp(agenda[i].nome, nome) == 0) {
            for (j = i; j < *numContatos - 1; j++) {
                strcpy(agenda[j].nome, agenda[j + 1].nome);
                strcpy(agenda[j].telefone, agenda[j + 1].telefone);
            }
            (*numContatos)--;
            encontrado = 1;
            break;
        }
    }

    // Mensagem para saber se o contato foi encontrado ou não
    if (encontrado) {
        printf("Contato removido com sucesso.\n");
    } else {
        printf("Contato não encontrado.\n");
    }
}
