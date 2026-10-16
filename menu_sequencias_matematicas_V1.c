#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {


    // Declaracao de variavel
    int sequencia[15]; // cria um vetor de ate 15 numeros
    int n, opcao;
    bool valido;

    // Menu de escolha do tipo de sequencia
    printf("\n======================================\nMENU DE SEQUENCIAS\n");
    printf("\nOpcao 1 - Progressao Aritmetica\nOpcao 2 - Progressao Geometrica\nOpcao 3 - Numeros Primos\nOpcao 4 - Fibonacci\nOpcao 5 - Incremento em Progressao\n");
    printf("\n======================================\n");
    printf("Escolha qual opcao deseja utilizar: ");
    scanf("%d", &opcao);

    // Bloco de sequencias
    switch (opcao) {

        case 1: { // Sequencia de Progressao Aritmetica
            printf("(Voce escolheu PA)\n");

            int primeiroTermo, r;

            printf("\nDigite o primeiro termo da PA: ");
            scanf("%d", &primeiroTermo);

            printf("\nDigite a razao da PA: ");
            scanf("%d", &r);

            sequencia[0] = primeiroTermo;

            for (int i = 1; i < n; i++) {
                sequencia[i] = sequencia[i - 1] + r;
            }
            break; // Indica "pare aqui, nao continue testando os proximos cases"
        }

        case 2: { // Sequencia de Progressão Geométrica
            printf("(Voce escolheu PG)\n");

            int primeiroTermo, q;

            printf("\nDigite o primeiro termo da PG: ");
            scanf("%d", &primeiroTermo);

            printf("\nDigite a razao da PG: ");
            scanf("%d", &q);

            sequencia[0] = primeiroTermo;

            for (int i = 1; i < n; i++) {
                sequencia[i] = sequencia[i - 1] * q;
            }
            break;
        }

        case 3: { // Sequencia de Numeros Primos
            printf("(Voce escolheu Numeros Primos)\n");

            int contador = 0;   // quantos pares já achei
            int candidato = 2;  // número que estou testando agora (começa em 2, pois 0 e 1 nunca são primos)


            while (contador < n) {
                int numero = candidato;
                int ehPrimo = 1;   // supoe que e primo (igual fizemos com "valido = true")

                for (int d = 2; d < numero; d++) {
                    if (numero % d == 0) {
                        ehPrimo = 0; // achou um divisor, nao e primo
                    }
                }

                if (ehPrimo) { 
                    printf("%d e primo\n", numero);
                    sequencia[contador] = numero; // guarda o primo na posição atual do vetor
                    contador++; // avança para a próxima posição livre

                } else {
                    printf("%d nao e primo\n", numero);
                }
                candidato++;
            }

            for (int i = 0; i < n; i++) {
                printf("%d, ", sequencia[i]);
            }
            break;
        }

        case 4: { // Sequencia de Fibonacci
            printf("(Voce escolheu Fibonacci)\n");

            sequencia[0] = 1;
            sequencia[1] = 1;

            for (int i = 2; i < n; i++) {
                sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
            }

            for (int i = 0; i < n; i++) {
                printf("%d ", sequencia[i]);
            }
            break;
        }

        case 5: { // Sequencia de Incremento em Progressão
            printf("(Voce escolheu Incremento em Progressao)\n");

            int tipo;
            int primeiroTermo, razao;
            /// Menu tipo de incremento
            printf("\nEscolha o tipo de incremento:\n");
            printf("1 - Linear\n2 - Geometrico\n");
            scanf("%d", &tipo);

            printf("\nDigite o primeiro termo: ");
            scanf("%d", &primeiroTermo);

            printf("\nDigite a razao: ");
            scanf("%d", &razao);

            sequencia[0] = primeiroTermo;

            if (tipo == 1) {
                for (int i = 1; i < n; i++) {
                    sequencia[i] = sequencia[i - 1] + razao;
                }
            } else if (tipo == 2) {
                for (int i = 1; i < n; i++) {
                    sequencia[i] = sequencia[i - 1] * razao;
                }
            }
            break;
        }
        
        default: // Funciona como o "else" final, para qualquer valor que nao bateu em nenhum case
            printf("\nOpcao invalida\n");
    }
    return 0;
}