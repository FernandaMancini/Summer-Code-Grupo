#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int cc;
   long n = get_int("Numero do cartao: ");
   int i = 0;
   cc  = n;
   while (cc > 0)
   {
    cc = cc/10;
    i++;
   }
   if (i != 13 && i != 15 && i != 16)
   {
    printf ("INVALIDO! \n");
   }

}
