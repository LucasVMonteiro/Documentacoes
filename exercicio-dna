#include <stdio.h>
#include <string.h>

/*

é necessario q nos indices pares sejam A ou C

e que nos indices impares, seja G ou T de acordo com o indice par anterior

se o indice par for A, entao o indice impar devera ser T
se o indice par for C, entao o indice impar devera ser G


*/
int main(void) {

  char dna[]= "ATCGATATCGCGATC";
  int len_str = strlen(dna);
  printf("%d\n",len_str);
  char gen;
  int resto ,flag, i;
  flag=0;
  if(dna[0] == 'A' || dna[0] == 'C'){

    for(i=0;i<len_str;i += 2){
      printf("%d\n",i);
      // se i for par: verficiar se é A ou C,
      // e verificar se o indice i+1 é G ou T
      if(i == len_str){
            printf("8\n");
            break;
      }
      else if (dna[i] == 'A' && dna[i+1] == 'T'){
        //se a posicao impar for verdadeira continue
        continue;
      }else if(dna[i] == 'C' && dna[i+1] == 'G'){
        continue;
      }else{
        flag=1;
        printf("\n ERR %d | %c \n",i,dna[i]);
        break;
      }
    }
    //bloco if
    if(flag==1)
      printf("SEQUENCIA INCORRETA\n");
    else
      printf("SEQUENCIA CORRETA\n");
  
  }   
  
  return 0;
}
