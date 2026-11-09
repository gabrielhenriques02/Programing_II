#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos) {
    int aprovados = 0;
    float somaNotas = 0;
    int totalGenM = 0;
    int totalGenF = 0;
    int totalGenO = 0;
    for (int i = 0; i < VectorSize(alunos); i++) {
        if (GetNotaAluno(VectorGet(alunos, i)) >= 6) {
            aprovados++;
        }
        if (GetGeneroAluno(VectorGet(alunos, i)) == 'M') {
            totalGenM++;
        }
        if (GetGeneroAluno(VectorGet(alunos, i)) == 'F') {
            totalGenF++;
        }
        if (GetGeneroAluno(VectorGet(alunos, i)) == 'O') {
            totalGenO++;
        }
        somaNotas += GetNotaAluno(VectorGet(alunos,i));
    }
    float percentM = ((float) totalGenM)/VectorSize(alunos);
    float percentF = ((float) totalGenF)/VectorSize(alunos);
    float percentO = ((float) totalGenO)/VectorSize(alunos);
    float percentAprov = ((float) aprovados)/VectorSize(alunos);
    float mediaNotas = ((float) somaNotas)/VectorSize(alunos);
    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", percentAprov*100);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", percentM*100);
    printf("Feminino: %.2f%%\n", percentF*100);
    printf("Outro: %.2f%%\n", percentO*100);
}