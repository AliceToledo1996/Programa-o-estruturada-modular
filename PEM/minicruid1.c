#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha{
	char nome[40];
	char telefone[20];
	char endereco[40];
	char email[20];
	int idade;	
};

int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0";
        setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '5')
	{

		printf("\nEntre com a op��o desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Sair\n\n");
		gets(opcao);

		if(opcao[0] == '1') //inserir
		{
			printf("\nEntre com um nome:");
			gets(agenda[proxima].nome);
			printf("\nEntre com um telefone:");
			gets(agenda[proxima].telefone);
			printf("\nEntre com um endere�o:");
			gets(agenda[proxima].endereco);
			printf("\nEntre com um e-mail:");
			gets(agenda[proxima].email);
			printf("\nEntre com uma idade:");
			char aux[5];
			gets(aux);
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //procurar
		{
			char procurado[40];
			printf("\nEntre com o nome procurado:");
			gets(procurado);

			bool achei = false; //nao achei
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			  //Ignorando Maiusculas/Minusculas:
			  //if(strcasecmp(procurado, agenda[i].nome) == 0)
			  if(strcmp(procurado, agenda[i].nome) == 0)
			  {
			    achei = true; //achei!!
			    printf("\n\nO telefone de %s � %s\n",
			      agenda[i].nome, agenda[i].telefone);
			    //depois de achar nao preciso procurar mais
			    break;
			  }
			}
			if(achei == false)
			{
			  printf("\n\nNome n�o encontrado\n");
			}
		}
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			    printf("%s, telefone: %s, endere�o: %s, e-mail: %s, idade: %d\n",
			      agenda[i].nome, agenda[i].telefone, agenda[i].endereco,
				  agenda[i].email, agenda[i].idade);
			}
			if(fichas_existentes == 0)
				printf("A base de dados est� vazia!\n");
		}
		if(opcao[0] == '4') //excluir
		{
			char procurado[40];
			printf("\nEntre com o nome que sera exclu�do:");
			gets(procurado);

			bool achei = false; //nao achei
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			  //Ignorando Maiusculas/Minusculas:
			  //if(strcasecmp(procurado, agenda[i].nome) == 0)
			  if(strcmp(procurado, agenda[i].nome) == 0)
			  {
			    achei = true; //achei!!
			    printf("\n\nO telefone de %s, que � %s, ser� removido\n", agenda[i].nome, agenda[i].telefone);
			    int j;
			    for(j=i+1; j<fichas_existentes; j++)
			    {
					agenda[j-1] = agenda[j];
			    }
			    fichas_existentes--;
			    proxima--;
			    break;
			  }
			}
			if(achei == false)
			{
			  printf("\n\nNome n�o encontrado\n");
			}
		}
	}
	return 0;
}

