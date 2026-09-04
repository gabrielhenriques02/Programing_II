#include <stdio.h>
#include "data.h"

#define YEAR 365
#define LEAP_YEAR 366

int verificaDataValida(int dia, int mes, int ano) {
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
            else {
                if (dia > 30) {
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
            else {
                if (dia > 30) {
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
        else {
            return -1;
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
            else {
                if (dia > 30) {
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
            else {
                if (dia > 30) {
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
        else {
            return -1;
        }
    }
    else {
        return 1;
    }
}

/**
 * @brief Imprime uma data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano) {
    if (dia < 10) {
        if (mes < 10) {
            printf("0%d/0%d/%d", dia, mes, ano);
        }
        else {
            printf("0%d/%d/%d", dia, mes, ano);
        }
    }
    else {
        if (mes < 10) {
            printf("%d/0%d/%d", dia, mes, ano);
        }
        else {
            printf("%d/%d/%d", dia, mes, ano);
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
    char meses[12][100] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
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
    if (0 < dia && dia < 10) {
        printf("0%i de ", dia);
        imprimeMesExtenso(mes);
        printf(" de %i\n", ano);
    }
    else {
        printf("%i de ", dia);
        imprimeMesExtenso(mes);
        printf(" de %i\n", ano);
    }
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
int numeroDiasMes(int mes, int ano) {
    //contador dos dias que o mes irá receber
    int contDias = 0;
    //fevereiro 28 dias
    if (verificaBissexto(ano) == 0) {
        for (int i = 1; i < 13; i++) {
            if (mes == i) {
                if (i > 0 && i < 8 && i != 2) {
                    if (i % 2 == 1) {
                        contDias += 31;
                        return contDias;
                    }
                    else {
                        contDias += 30;
                        return contDias;
                    }
                }
                else if (i > 7 && i < 13) {
                    if (i % 2 == 1) {
                        contDias += 30;
                        return contDias;
                    }
                    else {
                        contDias += 31;
                        return contDias;
                    }
                }
                else {
                    contDias += 28;
                    return contDias;
                }
            }
        }
        if (contDias == 0) {
            return -1;
        }
        else {
            return -1;
        }
    }
    else {
        for (int i = 1; i < 13; i++) {
            if (mes == i) {
                if (i > 0 && i < 8 && i != 2) {
                    if (i % 2 == 1) {
                        contDias += 31;
                        return contDias;
                    }
                    else {
                        contDias += 30;
                        return contDias;
                    }
                }
                else if (i > 7 && i < 13) {
                    if (i % 2 == 1) {
                        contDias += 30;
                        return contDias;
                    }
                    else {
                        contDias += 31;
                        return contDias;
                    }
                }
                else {
                    contDias += 29;
                    return contDias;
                }
            }
        }
        if (contDias == 0) {
            return -1;
        }
        else {
            return -1;
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
    return diasAteMes;
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
    /*
    diffDias: diferença total de dias entre as datas (valor  a ser retornado)
    menorAno: ano arbitrado como o menor para a recursao do ultimo if funcionar
    */
    int dias1 = 0, dias2 = 0, diffDias = 0, menorAno = ano2;
    //mesma data -> diffDias continua 0
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0) {
        return diffDias;
    }
    //quando as datas de entrada obedecem o esperado: ano2 no passado em relação à ano 1.
    else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
        /*
        quando as datas estao no mesmo ano, calculamos apenas a diferença entre os tempo decorrido naquele ano ate a data,
        utilizando a função calcula dias ate mes
        */
        if (ano2 == ano1) {
            //dias contados ate data1
            dias1 = calculaDiasAteMes(mes1, ano1) + dia1;
            //dias ate data 2
            dias2 = calculaDiasAteMes(mes2, ano2) + dia2;
            diffDias = dias1 - dias2;
            return diffDias;
        }
        //se nao estao no mesmo ano...
        else if (ano2 < ano1) {
            /*
            existe sempre uma diferença base: dias que faltam para acabar ano2 e dias decorridos do inicio de ano1 ate data1.
            dias para acabar ano2 depende se ano2 é ou não bissexto.
            a partir dessa diferença base incrementamos uma quantidade de dias relativa anos completos (365 ou 366 dias) que
            existem no intervalo nao inclusivo entre ano2 e ano1
            */
            dias1 = calculaDiasAteMes(mes1, ano1) + dia1;
            if (verificaBissexto(ano2) == 1) {
                //calcula dias que faltam para acabar ano2
                dias2 = LEAP_YEAR - (calculaDiasAteMes(mes2, ano2) + dia2);
                //define a diferença base
                diffDias = dias2 + dias1;
                //incrementa se existirem anos compeletos no intervalo nao inclusivo entre ano2 e ano1
                while (menorAno + 1 < ano1) {
                    if (verificaBissexto(menorAno + 1) == 1) {
                        diffDias += LEAP_YEAR;
                        menorAno++;
                    }
                    else {
                        diffDias += YEAR;
                        menorAno++;
                    }
                }
                return diffDias;
            }
            else {
                //calcula dias que faltam para acabar ano2
                dias2 = YEAR - (calculaDiasAteMes(mes2, ano2) + dia2);
                //define a diferença base
                diffDias = dias2 + dias1;
                //incrementa se existirem anos compeletos no intervalo nao inclusivo entre ano2 e ano1
                while (menorAno + 1 < ano1) {
                    if (verificaBissexto(menorAno + 1) == 1) {
                        diffDias += LEAP_YEAR;
                        menorAno++;
                    }
                    else {
                        diffDias += YEAR;
                        menorAno++;
                    }
                }
                return diffDias;
            }
        }
        else {
            return -1;
        }
    }
    //recursão para o caso das data maior ser colocada na entrada final
    else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1) {
        return calculaDiferencaDias(dia2, mes2, ano2, dia1, mes1, ano1);
    }
    else {
        return -1;
    }
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano) {
    //contadores para marcar a proxima data
    int proxDia = dia, proxMes = mes, proxAno = ano;

    if (verificaBissexto(ano) == 0) {
        if (mes == 12) {
            if (dia == 31) {
                proxDia = 1;
                proxMes = 1;
                proxAno++;
            }
            else {
                proxDia++;
            }
        }
        else if ((7 < mes && mes < 12 && mes % 2 == 0) || (0 < mes && mes < 8 && mes != 2 && mes % 2 == 1)) {
            if (dia == 31) {
                proxDia = 1;
                proxMes++;
            }
            else {
                proxDia++;
            }
        }
        else if ((7 < mes && mes < 12 && mes % 2 == 1) || (0 < mes && mes < 8 && mes != 2 && mes % 2 == 0)) {
            if (dia == 30) {
                proxDia = 1;
                proxMes++;
            }
            else {
                proxDia++;
            }
        }
        else {
            if (dia == 28) {
                proxDia = 1;
                proxMes++;
            }
            else {
                proxDia++;
            }
        }
    }
    else {
        if (mes == 12) {
            if (dia == 31) {
                proxDia = 1;
                proxMes = 1;
                proxAno++;
            }
            else {
                proxDia++;
            }
        }
        else if ((7 < mes && mes < 12 && mes % 2 == 0) || (0 < mes && mes < 8 && mes != 2 && mes % 2 == 1)) {
            if (dia == 31) {
                proxDia = 1;
                proxMes++;
            }
            else {
                proxDia++;
            }
        }
        else if ((7 < mes && mes < 12 && mes % 2 == 1) || (0 < mes && mes < 8 && mes != 2 && mes % 2 == 0)) {
            if (dia == 30) {
                proxDia = 1;
                proxMes++;
            }
            else {
                proxDia++;
            }
        }
        else {
            if (dia == 29) {
                proxDia = 1;
                proxMes++;
            }
            else {
                proxDia++;
            }
        }
    }

    imprimeData(proxDia, proxMes, proxAno);
}