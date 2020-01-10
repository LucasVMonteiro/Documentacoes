/*

Esse codigo é a resposta para o seguinte exercicio proposto: 
"
O DNA é um composto organico cujas molecusa contem as instrucoes ACCCA-
CAACA geneticas que coordenam o desenvolvimento e funcionamento de todos os
seres TGGGTGTTGT vivos e alguns virus, e que transmitem as caracteristicas
hereditarias de cada ser vivo. As quatro bases encontradas no DNA sao a adenina
(A), citosina (C), guanina (G) e timina (T). A adenina liga-se exclusivamente à
timina e a citosina liga-se sempre à guanina. Sabendo-se que o DNA é composto
por 2 lados um deles somente com adenina (A) e citosina (C), e o outro somente com guanina (G) e timina (T), um modo de armazenar estes dados de forma
alinha é utilizar os índices pares para um lado da fita e os índices ímpares para outro. Faça uma função que receba como parametro uma string. A função de-
verá verificar (1) se os índices pares contem somente A's e C's e (2) se depois de um A sempre tem um T e depois de um C sempre tem um G. Neste caso,
a funcao devera imprimir na tela "SEQUENCIA CORRETO"; caso contrario,
devera imprimir "SEQUENCIA INCORRETO".
"
*/


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
