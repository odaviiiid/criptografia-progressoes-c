#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    
    // Declaracao de variavel
    char palavra[16]; // cria um vetor de ate 16 caracteres
    int shift, n;
    bool valido;

    // Definicao do shift
    printf("\n======================================\nMENU INICIAL\n");
    printf("\nDigite o shift desejado para a criptografia: ");
    scanf("%d", &shift); // Gera imput para o usuario digitar o valor de shift e armazena na variavel    
    
    // Laco para a criacao e tratamento da palavra a ser cifrada
    do { 
        printf("\nAgora digite a palavra que deseja criptografar (deve conter ate 15 letras): ");
        scanf("%15s", palavra); // Gera imput para o usuario digitar e armazena no vetor "palavra". "%15s" limita quantos caracteres o scanf pode escrever
        
        n = strlen(palavra); // "strlen" Le e calcula quantos caracteres tem na string (palavra) e descobre o tamanho armazenando o valor na variavel

        valido = true; // Supoe valido a cada nova tentativa
        
        for (int i = 0; i < n; i++) { // Laco que percorre as posicoes do vetor, iniciando em 0 e incrementando para avancar a cada posicao
            if ((palavra[i] < 'A' || palavra[i] > 'Z') && (palavra[i] < 'a' || palavra[i] > 'z')) { // Se algo for diferente de letras
                valido = false;
            }
        }

        if (!valido) {
            printf("Voce deve digitar usando apenas letras!\n");
        }   
    } while (!valido); 

    printf("\nVoce digitou '%s' (%d caracteres).\n", palavra, n);
    
    // Laco que percorre e valida o que ha em cada posicao do vetor, iniciando em 0 e incrementando para avancar a cada posicao
    for ( int i = 0; i < n; i++) { 
        // Tratamento de letras maiusculas
        if (palavra[i] >= 'A' && palavra[i] <= 'Z') { // Trata maiusculas
            int posicao = palavra[i] - 'A'; // Indica o conteudo de cada posicao (iniciando na posicao 0) do conteudo digitado pelo usuario e armazenado no vetor "palavra[16]"
            int novaPosicao = (posicao + shift) % 26; // Cria uma nova variavel que e a soma de posicao original com o shift. "% 26" e usado para voltar ao inicio do alfabeto quando passar da ultima letra
            palavra[i] = 'A' + novaPosicao; // Converte a nova posicao de volta em letra, usando "A" como ponto de partida do alfabeto maiusculo
        // Tratamento de letras minusculas
        } else if (palavra[i] >= 'a' && palavra[i] <= 'z') {
            int posicao = palavra[i] - 'a';
            int novaPosicao = (posicao + shift) % 26;
            palavra[i] = 'a' + novaPosicao; // Converte a nova posicao de volta em letra, usando "A" como ponto de partida do alfabeto minusculo
        }
    }
    printf("\n======================================\n");
    printf("\nCom a Cifra de Cesar a palavra seria '%s'", palavra);

    return 0;
}