
#include <stdio.h>         //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>        //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>        //biblioteca de aloca��es de texto por regi�o
#include <string.h>        //biblioteca respons�vel por cuidar das strings

int registro()  //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/ strings
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//fim da cria��o de vari�veis/ string
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informa��es do usu�rio
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf);   //respons�vel por copiar os valores das string
	
	FILE *file;    //cria o arquivo
	file = fopen(arquivo, "w");   //cria e abre o arquivo, o "w" significa escrever
	fprintf(file,cpf);     //salva o valor da vari�vel
	fclose(file);          //fecha o arquivo
	
	file = fopen(arquivo, "a");  //cria e "a" atualiza o arquivo
	fprintf(file,", ");  //adiciona uma virgula ao arquivo
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado : ");  //coletando informa��es do usu�rio
	scanf("%s",nome);  //refere-se a string
	
	file = fopen(arquivo, "a");  //cria e "a" atualiza a variavel
	fprintf(file,nome);  //salva uma informa��o na vari�vel
	fclose(file);  //fecha a vari�vel
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,", ");  //adiciona virgula ao arquivo
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado : ");  //coletando informa��es do usu�rio
	scanf("%s",sobrenome);  //refere-se a sting
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,sobrenome); //salva uma informa��o na variavel
	fclose(file); //fecha a variavel
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,", ");  //adiciona uma informa��o na variavel
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado : ");  //coletando informa��es do usu�rio
	scanf("%s",cargo);  //refere-se a string
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file,cargo);  //adiciona uma informa��o na variavel
	fclose(file);  //fecha a variavel
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,".");  //adiciona um ponto ao arquivo
	fclose(file);  //fecha o arquivo
	
	system("pause");  //pausa a execu��o do programa e espera um comando do usu�rio
	
}
	
int consultar()
{
	setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem
	
	char cpf[50];
	char conteudo[300];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");  //abre e "r" le os arquivos na pasta 
	
	if(file == NULL)  //avalia se a variavel � NULL(nulo) 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 300, file) != NULL)  //while executa um bloco caso uma condi��o especifica for verdadeira
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
	
	}
	
int deletar()
{
	char cpf[50];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Deletado com sucesso, o usu�rio j� n�o existe no sistema!.\n");
		system("pause");
		
	}
}

int main()  //inicio da execu��o do codigo
{


	int opcao=0;      //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)  //responsavel por iniciar um loop
	{
	
		system("cls");  //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem
		
		printf("Cart�rio da EBAC ####\n\n\n");    //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: ");    //Fim do menu
	
		scanf("%d", &opcao);    //Armezenando a escolha do usu�rio
	
		system("cls");  //responsavel por limpar a tela
		
		
		switch(opcao)  //inicio da sele��o do menu
		{
			case 1:
			registro();  //chamada da fun��o registro
			break;  //interrompe a execu��o de um loop
		
			case 2:
			consultar();  //chamada da fun��o de consulta
			break;  //interrompe a fun��o de um loop
		
			case 3:
			deletar();  //chamada da fun��o de deletar
			break;  //interrompe a fun��o de um loop
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default: //especifica o que deve ser executado se nenhuma das fuin��es for atendida
				printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		} //fim da sele��o do menu
	}		
}
