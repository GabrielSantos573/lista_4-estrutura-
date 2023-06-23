#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int idade;
    char telefone[15];
    char produtoComprado[90];
} Cliente;

typedef struct {
    char marca[45];
    char UF[3];
    char site[45];
    int tel;
    int codigo;
} Fabricante;

typedef struct {
    Fabricante fabricante;
    char descricao[90];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
} Produto;

void le_valida_fabricante(Produto produto[], int index);
void le_valida_produto(Produto produto[], int index, int index2);
void lista_produto(Produto produto[], int cont2);
void lista_produtos_por_lucro(Produto produto[], int cont2);
void cadastra_cliente(Cliente clientes[], int *contClientes);
void listar_clientes(Cliente clientes[], int contClientes);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Produto produto[50];
    Cliente clientes[50];
    int contClientes = 0;

    int opc = 0, opc2 = 0, cont = 0, cont2 = 0;
    char parar, parar2;

    do {
        system("cls");

        printf("CADASTRO (FABRICANTE/PRODUTO)(1)");
        printf("\nLISTAR PRODUTOS POR VALOR CRESCENTE(3)");
        printf("\nLISTAR PRODUTOS POR LUCRO(4)");
        printf("\nCADASTRAR NOVO CLIENTE(5)");
        printf("\nLISTAR CLIENTES(6)");
        printf("\nSAIR (0)\n");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                do {
                    system("cls");

                    printf("CADASTRAR UM FABRICANTE (1)");
                    printf("\nCADASTRAR UM PRODUTO (2)");
                    printf("\nSAIR (0)\n");
                    scanf("%d", &opc2);

                    switch (opc2) {
                        case 1:
                            do {
                                system("cls");

                                fflush(stdin);
                                le_valida_fabricante(produto, cont);

                                if (cont > 0) {
                                    printf("Deseja parar com 2 fabricantes? (s/n): ");
                                    scanf(" %c", &parar);
                                    if (parar == 's') {
                                        cont++;
                                        break;
                                    }
                                    break;
                                }
                                cont++;
                                system("cls");
                            } while (cont != 4 || parar == 's');
                            break;

                        case 2:
                            do {
                                system("cls");

                                le_valida_produto(produto, cont2, cont);

                                if (cont2 > 1) {
                                    printf("Deseja parar com 5 produtos? (s/n): ");
                                    scanf(" %c", &parar2);
                                    if (parar2 == 's') {
                                        cont2++;
                                        break;
                                    }
                                    break;
                                }
                                cont2++;
                                system("cls");
                            } while (cont2 != 50 || parar2 == 's');
                            break;

                        case 0:
                            break;
                    }
                } while (opc2 != 0);
                break;

            case 2:
                

            case 3:
                lista_produto_valor(produto, cont2);
                printf("\n");
                system("pause");
                break;

            case 4:
                lista_produtos_por_lucro(produto, cont2);
                printf("\n");
                system("pause");
                break;

            case 5:
                cadastra_cliente(clientes, &contClientes);
                system("pause");
                break;
            
            case 6:
                listar_clientes(clientes, contClientes);
                system("pause");
                break;
        }

    } while (opc != 0);

    return 0;
}

void le_valida_fabricante(Produto produto[], int index) {
	
	int tam=0;
	do {
		printf("Nome da marca: ");
	    fflush(stdin);
	    scanf(" %[^\n]s", produto[index].fabricante.marca);
	    
	    tam=strlen(produto[index].fabricante.marca);
	}while(tam<3);
    
    
    printf("Código do fabricante: ");
    scanf("%d", &produto[index].fabricante.codigo);

    printf("Site (ex: whatsapp.com): ");
    fflush(stdin);
    scanf(" %[^\n]s", produto[index].fabricante.site);

    printf("Telefone (123456789): ");
    scanf("%d", &produto[index].fabricante.tel);

    printf("UF (ex: DF): ");
    fflush(stdin);
    scanf(" %[^\n]s", produto[index].fabricante.UF);
}

void le_valida_produto(Produto produto[], int index, int index2) {
    printf("Descreva seu produto: ");
    fflush(stdin);
    scanf(" %[^\n]s", produto[index].descricao);

    printf("Peso (kg): ");
    scanf("%f", &produto[index].peso);

    printf("Valor de compra (R$): ");
    scanf("%f", &produto[index].valorCompra);

    printf("Valor de venda (R$): ");
    scanf("%f", &produto[index].valorVenda);
    
    int i=0;
    
    for(i=0; i<index2; i++){
    	printf("Fabricante:%s", produto[i].fabricante.marca);
    	printf("Codigo Fabricante:%s", produto[i].fabricante.marca);
	}

    produto[index].valorLucro = produto[index].valorVenda - produto[index].valorCompra;
}

void lista_produto_valor(Produto produto[], int cont2) {
    int j;
    printf("PRODUTOS:\n");
    for (j = 0; j < cont2; j++) {
        printf("\nDescrição: %s\n", produto[j].descricao);
        printf("Fabricante: %s\n", produto[j].fabricante.marca);
        printf("Peso: %.2f kg\n", produto[j].peso);
        printf("Valor de compra: R$ %.2f\n", produto[j].valorCompra);
        printf("Valor de venda: R$ %.2f\n", produto[j].valorVenda);
        printf("Valor do lucro: R$ %.2f\n", produto[j].valorLucro);
    }
}

void lista_produtos_por_lucro(Produto produto[], int cont2) {
    int i, j;
    Produto temp;

    for (i = 0; i < cont2 - 1; i++) {
        for (j = 0; j < cont2 - i - 1; j++) {
            if (produto[j].valorLucro > produto[j + 1].valorLucro) {
                temp = produto[j];
                produto[j] = produto[j + 1];
                produto[j + 1] = temp;
            }
        }
    }

    printf("PRODUTOS ORDENADOS POR LUCRO:\n");
    for (i = 0; i < cont2; i++) {
        printf("\nDescrição: %s\n", produto[i].descricao);
        printf("Fabricante: %s\n", produto[i].fabricante.marca);
        printf("Peso: %.2f kg\n", produto[i].peso);
        printf("Valor de compra: R$ %.2f\n", produto[i].valorCompra);
        printf("Valor de venda: R$ %.2f\n", produto[i].valorVenda);
        printf("Valor do lucro: R$ %.2f\n", produto[i].valorLucro);
    }
}

void cadastra_cliente(Cliente clientes[], int *contClientes) {
    if (*contClientes >= 50) {
        printf("Limite de clientes cadastrados atingido.\n");
        return;
    }

    Cliente novoCliente;

    printf("CADASTRO DE NOVO CLIENTE:\n");
    printf("Nome: ");
    fflush(stdin);
    scanf(" %[^\n]s", novoCliente.nome);

    printf("Idade: ");
    scanf("%d", &novoCliente.idade);

    printf("Telefone: ");
    fflush(stdin);
    scanf(" %[^\n]s", novoCliente.telefone);

    printf("Produto comprado: ");
    fflush(stdin);
    scanf(" %[^\n]s", novoCliente.produtoComprado);

    clientes[*contClientes] = novoCliente;
    (*contClientes)++;

    printf("Cliente cadastrado com sucesso!\n");
}

void listar_clientes(Cliente clientes[], int contClientes) {
    int i;
    printf("CLIENTES CADASTRADOS:\n");
    for (i = 0; i < contClientes; i++) {
        printf("\nNome: %s\n", clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Produto comprado: %s\n", clientes[i].produtoComprado);
    }
}
