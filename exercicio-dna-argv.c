#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  //insira uma string composta das letras A C T G
  int len_str = strlen(argv[1]);
  int resto ,flag, i;
  flag=0;
  //Verificando se o primeiro indice é composto de A ou C
  if(argv[1][0] == 'A' || argv[1][0] == 'C'){
    for(i=0;i<len_str;i += 2){//iniciando iteracao a partir de 0, e ate o tamanho da string, iterando de 2 em 2 para obter indices pares
      if (argv[1][i] == 'A' && argv[1][i+1] == 'T'){//se o indice par for A e o indice seguinte(impar) for T, continue
        continue;
      }else if(argv[1][i] == 'C' && argv[1][i+1] == 'G'){//se o indice par for C e o indice seguinte(impar) for G, continue
        continue;
      }else{//caso o indice par nao seja A ou C, adicione +1 a sentinela 'flag', e saia do laço for
        flag=1;
        printf("\n ERR %d | %c \n",i,argv[1][i]);
        break;
      }
    }//aqui sera analisada a sentinela, caso 0 entao a sequencia respeita os criterios, caso 1 entao esta incorreta
    if(flag==1)
      printf("SEQUENCIA INCORRETA\n");
    else
      printf("SEQUENCIA CORRETA\n");
  }
  return 0;
}
