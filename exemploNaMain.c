#include <stdio.h>
#include <strings.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

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

    if (encontrado) {
        printf("Contato removido com sucesso.\n");
    } else {
        printf("Contato não encontrado.\n");
    }
}


// Exemplo para usar a função, infelizmente eu não sei como vai ficar com o menu
int main() {
    struct Contato agenda[100];
    int numContatos = 3;

    strcpy(agenda[0].nome, "Joao");
    strcpy(agenda[0].telefone, "123456789");
    strcpy(agenda[1].nome, "Maria");
    strcpy(agenda[1].telefone, "987654321");
    strcpy(agenda[2].nome, "Carlos");
    strcpy(agenda[2].telefone, "555555555");

    removerContato(agenda, &numContatos, "maria");

    printf("Agenda após a remoção:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("Nome: %s, Telefone: %s\n", agenda[i].nome, agenda[i].telefone);
    }

    return 0;
}
