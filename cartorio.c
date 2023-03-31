#include <stdio.h>  //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de epa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()//fun�ao por cadastrar os usuarios no sistema
{
	// inicio cria�ao de variaveis/string
	 char arquivo[40];
 	 char cpf[40];
 	 char nome[40];
 	 char sobrenome[40];
 	 char cargo[40];
 	 // final cria�ao de variaveis/string
 	 
 	 printf("digite o cpf a ser cadastrado: ");//coletando informa�ao do usuario
 	 scanf("%s", cpf);//%s refere-se a string
 	 
 	 strcpy(arquivo, cpf); //respnsavel por copiar os valores das strings
 	 
 	 FILE *file;// cria o arquivo
 	 file = fopen(arquivo, "w");//cria o arquivo o "w" siginifica escrever
 	 fprintf(file,cpf);//salvo o valor da variavel
 	 fclose(file);//fecha o arquivo
 	 
 	 
 	 file = fopen(arquivo, "a");
 	 fprintf(file,",");
 	 fclose(file);
 	 
 	 printf("digite o nome a ser cadastrado: ");
 	 scanf("%s",nome);
 	 
	  file = fopen(arquivo, "a");
	  fprintf(file,nome);
	  fclose(file);
	  
	file = fopen(arquivo, "a");
 	 fprintf(file,",");
 	 fclose(file);
 	 
 	 printf("digite o sobrenome a ser cadastrado: ");
 	 scanf("%s",sobrenome);
 	 
	  file = fopen(arquivo, "a");
	  fprintf(file,sobrenome);
	  fclose(file);
	  
	file = fopen(arquivo, "a");
 	 fprintf(file,",");
 	 fclose(file);
 	 
 	 printf("digite o cargo a ser cadastrado: ");
 	 scanf("%s",cargo);
 	 
 	 file = fopen(arquivo, "a");
 	 fprintf(file,cargo);
 	 fclose(file);
 	 
 	 system("pause");
 	 
 	 
 	 
}

int consulta()
{
      setlocale(LC_ALL, "portuguese"); //definindo a linguagem 
      
	  char cpf[40];
      char conteudo[200];
      
         printf("digite o cpf a ser consultado: ");
         scanf("%s",cpf);
      
      FILE *file;
      file = fopen(cpf, "r");
      
      
      
      if(file == NULL)
      {
      	 printf("n�o foi possivel abrir o aquivo, n�o localizado!.\n");
	  }
	  
	  while(fgets(conteudo, 200, file) != NULL)
	  {
	  	 printf("\n Essas sao as informa��es do usu�rio: ");
	  	 printf("%s", conteudo);
	  	 printf("\n\n");
	  }
	     fclose(file);// neste local pois se nao fechar o arquivo ele fica aberto no sistema 
	     system("pause");
}


int deletar()
{
	  setlocale(LC_ALL, "portuguese"); //definindo a linguagem 
	
      char cpf[40];//fun�ao responsavel por criar a variavel cpf
      
      printf("digite o cpf do usuario a ser deletado: ");
      scanf("%s",cpf);//fun�ao responsavel por armazenar na variavel "cpf" 
      
      system("cls");// limpar tela de informa�oes desnecessarias 
      
      FILE *file;//procurando na biblioteca o arquivo file
      file = fopen(cpf,"r");//abriondo o arquivo para a leitura
      fclose(file);
      
      if(file == NULL)// se os dados forem igual a zero ou seja nulo
      {
      	printf("\nO usu�rio nao se encontra no sistema!\n\n");
      	system("pause");
	  }
      
      else//se os dados digitados coincidir com algum arquivo ja registrado
      {
      	remove(cpf);
      	printf("\nUsu�rio deletado com sucesso!\n\n");
      	system("pause");
	  }
    
}

int main()
{
	int opcao=0;// definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

           system("cls");
	
	       setlocale(LC_ALL, "portuguese"); //definindo a linguagem 
	
 	       printf("### cart�rio �zara ###\n\n");//inicio do menu
	       printf("escolha a op��o desejada do menu:\n\n");
	       printf("\t1 - registrar nomes\n");
	       printf("\t2 - consultar nomes\n");
           printf("\t3 - deletar nomes\n");
           printf("\t4 - sair do sistema\n\n");
	       printf("opc�o:");//fim do menu

           scanf("%d", &opcao);//armazenando a escolha do usuario
    
           system("cls");
           
		   switch(opcao)
		   {
		   	case 1:
		   		registro();// chamada de fun�oes 
		   		break;
		   		
			case 2:
		   	    consulta(); 
				break;
			
			case 3:
		        deletar();
			    break;
			
			case 4:
				printf("obrigado por utilizar o sistema!\n\n");
				return 0;
				break;
			
		
			default:
			printf("esta op�ao nao esta disponivel!\n");
			system("pause");
			break;		
		   }
           
		  		     
    } 
}

