//programa para leitura de arquivos de texto
//imprimi conteudo do txt na tela e informa a quantidade de caracteres
//aqui eu tento exibir cada ponteiro de cada caractere, em andamento
#include <stdio.h>
#include <stdlib.h>

int copiar(FILE *fp, char buffer[]);

int main(int argc, char *argv[]){
	
	FILE *fp;
	//char nArq[20];
	int tamArq;
		
	//scanf("%s",nArq);	
		
	fp = fopen(argv[1],"r");
	tamArq = sizeof(*fp);
	
	char buffer[tamArq];
	printf("%d\n",tamArq);
	//Menu
	int decisao;
	printf("O que deseja fazer?\n");
	printf("Le arquivo de texto - 1\n");
	printf("Le ponteiros do arquivo - 2\n");
	
	scanf("%d",&decisao);
	
	//funcao 1
	if(decisao == 1)
	{
		int qntChar = copiar(fp,buffer);
		printf("%s\n%d Caracteres\n",buffer,qntChar-1);	
	}
	else if(decisao == 2)
	{
		char c;
		int qntdChar;
		qntdChar = 0;
		while(!feof(fp))
		{
			c = getc(fp);
			qntdChar++;
		}
		
		int contador;
		for(contador = 0;contador < qntdChar; contador++)
		{
			fread(&c,sizeof(char),1,fp);
			printf("%p -> %c\n",fp,c);
			fseek(fp,sizeof(char)*contador,SEEK_SET);
			
		}
		
		printf("%d posicoes lidas\n",contador);
		
	}
	else
	{
		printf("Responda algo valido, fim do programa!");
	}
	
	fclose(fp);
	
	return 0;
}

int copiar(FILE *fp, char buffer[]){
	//funcao 1
	char c;
	printf("Iniciando while\n\n");
	int contador;
	contador = 0;	
	while(!feof(fp))
	{
		c = getc(fp);
		buffer[contador] = c;
		//printf("%c",c);
		contador++;
	}
	return contador;
}
