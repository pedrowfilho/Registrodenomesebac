#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

int incluir(){
	printf("\tINCLUIR REGISTRO\n");
	
	//declaração das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Informe o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copia o valor da string
	
	FILE *file; //chama a função FILE do sistema para trabalhar com arquivos
	
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salva no arquivo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , após o valor da última variável armazenada
	fclose(file); //fecha o arquivo
	
	printf("Informe o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, nome); //salva o valor da variável nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , após o valor da última variável armazenada
	fclose(file); //fecha o arquivo
	
	printf("Informe o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, sobrenome); //salva o valor da variável sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma "," após o valor da última variável armazenada
	fclose(file); //fecha o arquivo
	
	printf("Informe o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, cargo); //salva o valor da variável sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consultar(){
	printf("\tCONSULTAR REGISTRO\n");
	setlocale(LC_ALL, "Portuguese"); //seleciona a linguagem
	
	char cpf[40];
	char info[200]; //para armazenar o conteúdo do arquivo
	
	printf("Informe o CPF para consulta: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e lê todo o conteúdo
	
	//validação caso o arquivo não exista
	if(file == NULL){
		printf("CPF não localizado!\n");
	}
	
	//salva na variável "info" os 200 caracteres ou até que não seja nulo
	while(fgets(info, 200, file) != NULL){
		printf("\nRegistro encontrado!\n");
		printf("%s", info);
		printf("\n");
	}
	system("pause");
}

int excluir(){
	printf("\tEXCLUIR REGISTRO\n");
	char cpf[40];
	
	printf("Informe o CPF para excluir: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("CPF removido ou não cadastrado!\n");
		system("pause");
	}
}

char menu(){
	system("cls"); //limpa a tela
	
	//menu do programa
	printf("*** SISTEMA DE REGISTRO DE NOMES ***\n");
	printf("\tSeja Bem-Vindo!\n\n");
	printf("\tEscolha uma opção: \n\n");
	printf("\t1 - Incluir\n");
	printf("\t2 - Consultar\n");
	printf("\t3 - Excluir\n\n");
}

int main(){
	
	int opcao = 0; //declara a varavel que vai armazenar a opcao escolhida pelo usuario
	int laco = 1;
	
	for(laco = 1; laco = 1;){
	
		setlocale(LC_ALL, "Portuguese"); //seleciona a linguagem
		
		menu();
		
		printf("Opção: ");
		scanf("%d", &opcao); //lê a opção escolhida pelo usuário
		
		system("cls"); //limpa a tela
		
		switch(opcao){
			case 1:
				incluir();
				break;
			case 2:
				consultar();
				break;
			case 3:
				excluir();
				break;
			default:
				printf("\tOpção inválida!\n");
				system("pause");
				break;
		}
	}
}

