#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long num;

    do
    {
       num = get_long ("Numero do cartao: ");
    }
    while (num <= 0);

    long cc = num;
    int soma = 0;
    int count = 0;
    long divisor = 10;
    char result[11];

    while (cc > 0)
    {
        int ultDigit = cc % 10;
        soma = soma + ultDigit;
        cc = cc / 100;
    }

    cc = num / 10;
    while (cc > 0)
    {
        int ultDigit = cc % 10;
        int vezesDois = ultDigit * 2;
        soma = soma + (vezesDois % 10) + (vezesDois / 10);
       cc = cc / 100;
    }

    cc = num;
    while (cc != 0)
    {
        cc = cc / 10;
        count++;
    }

    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int priDigit = num / divisor;
    int priDoisDigit = num / (divisor / 10);

    if (soma % 10 == 0)
    {
        if (priDigit == 4 && (count == 13 || count == 16))
        {
             strcpy(result, "VISA");
        }
        else if ((priDoisDigit == 34 || priDoisDigit == 37) && count == 15)
        {
            strcpy(result, "AMEX");
        }
        else if ((50 < priDoisDigit && priDoisDigit < 56) && count == 16)
        {
            strcpy(result, "MASTERCARD");
        }
        else
        {
            strcpy(result, "INVALID");
        }
    }
    else
    {
        strcpy(result, "INVALID");
    }

    printf("%s\n", result);
}