#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 10
// Variáveis globais
int codigos[MAX_PRODUTOS];
char nomes[MAX_PRODUTOS][100];
float precos[MAX_PRODUTOS];
int numProdutos = 0;

void adicionarProduto() {
    int codigo;
    char nome[100];
    float preco;

    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    printf("Digite o nome do produto: ");
    fflush(stdin);
    gets(nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &preco);

    codigos[numProdutos] = codigo;
    strcpy(nomes[numProdutos], nome);
    precos[numProdutos] = preco;
    numProdutos++;

    printf("Produto adicionado com sucesso!\n");
}


void listarProdutos() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("---- Lista de Produtos ----\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Código: %d\n", codigos[i]);
        printf("Nome: %s\n", nomes[i]);
        printf("Preço: R$%.2f\n", precos[i]);
        printf("---------------------------\n");
    }
}


void buscarProduto() {
    int codigo;

    printf("Digite o código do produto a ser buscado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < numProdutos; i++) {
        if (codigos[i] == codigo) {
            printf("---- Informações do Produto ----\n");
            printf("Código: %d\n", codigos[i]);
            printf("Nome: %s\n", nomes[i]);
            printf("Preço: R$%.2f\n", precos[i]);
            printf("---------------------------------\n");
            return;
        }
    }

    printf("Produto não encontrado.\n");
}


void excluirProduto(){// função extra para estudarem
    int codigo;
    int indice = -1;

    printf("Digite o código do produto a ser excluído: ");
    scanf("%d", &codigo);

    for (int i = 0; i < numProdutos; i++) {
        if (codigos[i] == codigo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    // Deslocar os produtos seguintes para preencher o espaço vazio
    for (int i = indice; i < numProdutos - 1; i++) {
        codigos[i] = codigos[i + 1];
        strcpy(nomes[i], nomes[i + 1]);
        precos[i] = precos[i + 1];
    }

    numProdutos--;

    printf("Produto excluído com sucesso!\n");
}


void menuPrincipal() {
    int opcao;

    do {
        printf("----- MENU -----\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto\n");
        printf("4. Excluir Produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                buscarProduto();
                break;
            case 4:
                excluirProduto();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 5);
}


int main() {
    menuPrincipal();
    return 0;
}

