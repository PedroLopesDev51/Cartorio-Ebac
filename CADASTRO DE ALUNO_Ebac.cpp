#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()                                      // aqui estamos designando funções que só serão chamadas quando o usuário fizer a escolha da opção, otimizando o programa.         
{
	// Inicio criacao de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// FINAL criacao de variaei/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informacao do usuario
	scanf("%s", cpf);  //%s refere-se a string.
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings (aqui estamos dizendo que o nome do arquivo vai ser o mesmo valor do cpf inserido.)
	
	FILE *file;        // cria o arquivo (FILE é um comando do sistema para criar arquivo e *file é o nome do arquivo)
	file = fopen(arquivo, "w");  //cria o arquivo (aqui designamos que o file vai ter o nome de arquivo que vai ser o mesmo do cpf, com o comando "w" de escrita)
	fprintf(file,cpf);      // fprintf quer dizer que estamos salvando no arquivo a variavel cpf, para printar no arquivo.
	fclose(file);  // fecha o arquivo apos finalizar o registro do cpf
	
	
	file = fopen(arquivo, "a");  //aqui estamos pedindo para ele abrir o arquivo criado e atulizar o registro "a"
	fprintf(file,",");  // aqu estamos pedindo para ele inserir uma , apos o cpf para as informacoes contidas no arquivo nao ficarem todas juntas.
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); // agora pedimos para p usuario inserir o nome
	scanf("%s", nome);  // aqui estamos salvando tudo que ele digitar na string nome, no passo seguinte vamos salvar ela no nosso arquivo
	
	
	file = fopen (arquivo, "a");   //aqui estamos aabrindo o arquivo arquivo e atualizando ele "a"
	fprintf(file,nome);            //com o fprintf estamos dando um print f para o file nao para o usuario, salvando a informacao nome no arquivo
	fclose(file);   //aqui fechamos o arquivo apos salvar o conteudo da variavel nome dentro do arquivo
	
	file = fopen(arquivo, "a");  // novamente estamos colocanto a , apos o nome ser salvo no arquivo.
	fprintf(file,",");  //
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");  // novamente estamos pedindo apra ele abrir o arquivo arquivo atualizando ele
	fprintf(file,sobrenome);  // aqui pedimos para ele printar no arquivo a variavel sobrenome digitada pelo usuario
	fclose(file);
	
	file = fopen(arquivo, "a");  // novamente estamos colocanto a , apos o sobrenome ser salvo no arquivo.
	fprintf(file,",");  //
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");            //definindo a linguagem (precisamos chamalo de novo pois estamos criando uma funcao diferente e uma nao encherga a outra.
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");

}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");  
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL )
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
   {
   int opcao=0;  // Definindo as variaveis
   int laco=1;
   
   for(laco=1;laco=1;)
   {
   	 system("cls");
   	  	
	   setlocale(LC_ALL, "Portuguese");            //definindo o local como portugues para a comunicacao com a biblioteca para uma acentucao correta.
   		
	   printf("### SISTEMA DE CADASTRO DE ALUNOS DA EBAC ### \n\n");  //inicio do menu
	   printf("Esolha a opção desejada: \n\n");
	   printf("\t1 - Registrar nomes\n");              // O /t serve para dar o espaçamento da margemm
	   printf("\t2 - Consultar nomes\n");              // O /n serve para pular uma linha
	   printf("\t3 - Apagar nomes\n\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("desenvolvido por @drope51\n\n");   
	   printf("Opção: "); //Fim do menu
   
	   scanf("%d", &opcao); //(ARMAZEANDNDO A ESCOLHA DO USUARIO) Scanf tem como objetivo escanear o que o usuario coloca, %d = armazeando variavel de numero inteiro. & = define que a opcao que o usuario inserir sera armazenada na variavel opcao
   		
	    system("cls");     // comando para o sistema limpar a tela apos o usuario escolher uma opcao.
	   
	   switch(opcao) // inicio da seleção de menu
	   {
	   		case 1:            // aqui estamos fazendo a chamada da funcao criada la em cima. ao selecionar 1 ele vai chaamar a funçao int registro()
	   		registro();
			break;
			 	
			case 2:
			consulta();
		  	break;
		  		
		  	case 3:
			deletar();
			break;		
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("Essa opção não esta disponivel!\n");
   		 	system("pause");
			break;					
	   } //Fim da seleção
   
	}   
}

