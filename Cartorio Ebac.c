
#include <stdio.h>         //biblioteca de comunicação com o usuário
#include <stdlib.h>        //biblioteca de alocação de espaço em memória
#include <locale.h>        //biblioteca de alocações de texto por região
#include <string.h>        //biblioteca responsável por cuidar das strings

int registro()  //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/ strings
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//fim da criação de variáveis/ string
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informações do usuário
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf);   //responsável por copiar os valores das string
	
	FILE *file;    //cria o arquivo
	file = fopen(arquivo, "w");   //cria e abre o arquivo, o "w" significa escrever
	fprintf(file,cpf);     //salva o valor da variável
	fclose(file);          //fecha o arquivo
	
	file = fopen(arquivo, "a");  //cria e "a" atualiza o arquivo
	fprintf(file,", ");  //adiciona uma virgula ao arquivo
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado : ");  //coletando informações do usuário
	scanf("%s",nome);  //refere-se a string
	
	file = fopen(arquivo, "a");  //cria e "a" atualiza a variavel
	fprintf(file,nome);  //salva uma informação na variável
	fclose(file);  //fecha a variável
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,", ");  //adiciona virgula ao arquivo
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado : ");  //coletando informações do usuário
	scanf("%s",sobrenome);  //refere-se a sting
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,sobrenome); //salva uma informação na variavel
	fclose(file); //fecha a variavel
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,", ");  //adiciona uma informação na variavel
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado : ");  //coletando informações do usuário
	scanf("%s",cargo);  //refere-se a string
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file,cargo);  //adiciona uma informação na variavel
	fclose(file);  //fecha a variavel
	
	file = fopen(arquivo, "a");  //abre e "a" atualiza o arquivo
	fprintf(file,".");  //adiciona um ponto ao arquivo
	fclose(file);  //fecha o arquivo
	
	system("pause");  //pausa a execução do programa e espera um comando do usuário
	
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
	
	if(file == NULL)  //avalia se a variavel é NULL(nulo) 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 300, file) != NULL)  //while executa um bloco caso uma condição especifica for verdadeira
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
	
	}
	
int deletar()
{
	char cpf[50];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Deletado com sucesso, o usuário já não existe no sistema!.\n");
		system("pause");
		
	}
}

int main()  //inicio da execução do codigo
{


	int opcao=0;      //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)  //responsavel por iniciar um loop
	{
	
		system("cls");  //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem
		
		printf("Cartório da EBAC ####\n\n\n");    //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");    //Fim do menu
	
		scanf("%d", &opcao);    //Armezenando a escolha do usuário
	
		system("cls");  //responsavel por limpar a tela
		
		
		switch(opcao)  //inicio da seleção do menu
		{
			case 1:
			registro();  //chamada da função registro
			break;  //interrompe a execução de um loop
		
			case 2:
			consultar();  //chamada da função de consulta
			break;  //interrompe a função de um loop
		
			case 3:
			deletar();  //chamada da função de deletar
			break;  //interrompe a função de um loop
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default: //especifica o que deve ser executado se nenhuma das fuinções for atendida
				printf("Essa opção não está disponível\n");
			system("pause");
			break;
		} //fim da seleção do menu
	}		
}
