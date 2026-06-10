#include <stdio.h>

int main ()
{
  FILE * pFile;
  pFile = fopen ( "Alunadoooo.bin" , "wb" );
  fputs ( "This is an apple." , pFile );
  fseek ( pFile , 1 , SEEK_SET );
  
  fputs ( " sam" , pFile );
  fclose ( pFile );
  return 0;
}