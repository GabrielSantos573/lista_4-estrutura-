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

typedef struct{
	char sigla[3];
	char nome[25];
}UF;


typedef struct {
	UF uf;
    char marca[45];
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

void le_valida_fabricante_produto(Produto produto[], int index);
void lista_produto_valor(Produto produto[], int cont);
void lista_produtos_por_lucro(Produto produto[], int cont);
void cadastra_cliente(Cliente clientes[], int *contClientes);
void listar_clientes(Cliente clientes[], int contClientes);
void lista_produtoFabricante(Produto produto[], int index);
void pesquisaValorMaior(Produto produto[], int index);
void pesquisaValorMenor(Produto produto[], int index);
void pesquisaClienteIdade(Cliente clientes[], int contClientes);
void pesquisaValorBuscaBinaria(Produto produto[], int index);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Produto produto[50];
    Cliente clientes[50];
    UF uf;
    int contClientes = 0;

    int opc = 0, opc2 = 0, cont = 0;
    char parar;

    do {
        system("cls");

        printf("CADASTRO (PRODUTO/FABRICANTE)(1)");
        printf("\nListar os produtos de um determinado fabricante(2)");
        printf("\nPesquisa estado por valor(>=) (3)");
        printf("\nPesquisa estado por valor(<=) (4)");
        printf("\nLISTAR PRODUTOS POR VALOR CRESCENTE(5)");
        printf("\nLISTAR PRODUTOS POR LUCRO(6)");
        printf("\nCADASTRAR NOVO CLIENTE(7)");
        printf("\nLISTAR CLIENTES(8)");
        printf("\nLISTAR CLIENTE COM 60+ (9)");
        printf("\nPESQUISAR PRODUTO POR VALOR(BB) (10)");//BB=BUSCA BINAIRA 
        printf("\nSAIR (0)\n");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
               do {
                	system("cls");

                    fflush(stdin);
                    le_valida_fabricante_produto(&produto, cont);

                    if (cont > 0) {
                    	printf("Deseja parar com 5 produtos? (s/n): ");
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
                lista_produtoFabricante(&produto, cont);
                printf("\n");
                system("pause");
                break;
                
            case 3:
            	pesquisaValorMaior(&produto, cont);
            	printf("\n");
                system("pause");
            	break;
            	
            case 4:
            	pesquisaValorMenor(&produto, cont);
            	printf("\n");
                system("pause");
            	break;

            case 5:
                lista_produto_valor(&produto, cont);
                printf("\n");
                system("pause");
                break;

            case 6:
                lista_produtos_por_lucro(&produto, cont);
                printf("\n");
                system("pause");
                break;

            case 7:
                cadastra_cliente(&clientes, &contClientes);
                system("pause");
                break;
            
            case 8:
                listar_clientes(&clientes, contClientes);
                system("pause");
                break;
            
            case 9:
            	pesquisaClienteIdade(&clientes, contClientes);
            	system("pause");
            	break;
            	
            case 10:
            	pesquisaValorBuscaBinaria(&produto, cont);
            	break;
        }

    } while (opc != 0);

    return 0;
}

void le_valida_fabricante_produto(Produto produto[], int index) {
	
	printf("--------PRODUTO---------");
	printf("\nDescreva seu produto: ");
    fflush(stdin);
    scanf(" %[^\n]s", produto[index].descricao);

    printf("Peso (kg): ");
    scanf("%f", &produto[index].peso);

    printf("Valor de compra (R$): ");
    scanf("%f", &produto[index].valorCompra);

    printf("Valor de venda (R$): ");
    scanf("%f", &produto[index].valorVenda);
    
    produto[index].valorLucro = produto[index].valorVenda - produto[index].valorCompra;
	
	printf("Valor de lucro (R$): %2.f", produto[index].valorLucro);
    
	printf("\n--------FABRICANTE DO PRODUTO---------");
	int tam=0;
	do {
		printf("\nNome da marca: ");
	    fflush(stdin);
	    scanf(" %[^\n]s", produto[index].fabricante.marca);
	    
	    tam=strlen(produto[index].fabricante.marca);
	    
	    if(tam<3){
	    	printf("O nome não pode ter menos que 3 letras.");
		}
	}while(tam<3);
    
    do{
    	printf("\nCódigo do fabricante: ");
    	scanf("%d", &produto[index].fabricante.codigo);
    	
    	if(produto[index].fabricante.codigo < 100000){
	    	printf("O codigo não pode ter menos que 6 digitos.");
		}
	}while(produto[index].fabricante.codigo < 100000);
    

    printf("Site (ex: teste.com): ");
    fflush(stdin);
    scanf(" %[^\n]s", produto[index].fabricante.site);
    
	printf("Telefone ((61) 123456789): ");
	scanf("%d", &produto[index].fabricante.tel);
	    
	fflush(stdin);
	int opcUf=0;
	int loop=0;

	do{
		loop=0;
		printf("\nUF: ");
		printf("\nAcre(1) \nAlagoas(2)	\nAmapá(3) \nAmazonas(4) \nBahia(5)	\nCeará(6)	\nDistrito Federal(7)	\nEspírito Santo(8)	\nGoiás(9)");
		printf("\nMaranhão(10)	\nMato Grosso (11)	\nMato Grosso do Sul (12)	\nMinas Gerais (13)	\nPará (14)	\nParaíba (15)	\nParaná (16)	\nPernambuco (17)");
		printf("\nPiauí(18)	\nRio de Janeiro(19)	\nRio Grande do Norte(20)	\nRio Grande do Sul(21)	\nRondônia(22)  \nRoraima(23)	\nSanta Catarina(24)	\nSão Paulo(25)	\nSergipe(26)	\nTocantins(27)\n");
		scanf("%d", &opcUf);
    	switch(opcUf){
    		case 1:
	    			strcpy(produto[index].fabricante.uf.sigla, "AC");
	    			strcpy(produto[index].fabricante.uf.nome, "Acre");
	    			
	    		break;
	    	case 2:
	    			strcpy(produto[index].fabricante.uf.sigla, "AL");
	    			strcpy(produto[index].fabricante.uf.nome, "Alagoas");
	    		break;
	    	case 3:
	    			strcpy(produto[index].fabricante.uf.sigla, "AP");
	    			strcpy(produto[index].fabricante.uf.nome, "Amapa");
	    		break;
	    	case 4:
	    			strcpy(produto[index].fabricante.uf.sigla, "AM");
	    			strcpy(produto[index].fabricante.uf.nome, "Amazonas");
	    		break;
	    	case 5:
	    			strcpy(produto[index].fabricante.uf.sigla, "BA");
	    			strcpy(produto[index].fabricante.uf.nome, "Bahia");
	    		break;
	    	case 6:
	    			strcpy(produto[index].fabricante.uf.sigla, "CE");
	    			strcpy(produto[index].fabricante.uf.nome, "Ceara");
	    		break;
	    	case 7:
	    			strcpy(produto[index].fabricante.uf.sigla, "DF");
	    			strcpy(produto[index].fabricante.uf.nome, "Distrito Federal");
	    			
	    			printf("%s", produto[index].fabricante.uf.nome);
	    		break;
	    	case 9:
	    			strcpy(produto[index].fabricante.uf.sigla, "GO");
	    			strcpy(produto[index].fabricante.uf.nome, "GOIAS");
	    		break;
	    	case 10:
	    			strcpy(produto[index].fabricante.uf.sigla, "MA");
	    			strcpy(produto[index].fabricante.uf.nome, "MARANHAO");
	    		break;
	    	case 11:
	    			strcpy(produto[index].fabricante.uf.sigla, "MT");
	    			strcpy(produto[index].fabricante.uf.nome, "MATO GROSSO");
	    		break;
	    	case 12:
	    			strcpy(produto[index].fabricante.uf.sigla, "MS");
	    			strcpy(produto[index].fabricante.uf.nome, "MATO GROSSO DO SUL");
	    		break;
	    	case 13:
	    			strcpy(produto[index].fabricante.uf.sigla, "MG");
	    			strcpy(produto[index].fabricante.uf.nome, "MINAS GERAIS");
	    		break;
	    	case 14:
	    			strcpy(produto[index].fabricante.uf.sigla, "PA");
	    			strcpy(produto[index].fabricante.uf.nome, "PARA");
	    		break;
	    	case 15:
	    			strcpy(produto[index].fabricante.uf.sigla, "PB");
	    			strcpy(produto[index].fabricante.uf.nome, "PARAIBA");
	    		break;
	    	case 16:
	    			strcpy(produto[index].fabricante.uf.sigla, "PR");
	    			strcpy(produto[index].fabricante.uf.nome, "PARANA");
	    		break;
	    	case 17:
	    			strcpy(produto[index].fabricante.uf.sigla, "PE");
	    			strcpy(produto[index].fabricante.uf.nome, "PERNAMBUCO");
	    		break;
	    	case 18:
	    			strcpy(produto[index].fabricante.uf.sigla, "PI");
	    			strcpy(produto[index].fabricante.uf.nome, "PIAUI");
	    		break;
	    	case 19:
	    			strcpy(produto[index].fabricante.uf.sigla, "RJ");
	    			strcpy(produto[index].fabricante.uf.nome, "RIO DE JANEIRO");
	    		break;
	    	case 20:
	    			strcpy(produto[index].fabricante.uf.sigla, "RN");
	    			strcpy(produto[index].fabricante.uf.nome, "RIO GRANDE DO NORTE");
	    		break;
	    	case 21:
	    			strcpy(produto[index].fabricante.uf.sigla, "RS");
	    			strcpy(produto[index].fabricante.uf.nome, "RIO GRANDE DO SUL");
	    		break;
	    	case 22:
	    			strcpy(produto[index].fabricante.uf.sigla, "RO");
	    			strcpy(produto[index].fabricante.uf.nome, "RONDONIA");
	    		break;
	    	case 23:
	    			strcpy(produto[index].fabricante.uf.sigla, "RR");
	    			strcpy(produto[index].fabricante.uf.nome, "RORAIMA");
	    		break;
	    	case 24:
	    			strcpy(produto[index].fabricante.uf.sigla, "SC");
	    			strcpy(produto[index].fabricante.uf.nome, "SANTA CATARINA");
	    		break;
	    	case 25:
	    			strcpy(produto[index].fabricante.uf.sigla, "SP");
	    			strcpy(produto[index].fabricante.uf.nome, "SAO PAULO");
	    		break;
	    	case 26:
	    			strcpy(produto[index].fabricante.uf.sigla, "SE");
	    			strcpy(produto[index].fabricante.uf.nome, "SERGIPE");
	    		break;
	    	case 27:
	    			strcpy(produto[index].fabricante.uf.sigla, "TO");
	    			strcpy(produto[index].fabricante.uf.nome, "TOCANTINS");
	    		break;
	    	case 8:
	    			strcpy(produto[index].fabricante.uf.sigla, "ES");
	    			strcpy(produto[index].fabricante.uf.nome, "ESPIRITO SANTO");
	    		break;
	    	default:
	    		printf("Escolha uma das 27 federações existentes");
	    		loop=1;
	    		break;
		}
	    	
	} while(loop!=0);
}

void lista_produtoFabricante(Produto produto[], int index){
	char auxfrabricante[25];
	
	printf("Digite o nome do fabricante para achar um produto: ");
	scanf(" %[^\n]s", &auxfrabricante);
	
	for(int i=0; i<index;i++){
		if(strcmp(auxfrabricante, produto[i].fabricante.marca)==0){
			printf("\nFabricante: %s", produto[i].fabricante.marca);
			printf("\nProduto: %s", produto[i].descricao);
			printf("\nPeso: %.2f Kg", produto[i].peso);
			printf("\nValor compra: R$ %.2f", produto[i].valorCompra);
			printf("\nValor venda: R$ %.2f", produto[i].valorVenda);
			printf("\nValor lucro: R$ %.2f", produto[i].valorLucro);
			break;
		}
	 break;
	}
}

void pesquisaValorMaior(Produto produto[], int index){  //usamos o valor de venda por ser o apresentado ao cliente ja que não foi especificado.
	float auxValor=0;
	
	printf("Digite o valor para achar os estados: ");
	scanf("%f", &auxValor);
	
	for(int i=0; i<index; i++){
		if(produto[i].valorVenda >= auxValor){
			printf("\nEstado: %s", produto[i].fabricante.uf.nome);
		}
	}
	
}

void pesquisaValorMenor(Produto produto[], int index){  
	float auxValor=0;
	
	printf("Digite o valor para achar os estados: ");
	scanf("%f", &auxValor);
	
	for(int i=0; i<index; i++){
		if(produto[i].valorVenda <= auxValor){
			printf("\nEstado: %s", produto[i].fabricante.uf.nome);
		}
	}
	
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

void pesquisaClienteIdade(Cliente clientes[], int contClientes){
	
	for(int i=0; i<contClientes; i++){
		if(clientes[i].idade >= 60){
			printf("\nNome: %s", clientes[i].nome);
		}
	}
}

void pesquisaValorBuscaBinaria(Produto produto[], int index){  
	float auxValor=0;
	
	float tam = sizeof(produto)/sizeof(float);
	
	int ini=0;
	int fim=tam-1;
	int meio;
	
	printf("Digite o valor : ");
	scanf("%f", &auxValor);
	
	while(ini <= fim){
		meio=(ini+fim)/2;
		
		if(auxValor < produto[meio].valorVenda){
			fim = meio-1;
		}else if(auxValor > produto[meio].valorVenda){
			ini = meio+1;
		}else{
	 		printf("VALOR ENCONTRADO: %2.f", produto[meio].valorVenda);
		}	
	}
	
}
