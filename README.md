# Cifra de César com Progressões Matemáticas

Projeto da disciplina de Algoritmo e Pensamento Computacional, desenvolvido em linguagem C.

## Objetivo

Unificar o conceito de criptografia simples (Cifra de César) com matemática aplicada
(progressões e séries) e conceitos computacionais, aplicando a Taxonomia de Bloom
no processo de aprendizado.

## O que o programa faz

1. Lê uma palavra secreta (até 15 letras, validando que contém apenas letras)
2. Lê um valor de SHIFT (deslocamento fixo)
3. Permite escolher uma entre 5 sequências matemáticas:
   - Progressão Aritmética (PA)
   - Progressão Geométrica (PG)
   - Números Primos
   - Série de Fibonacci
   - Incremento em Progressão (linear ou geométrico)
4. Aplica duas camadas de criptografia sobre a palavra:
   - Camada 1: Cifra de César com o SHIFT fixo
   - Camada 2: deslocamento adicional, usando a sequência escolhida (um termo por letra)
5. Exibe o resultado na tela e grava em um arquivo de log (`resultado_cifra.txt`)

## Organização dos arquivos

Este repositório documenta as etapas de construção do projeto, não apenas a
versão final:

| Arquivo | Descrição |
|---|---|
| `cifras_de_cesar_V1.c` | Primeira versão: só a Cifra de César, com shift fixo |
| `menu_sequencias_matematicas_V1.c` | Módulo separado, com as 5 sequências matemáticas isoladas |
| `cifras_de_cesar_V2.c` | **Versão final**: une as duas camadas e grava o resultado em arquivo |
| `resultado_cifra.txt` | Exemplo de arquivo gerado pela execução do programa |

## Conceitos de Algoritmos aplicados

- Vetores (`char[]` para strings, `int[]` para sequências numéricas)
- Estruturas de repetição: `for`, `while`, `do-while`
- Estruturas de decisão: `if`/`else if`/`else`, `switch`/`case`
- Laços aninhados (teste de números primos)
- Escopo de variáveis em blocos (`{ }`)
- Operador módulo (`%`) para aritmética circular do alfabeto
- Manipulação de arquivos (`fopen`, `fprintf`, `fclose`)

## Como executar

Compile com qualquer compilador C, por exemplo:

```bash
gcc cifras_de_cesar_V2.c -o cifra
./cifra
```

## Exemplo de execução

**Entrada:**
Shift: 3
Palavra: coracao
Sequência: Fibonacci

**Saída esperada (arquivo gerado):**
Palavra codificada: gswgkle | SHIFT: 3 | Tipo: 4 | Letras: 7
