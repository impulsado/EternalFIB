#include<stdio.h>

main()
{
  
  long long i, resultado=0;
  
  for ( i=0; i<2000000; i++)
    resultado=resultado+i;

  printf("Resultado = %lld\n",resultado);
}
