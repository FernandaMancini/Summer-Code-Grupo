#include <stdio.h>
#include <cs50.h>

int main(void)
{
   long n;
   do
   {
      n = get_long("Numero do cartao: ");
   } while (n <= 0);

   long cc = n;
   int soma;

   while (cc > 0)
   {
      int ultdig = cc % 10;
      soma = soma + ultdig;
      cc = cc/100;
   }

   cc = n/10;
   while (c > 0)
   {
      int ultdig = cc % 10;
      int vezesdois = ultdig * 2;
      soma = soma + (vezesdois /10);
      cc = cc/100;
   }
   

}
