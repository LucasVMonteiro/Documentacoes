#include <stdio.h>

//0 1 2 3 4 5 6 7 8 9 A B C D E F

int main(void) {
  printf("Digite um caractere: \n");
  int c;
  scanf("%d",&c);
  if(c > 255){
    return -1;
  }
  int bits[] = {128,64,32,16,8,4,2,1};//128 64 32 16 8 4 2 1
  int byte[] = {0,0,0,0,0,0,0,0};
  int tam = 7;
  //128 + 64 eh > ou < q 10? maior, 128 + 32 eh > ou <...
  // se o resultado da soma for menor, manter o valor
  int notbite;
  notbite = 0;
  for(int i = 0; i <= tam; i++){
    if(i != tam){
      if(bits[i] > c){
        byte[i] = 0;
        continue;
      }
      printf("\nindice atual %d valor %d",i,bits[i]);
      int x,y;
      x = bits[i];
      byte[i]=1;
      y = x + bits[i+1];
      int contador = i+2;


      if(y > c){
        while (y > c) {
          y = x + bits[contador];
          if( y == c){
            byte[contador] = 1;
            printf("Concluido");
            break;
          }
          else if( y > c){
            ++contador;
          } 
        }
        //comando
        notbite = 1;
      }
      
      
      if(y < c){
        if(notbite == 0){
          byte[i+1]= 1;
        }
        else{
          byte[contador]=1;
          }
        while(y<c){
          y = y + bits[contador];
          printf("\n%d w\n",y);
          if( y > c){
            y = y - bits[contador];
            printf("\n%d i\n",y);
            ++contador;
            continue;
          }
          byte[contador]=1;
          ++contador;
        }

        //comando
      }


      if ( y > c){
        printf("\nmaior q\n");
        continue;
      }else if(y < c){
        printf("\nmenor q\n");
      }else{
        printf("\nok %d\n",y);
        break;
      }
    }else if(bits[i]==c)
      printf("\nvalor %d\n",c);
    
  }

  for(int i = 0; i<8;++i){
    printf("%d",byte[i]);
  }
  return 0;
}
