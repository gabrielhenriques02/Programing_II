#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "operacao.h"

struct Agencia {
    tConta **contas;
    tOperacao **operacoes;
    int qtdContas;
    int qtdOperacoes;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */
tAgencia* CriaAgencia() {
    tAgencia *a = (tAgencia *) calloc(1, sizeof(tAgencia));
    a->contas = NULL;
    a->operacoes = NULL;
    a->qtdContas = a->qtdOperacoes = 0;
    return a;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia* agencia) {
    for (int i = 0; i < agencia->qtdContas; i++) {
        DestroiConta(agencia->contas[i]);
    }
    for (int i = 0; i < agencia->qtdOperacoes; i++) {
        DestroiOperacao(agencia->operacoes[i]);
    }
    DestroiConta(agencia->contas);
    DestroiOperacao(agencia->operacoes);
    //DestroiConta(agencia->contas);
    //DestroiOperacao(agencia->operacoes);
    free(agencia);
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia) {
    int qtdContasAloc = 0;
    int qtdOperacoesAloc = 0;
    scanf("%d\n", &agencia->qtdContas);

    while (qtdContasAloc < agencia->qtdContas) {
        int idConta;
        scanf("%d\n", &idConta);
        if (idConta > 0) {
            agencia->contas = (tConta **) realloc(agencia->contas, qtdContasAloc * sizeof(tConta *));
            agencia->contas[qtdContasAloc] = CriaConta(idConta);
            qtdContasAloc++;
        }
        else {
            printf("Digite um id valido para a conta a ser cadastrada!\n");
        }
    }

    
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta* BuscaContaPorId(tAgencia *agencia, int id);

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia* agencia);

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia);

/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia* agencia);