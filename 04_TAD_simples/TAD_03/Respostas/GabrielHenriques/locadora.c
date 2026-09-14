#include <stdio.h>
#include "locadora.h"

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora () {

    tLocadora l = {0};
    return l;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
    
    for (int i = 0; i < locadora.numFilmes; i++) {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
            return 1;
        }
        else {
            continue;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme) {

    if (!verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))) {
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
        printf("Filme cadastrado %d - ", obterCodigoFilme(filme));
        imprimirNomeFilme(filme);
        printf("\n");
        return locadora;
    }
    else {
        printf("Filme ja cadastrado no estoque.\n");
        return locadora;
    }
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora) {

    while (1) {

        int codigo;
        if (scanf("%d,", &codigo) == 1) {
            
            locadora = cadastrarFilmeLocadora(locadora, leFilme(codigo));
            continue;
        }
        else {
            break;
        }
    }

    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

    int filmesAlugados = 0, custoTotal = 0;

    for (int i = 0; i < quantidadeCodigos; i++) {

        if (!verificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    for (int i = 0; i < quantidadeCodigos; i++) {

        for (int j = 0; j < locadora.numFilmes; j++) {
            
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && obterQtdEstoqueFilme(locadora.filme[j]) > 0) {
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
                filmesAlugados++; //qtd filmes alugados
                custoTotal += locadora.filme[j].valor; // custo total
        
            }
            else if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && obterQtdEstoqueFilme(locadora.filme[j]) == 0) {
                printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                imprimirNomeFilme(locadora.filme[j]);
                printf(" nao disponivel no estoque. Volte mais tarde.\n");    
            }
        }
    }
    
    printf("Total de filmes alugados: %d com custo de R$%d\n", filmesAlugados, custoTotal);
    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora) {

    int codigos[MAX_FILMES] = {0};
    int quantidadeCodigos = 0, indexCodigo = 0;

    while (1) {

        int codigo = 0;

        if (scanf("%d\n", &codigo) == 1) {
            codigos[indexCodigo] = codigo;
            quantidadeCodigos++;
            indexCodigo++;
            continue;
        }
        else {
            break;
        }
    }

    return alugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

    for (int i = 0; i < quantidadeCodigos; i++) {

        if (!verificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    for (int i = 0; i < quantidadeCodigos; i++) {

        for (int j = 0; j < locadora.numFilmes; j++) {
            
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && obterQtdAlugadaFilme(locadora.filme[j]) != 0) {
                locadora.filme[j] = devolverFilme(locadora.filme[j]); //mensagem de sucesso?
                printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                imprimirNomeFilme(locadora.filme[j]);
                printf(" Devolvido!\n");
                locadora.lucro += locadora.filme[j].valor;
            }
            else if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) && obterQtdAlugadaFilme(locadora.filme[j]) == 0) {
                printf("Não e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[j]));
                imprimirNomeFilme(locadora.filme[j]);
                printf("\n");
            }
        }
    }
    
    return locadora;

}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora) {
    
    int codigos[MAX_FILMES] = {0};
    int quantidadeCodigos = 0, indexCodigo = 0;

    while (1) {

        int codigo;
        if (scanf("%d\n", &codigo) == 1) {
            codigos[indexCodigo] = codigo;
            quantidadeCodigos++;
            indexCodigo++;
            continue;
        }
        else {
            break;
        }
    }

    return devolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora) {

    tLocadora locadoraOrdenada = criarLocadora();
    locadoraOrdenada.lucro = locadora.lucro;
    locadoraOrdenada.numFilmes = locadora.numFilmes;

    for (int i = 0; i < locadora.numFilmes; i++) {

        int posicao = 0;

        for (int j = 0; j < locadora.numFilmes; j++) {

            if (compararNomesFilmes(locadora.filme[i], locadora.filme[j]) < 0) {
                posicao++;
            }
        }

        locadoraOrdenada.filme[locadora.numFilmes - 1 - posicao] = locadora.filme[i];
    }

    return locadoraOrdenada;

}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora) {

    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora.numFilmes; i++) {

        printf("%d - ", ordenarFilmesLocadora(locadora).filme[i].codigo);
        imprimirNomeFilme(ordenarFilmesLocadora(locadora).filme[i]);
        printf(" Fitas em estoque: %d\n", ordenarFilmesLocadora(locadora).filme[i].qtdEstoque);
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora) {
    if (locadora.lucro != 0) {
        printf("Lucro total R$%d\n", locadora.lucro);
    }
}