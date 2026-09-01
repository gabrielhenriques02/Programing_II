#include "data.h"
#include <stdio.h>

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano) { //precisa testar e comentar
    if (ano < 1 ){
        return 0;
    }
    else if (mes < 1 || mes > 12) {
        return 0;
    }
    else if (verificaBissexto(ano) == 0) {
        if (mes > 0 && mes < 8 && mes != 2) {
            if (mes % 2 == 1) {
                if (dia > 31) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
        else if (mes > 7 && mes < 13) {
            if (mes % 2 == 0) {
                if (dia > 31) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
        else if (mes == 2) {
            if (dia > 28) {
                return 0;
            }
            else {
                return 1;
            }
        }
    }
    else if (verificaBissexto(ano) == 1) {
        if (mes > 0 && mes < 8 && mes != 2) {
            if (mes % 2 == 1) {
                if (dia > 31) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
        else if (mes > 7 && mes < 13) {
            if (mes % 2 == 0) {
                if (dia > 31) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
        else if (mes == 2) {
            if (dia > 29) {
                return 0;
            }
            else {
                return 1;
            }
        }
    }
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes){ //precisa testar
    //array com os meses
    char meses[12][10] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    //loop para verificar o mês que deve ser impresso
    for (int i = 0; i < 12; i++) {
        if (mes == i + 1) {
            printf("%s", meses[i]);
        }
    }

}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){ //precisa testar e comentar
    printf("%i de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %i\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){ //precisa testar e comentar
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano) { //precisa testar e comentar
    if (verificaBissexto(ano) == 0) {
        for (int i = 1; i < 13; i++) {
            if (mes == i) {
                if (i > 0 && i < 8 && i != 2) {
                    if (i % 2 == 1) {
                        return 31;
                    }
                    else {
                        return 30;
                    }
                }
                else if (i > 7 && i < 13) {
                    if (i % 2 == 1) {
                        return 30;
                    }
                    else {
                        return 31;
                    }
                }
                else if (i == 2) {
                    return 28;
                }
            }
        }
    }
    else {
        for (int i = 1; i < 13; i++) {
            if (mes == i) {
                if (i > 0 && i < 8 && i != 2) {
                    if (i % 2 == 1) {
                        return 31;
                    }
                    else {
                        return 30;
                    }
                }
                else if (i > 7 && i < 13) {
                    if (i % 2 == 1) {
                        return 30;
                    }
                    else {
                        return 31;
                    }
                }
                else if (i == 2) {
                    return 29;
                }
            }
        }
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){ //falta testar e comentar
    if (ano1 > ano2) {
        return 1;
    }
    else if (ano1 == ano2) {
        if (mes1 > mes2) {
            return 1;
        }
        else if (mes1 == mes2) {
            if (dia1 > dia2) {
                return 1;
            }
            else if (dia1 == dia2) {
                return 0;
            }
            else {
                return -1;
            }
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    //inicializa a contagem de dias com 0
    int diasAteMes = 0;
    //loop para incrementar os dias
    for(int i = 1; i < mes; i++) {
        diasAteMes += numeroDiasMes(i, ano);
    }
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int dias1 = 0, dias2 = 0;
    if (ano1 > ano2) { //falta pensar em como fazer isso aqui... 
        //dias contados em ano1
        dias1 = calculaDiasAteMes(mes1, ano1);
        //calcular dias que faltam para acabar ano2
        if (verificaBissexto(ano2) == 0) {
            dias2 = 365 - calculaDiasAteMes(mes2, ano2);
        }
        else {
            dias2 = 366 - calculaDiasAteMes(mes2, ano2);
        }
        //calcula dias para anos completos entre ano1 e ano2
        for (ano2; ano2 < ano1; ano2++) {

        }
    }
}