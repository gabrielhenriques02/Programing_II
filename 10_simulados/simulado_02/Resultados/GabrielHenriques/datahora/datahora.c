#include <stdio.h>
#include <stdlib.h>
#include "datahora.h"

int verificaBissexto(DataHora *d);
int verificaDiasMes(DataHora *d);

struct DataHora {
    int dia, mes, ano, hora, minuto;
};
/**
 * @brief   Cria uma data/hora a partir dos valores informados.
 *
 * @param dia     [entrada]  Dia do mês, inteiro em [1, 31] (válido para o mês/ano).
 * @param mes     [entrada]  Mês, inteiro em [1, 12].
 * @param ano     [entrada]  Ano com 4 dígitos (ex.: 2026), inteiro >= 1.
 * @param hora    [entrada]  Hora do dia, inteiro em [0, 23].
 * @param minuto  [entrada]  Minuto, inteiro em [0, 59].
 *
 * @return  Ponteiro para o DataHora criado (alocado dinamicamente);
 *          NULL se a alocação de memória falhar.
 *
 * @pre     Os valores formam uma data/hora válida (a função NÃO valida).
 * @post    O chamador é dono do DataHora retornado e deve liberá-lo com
 *          liberaDataHora() (ou transferir a posse para outro TAD que o libere).
 */
DataHora *criaDataHora(int dia, int mes, int ano, int hora, int minuto) {
    DataHora *d = (DataHora *) calloc(1, sizeof(DataHora));
    if (d != NULL) {
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
        d->hora = hora;
        d->minuto = minuto;
        return d;
    }
    else {
        return NULL;
    }
    
}

/**
 * @brief   Lê uma data/hora da entrada padrão e cria o DataHora correspondente.
 *
 * Lê UMA linha no formato "DD/MM/AAAA HH:MM" (data, um espaço, horário), por
 * exemplo "27/10/2026 08:05", consumindo também a quebra de linha final.
 *
 * @return  Ponteiro para o DataHora lido (mesmas regras de posse de criaDataHora()).
 *
 * @pre     A próxima linha da entrada padrão contém uma data/hora válida no formato
 *          acima.
 */
DataHora *lerDataHora() {
    int dia, mes, ano, hora, minuto;
    scanf("%d/%d/%d %d:%d\n", &dia, &mes, &ano, &hora, &minuto);
    DataHora *d = criaDataHora(dia, mes, ano, hora, minuto);
    return d;
}

/**
 * @brief   Calcula quantos minutos se passaram entre duas datas/horas.
 *
 * O cálculo considera o calendário real:
 *   - meses com 31 dias: 1, 3, 5, 7, 8, 10, 12; com 30 dias: 4, 6, 9, 11;
 *   - fevereiro tem 29 dias em ano bissexto e 28 nos demais;
 *   - um ano é bissexto se for divisível por 400, ou se for divisível por 4 e NÃO
 *     for divisível por 100 (ex.: 2028 e 2000 são bissextos; 2026 e 2100 não são);
 *   - cada dia tem 24 * 60 = 1440 minutos.
 * Exemplos:
 *   inicio = 27/10/2026 08:50, fim = 27/10/2026 10:05  ->  75
 *   inicio = 27/10/2026 23:30, fim = 28/10/2026 00:10  ->  40
 *   inicio = 28/02/2028 12:00, fim = 01/03/2028 12:00  ->  2880 (2028 é bissexto)
 *
 * @param inicio  [entrada]  Data/hora inicial (não-nula).
 * @param fim     [entrada]  Data/hora final (não-nula).
 *
 * @return  Diferença em minutos (fim - inicio). É >= 0 sempre que fim não for
 *          anterior a inicio.
 *
 * @pre     inicio != NULL e fim != NULL.
 * @note    Nenhuma das duas datas/horas é modificada ou liberada.
 */
int diferencaMinutosDataHora(DataHora *inicio, DataHora *fim) {
    int difMin = 0, difHoras = 0, difDias = 0;

    if (inicio != NULL && fim !=NULL) {
        DataHora *inicioCp = criaDataHora(inicio->dia, inicio->mes, inicio->ano, inicio->hora, inicio->minuto);
        difMin = 60 - inicioCp->minuto;
        difHoras = 24 - inicioCp->hora - 1;

        if (inicioCp->dia == fim->dia && inicioCp->mes == fim->mes && inicioCp->ano == fim->ano) {
            if (inicioCp->hora == fim->hora) { //1
                liberaDataHora(inicioCp);
                return fim->minuto - inicio->minuto;
            }
            else if (inicioCp->hora + 1 == fim->hora) { //2
                liberaDataHora(inicioCp);
                return (difMin + fim->minuto);
            }
            else { //3
                liberaDataHora(inicioCp);
                return (fim->hora - inicio->hora - 1)*60 + (difMin + fim->minuto);
            }
        }

        if (inicioCp->dia != fim->dia && inicioCp->mes == fim->mes && inicioCp->ano == fim->ano) { //4
            liberaDataHora(inicioCp);
            return (fim->dia - inicio->dia - 1)*24*60 + (difHoras + fim->hora)*60 + (difMin + fim->minuto);
        }

        while(inicioCp->mes != fim->mes || inicioCp->ano != fim->ano) { //5
            difDias += verificaDiasMes(inicioCp) - inicioCp->dia;
            if (inicioCp->mes == 12) {
                inicioCp->dia = 0;
                inicioCp->mes = 1;
                inicioCp->ano++;
            }
            else {
                inicioCp->dia = 0;
                inicioCp->mes++;
            }
        }

        liberaDataHora(inicioCp);
        return (difDias + fim->dia - 1)*24*60 + (difHoras + fim->hora)*60 + (difMin + fim->minuto);
    }
    else {
        return -1;
    }
}

/**
 * @brief   Imprime a data/hora na saída padrão no formato "DD/MM/AAAA HH:MM".
 *
 * Dia, mês, hora e minuto são impressos SEMPRE com dois dígitos e o ano com quatro
 * (zeros à esquerda quando necessário). Ex.: "05/03/2027 08:05". Há exatamente um
 * espaço entre a data e o horário. NÃO imprime quebra de linha nem espaços
 * antes/depois.
 *
 * @param dh  [entrada]  Data/hora a imprimir (não-nula).
 * @pre     dh != NULL.
 */
void imprimeDataHora(DataHora *dh) {
    if (dh != NULL) {
        printf("%02d/%02d/%04d %02d:%02d", dh->dia, dh->mes, dh->ano, dh->hora, dh->minuto);
    }
}
/**
 * @brief   Libera a memória alocada para uma data/hora.
 *
 * @param dh  [entrada]  Data/hora a liberar.
 * @post    A memória apontada por dh é liberada; o ponteiro não deve mais ser usado.
 */
void liberaDataHora(DataHora *dh) {
    free(dh);
}

int verificaBissexto(DataHora *d) {
    if ((d->ano % 400 == 0) || (d->ano % 4 == 0 && d->ano % 100 != 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

int verificaDiasMes(DataHora *d) {
    int mes30[4] = {4, 6, 9, 11};
    int mes31[7] = {1, 3, 5, 7, 8, 10, 12};
    if (verificaBissexto(d) == 1) {
        if (d->mes == 2) {
            return 29;
        }
    }
    else {
        if (d->mes == 2) {
            return 28;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (d->mes == mes30[i]) {
            return 30;
        }
    }
    for (int i = 0; i < 7; i++) {
        if (d->mes == mes31[i]) {
            return 31;
        }
    }
    return -1;
}