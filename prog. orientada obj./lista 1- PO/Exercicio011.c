#include <stdio.h>
#include <string.h>

#define MAX 100

int palindromo(char *palavra);
int palindromo(char *palavra) 
{

    int ordem_normal = 0;
    int ordem_contrario = strlen(palavra) - 1;

    while (ordem_normal<ordem_contrario)
    {
        if (palavra[ordem_normal++] != palavra[ordem_contrario--])
        {
            return 0;

        }
        
    }
    
    return 1;
}

int main() 
{
    char palavra[MAX+1];
// Leitura
    fgets(palavra, MAX, stdin);
// Remove '\n' do final da cadeia de caracteres
    int tam = 0;

    while ( palavra[tam] != '\0' ) 
        ++tam;
        if ( tam > 0 && palavra[tam-1] == '\n' ) --tam; // Unix e Windows
    
    palavra[tam] = '\0';
// Chama a funcao int palindromo(char *palavra)
    if ( palindromo(palavra) ) printf("PALINDROMO\n");
        else printf("-\n");

    return 0;
}