//
// Tomás Oliveira e Silva, AED, October 2021
//
// This program implements a simple sieve of Eratosthenes.
// It does not work as intended. Use the valgrind and
// gdb programs to find the programming errors. Correct them.
// usar -g para compilar e depois usar valgrind

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  const int limit = 1000000;
  int *sieve = (int *)malloc((size_t)(1 + limit) * sizeof(int)); //um int ocupa 4 bytes, logo temos que multiplicar por 4
  if(sieve == NULL)
    return 1;
  for(int i = 0;i <= limit;i++)
    sieve[i] = 0;  //fill the table with zeros
  sieve[0] = sieve[1] = 1; // 0 and 1 are not prime
  for(int p = 2;p * p <= limit;p++)
    if(sieve[p] == 0)
      for(int i = p * p;i <= limit;i += p)
        sieve[i] = 1; // i is not prime
  int c = 0;
  for(int i = 0;i <= limit;i++)
    if(sieve[i] == 0)
      c++;
  printf("There are %d prime numbers up to %d\n",c,limit);
  free(sieve);
  return 0;
}
