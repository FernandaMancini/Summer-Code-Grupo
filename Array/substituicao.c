#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_LENGTH 26

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int keyLength = strlen(key);

    if (keyLength != ALPHABET_LENGTH) {
        printf("Chave deve conter 26 characteres.\n");
        return 1;
    }

    // Verificar se a chave contém apenas letras e se cada letra é única
    int freq[ALPHABET_LENGTH] = {0};
    for (int i = 0; i < keyLength; i++) {
        if (!isalpha(key[i])) {
            printf("Chave deve conter apenas caracteres alfabeticos.\n");
            return 1;
        }

        int index = tolower(key[i]) - 'a';
        if (freq[index] > 0) {
            printf("Chave nao deve conter caracteres repetidos.\n");
            return 1;
        }
        freq[index]++;
    }

    string plaintext = get_string("Texto: ");
    int textLength = strlen(plaintext);

    printf("Criptografado: ");

    for (int i = 0; i < textLength; i++) {
        char c = plaintext[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int index = tolower(c) - 'a';
            char encryptedChar = isupper(c) ? toupper(key[index]) : tolower(key[index]);
            printf("%c", encryptedChar);
        } else {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
