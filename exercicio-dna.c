#include <stdio.h>
#include <string.h>

/*

é necessario q nos indices pares sejam A ou C

e que nos indices impares, seja G ou T de acordo com o indice par anterior

se o indice par for A, entao o indice impar devera ser T
se o indice par for C, entao o indice impar devera ser G

*/
int main(void) {
  //insira uma string composta das letras A C T G
  char dna[]= "ATCGATATCGCGATC";
  int len_str = strlen(dna);
  int resto ,flag, i;
  flag=0;
  //Verificando se o primeiro indice é composto de A ou C
  if(dna[0] == 'A' || dna[0] == 'C'){
    for(i=0;i<len_str;i += 2){//iniciando iteracao a partir de 0, e ate o tamanho da string, iterando de 2 em 2 para obter indices pares
      if (dna[i] == 'A' && dna[i+1] == 'T'){//se o indice par for A e o indice seguinte(impar) for T, continue
        continue;
      }else if(dna[i] == 'C' && dna[i+1] == 'G'){//se o indice par for C e o indice seguinte(impar) for G, continue
        continue;
      }else{//caso o indice par nao seja A ou C, adicione +1 a sentinela 'flag', e saia do laço for
        flag=1;
        printf("\n ERR %d | %c \n",i,dna[i]);
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
