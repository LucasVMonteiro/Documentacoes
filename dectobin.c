#include <stdio.h>

//0 1 2 3 4 5 6 7 8 9 A B C D E F

int main(void) {
  printf("Numero de 0 a 255: ");
  int c;

  scanf("%d",&c);

  if(c > 255 || c <= -1){
    return -1;
  }

  int bits[] = {128,64,32,16,8,4,2,1};//128 64 32 16 8 4 2 1
  int byte[] = {0,0,0,0,0,0,0,0};
  int tam = sizeof(bits);
  int notbite;
  notbite = 0;
  
  if(c != 0){
  for(int i = 0; i <= tam; i++){

      if(bits[i] > c){
        byte[i] = 0;
        continue;
      }

      int x,y;
      x = bits[i];
      byte[i]=1;
      if(bits[i] == 1){
        break;
      }
      y = x + bits[i+1];
      int contador = i+2;

      if(y > c){
        while (y > c) {
          y = x + bits[contador];
          if( y == c){
            byte[contador] = 1;
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
          if( y > c){
            y = y - bits[contador];
            ++contador;
            continue;
          }
          byte[contador]=1;
          ++contador;
        }
      }
      break;
    }
  }
	
	printf("bin ");
  for(int i = 0; i<8;++i){
    printf("%d",byte[i]);
  }
  return 0;
}
