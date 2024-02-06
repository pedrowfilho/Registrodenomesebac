#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int incluir(){ //fun��o respons�vel por cadastrar nomes no sistema
	printf("\tINCLUIR REGISTRO\n\n");
	
	//declara��o das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Informe o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copia o valor da string
	
	FILE *file; //chama a fun��o FILE do sistema para trabalhar com arquivos
	
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //escreve no arquivo o valor da vari�vel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , ap�s o valor da �ltima vari�vel armazenada
	fclose(file); //fecha o arquivo
	
	printf("Informe o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, nome); //escreve o valor da vari�vel nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , ap�s o valor da �ltima vari�vel armazenada
	fclose(file); //fecha o arquivo
	
	printf("Informe o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, sobrenome); //salva o valor da vari�vel sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma "," ap�s o valor da �ltima vari�vel armazenada
	fclose(file); //fecha o arquivo
	
	printf("Informe o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, cargo); //escreve o valor da vari�vel sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consultar(){
	printf("\tCONSULTAR REGISTRO\n\n");
	setlocale(LC_ALL, "Portuguese"); //seleciona a linguagem
	
	char cpf[40];
	char info[200]; //para armazenar o conte�do do arquivo
	
	printf("Informe o CPF para consulta: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e l� todo o conte�do
	
	//valida��o caso o arquivo n�o exista
	if(file == NULL){
		printf("CPF n�o localizado!\n");
	}
	
	//salva na vari�vel "info" os 200 caracteres ou at� que n�o seja nulo
	while(fgets(info, 200, file) != NULL){
		printf("\nRegistro encontrado!\n");
		printf("%s", info);
		printf("\n");
	}
	system("pause");
}

int excluir(){
	printf("\tEXCLUIR REGISTRO\n\n");
	char cpf[40];
	
	printf("Informe o CPF para excluir: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("CPF removido ou n�o cadastrado!\n");
		system("pause");
	}
}

char menu(){
	system("cls"); //limpa a tela
	
	//menu do programa
	printf("*** SISTEMA DE REGISTRO DE NOMES ***\n");
	printf("\tSeja Bem-Vindo!\n\n");
	printf("\tEscolha uma op��o: \n\n");
	printf("\t1 - Incluir\n");
	printf("\t2 - Consultar\n");
	printf("\t3 - Excluir\n");
	printf("\t4 - Cadastrar usu�rio\n");
	printf("\t5 - Sair\n\n");
}

int cadastrarUsuario(){
	printf("\tCADASTRAR USU�RIO\n\n");
	
	//declara��o das vari�veis
	char arquivo[40];
	char email[40];
	char nome[40];
	char sobrenome[40];
	char senha[10];
	
	printf("email: ");
	scanf("%s", email);
	
	strcpy(arquivo, email); //copia o valor da string
	
	FILE *file; //chama a fun��o FILE do sistema para trabalhar com arquivos
	
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, email); //salva no arquivo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , ap�s o valor da �ltima vari�vel armazenada
	fclose(file); //fecha o arquivo
	
	printf("senha: ");
	scanf("%s", senha);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, senha); //salva o valor da vari�vel nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , ap�s o valor da �ltima vari�vel armazenada
	fclose(file); //fecha o arquivo
	
	printf("nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, nome); //salva o valor da vari�vel nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , ap�s o valor da �ltima vari�vel armazenada
	fclose(file); //fecha o arquivo
	
	printf("sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, sobrenome); //salva o valor da vari�vel nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, ","); //inclui uma , ap�s o valor da �ltima vari�vel armazenada
	fclose(file); //fecha o arquivo
	
	printf("Usu�rio cadastrado com sucesso!\n");
	
	system("pause");
}

int main(){
	
	int opcao = 0; //declara a varavel que vai armazenar a opcao escolhida pelo usuario
	int laco = 1;
	char senhadigitada[] = "a";
	int verificacao;
	
	printf("*** SISTEMA DE REGISTRO DE NOMES ***\n");
	printf("\t\tAcesse!\n\n");
	printf("Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	//compara se a senha digitada pelo usu�rio � a mesma da string
	verificacao = strcmp(senhadigitada, "admin");
	
	if(verificacao == 0){
		
		for(laco = 1; laco = 1;){
		
			setlocale(LC_ALL, "Portuguese"); //seleciona a linguagem
			
			menu();
			
			printf("Op��o: ");
			scanf("%d", &opcao); //l� a op��o escolhida pelo usu�rio
			
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
				case 4:
					cadastrarUsuario();
					break;
				case 5:
					printf("Obrigado por utilizar o sistema!");
					return 0; //sai do sistema
					break;
				default:
					printf("\tOp��o inv�lida!\n");
					system("pause");
					break;
			}
		}
	}else
		printf("Senha incorreta!");
}

