#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    
    // Declaracao de variavel
    char palavra[16]; // cria um vetor de ate 16 caracteres
    int sequencia[15]; // cria um vetor de ate 15 numeros
    int shift, n, opcao;
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
            printf("\nVoce deve digitar usando apenas letras!\n");
        }   
    } while (!valido); 

    printf("\nVoce digitou '%s' (%d caracteres).\n", palavra, n);
    
    // Menu de escolha do tipo de sequencia
    printf("\n======================================\nMENU DE SEQUENCIAS\n");
    printf("\nOpcao 1 - Progressao Aritmetica\nOpcao 2 - Progressao Geometrica\nOpcao 3 - Numeros Primos\nOpcao 4 - Fibonacci\nOpcao 5 - Incremento em Progressao\n");
    printf("\nEscolha qual opcao deseja utilizar: ");
    scanf("%d", &opcao);
    printf("\n======================================\n");

    // Bloco de sequencias
    switch (opcao) {

        case 1: { // Sequencia de Progressao Aritmetica
            printf("Voce escolheu Progressao Aritmetica (PA)\n");

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
            printf("Voce escolheu Progressão Geométrica (PG)\n");

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
            printf("Voce escolheu Numeros Primos\n\n");

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

            printf("\nPRIMOS ");

            for (int i = 0; i < n; i++) {
                
                printf("| %d ", sequencia[i]);
            }
            break;
        }

        case 4: { // Sequencia de Fibonacci
            printf("Voce escolheu Fibonacci\n");

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
            printf("Voce escolheu Incremento em Progressao\n");

            int tipo;
            int primeiroTermo, razao;
            /// Menu tipo de incremento
            printf("\nOpcao 1 - Linear\nOpcao 2 - Geometrico\n");
            printf("\nEscolha o tipo de incremento: ");
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

    // Laco que percorre e valida o que ha em cada posicao do vetor, iniciando em 0 e incrementando para avancar a cada posicao
    for ( int i = 0; i < n; i++) { 
        // Tratamento de letras maiusculas
        if (palavra[i] >= 'A' && palavra[i] <= 'Z') { // Trata maiusculas
            int posicao = palavra[i] - 'A'; // Indica o conteudo de cada posicao (iniciando na posicao 0) do conteudo digitado pelo usuario e armazenado no vetor "palavra[16]"
            int deslocamentoTotal = shift + sequencia[i];
            int novaPosicao = (posicao + deslocamentoTotal) % 26; // Cria uma nova variavel que e a soma de posicao original com o shift. "% 26" e usado para voltar ao inicio do alfabeto quando passar da ultima letra
            palavra[i] = 'A' + novaPosicao; // Converte a nova posicao de volta em letra, usando "A" como ponto de partida do alfabeto maiusculo
        // Tratamento de letras minusculas
        } else if (palavra[i] >= 'a' && palavra[i] <= 'z') {
            int posicao = palavra[i] - 'a';
            int deslocamentoTotal = shift + sequencia[i];
            int novaPosicao = (posicao + deslocamentoTotal) % 26;
            palavra[i] = 'a' + novaPosicao; // Converte a nova posicao de volta em letra, usando "A" como ponto de partida do alfabeto minusculo
        }
    }
    printf("\n======================================\n");
    printf("\nCom a Cifra de Cesar a palavra seria '%s'", palavra);
    
    // Aquivo
        FILE *arquivo = fopen("resultado_cifra.txt", "w"); // Abre (ou cria) o arquivo para escrever
        if (arquivo == NULL) { // Verifica se o arquivo abriu ou foi criado corretamente
            printf("Erro ao abrir/criar o arquivo!\n");
            return 1;   // encerra o programa, já que não há como continuar sem o arquivo
        }

        fprintf(arquivo, "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n", palavra, shift, opcao, n); // Escreve no arquivo

        fclose(arquivo); // Fecha o arquivo e salva o conteudo
        
    return 0;
}