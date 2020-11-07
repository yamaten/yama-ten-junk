#include <stdio.h>

int main(int argc, char** argv)
{
  printf("\\|"); 
  for (int x=0; x<16; x++)
    printf("%x|", x);
  printf("\n");

  for (int x=-1; x<16; x++)
    printf("-+");
  printf("\n");
  
  for (int y=0; y<16; y++) {
    printf("%x|", y);
    for (int x=0; x<16; x++) 
      printf("%c|", (x>=2&&x<8)? x*16+y: ' ');
    printf("\n");
  }
}
    
