#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int matricula;
    char nome[80];
    char turma;
    float nota1;
    float nota2;
    float media;
    char situacao[20];
} Aluno;

typedef struct {
    char turma;
    char data[11];
    char evento[100];
} Evento;

// Listas de alunos e eventos
Aluno turmaA[10], turmaB[10], turmaC[10];
Evento agenda[30];

// Contadores
int contA = 0, contB = 0, contC = 0, contEventos = 0;

// Função auxiliar para buscar aluno por matrícula
Aluno* BuscarAluno(int mat) {
    int i;
    for (i = 0; i < contA; i++) if (turmaA[i].matricula == mat) return &turmaA[i];
    for (i = 0; i < contB; i++) if (turmaB[i].matricula == mat) return &turmaB[i];
    for (i = 0; i < contC; i++) if (turmaC[i].matricula == mat) return &turmaC[i];
    return NULL;
}

void CadastrarAluno() {
    Aluno a;
    printf("Digite a matrícula (5 dígitos): ");
    scanf("%d", &a.matricula);

    // Verificar se matrícula já existe
    if (BuscarAluno(a.matricula) != NULL) {
        printf("Erro: Já existe um aluno com essa matrícula!\n");
        return;
    }

    printf("Nome completo: ");
    fflush(stdin);
    fgets(a.nome, sizeof(a.nome), stdin);
    a.nome[strcspn(a.nome, "\n")] = 0;

    printf("Turma (A/B/C): ");
    scanf(" %c", &a.turma);
    a.nota1 = 0;
    a.nota2 = 0;
    a.media = 0;
    strcpy(a.situacao, "PENDENTE");

    switch(a.turma) {
        case 'A':
        case 'a':
            if (contA < 10) turmaA[contA++] = a;
            else printf("Turma A cheia!\n");
            break;
        case 'B':
        case 'b':
            if (contB < 10) turmaB[contB++] = a;
            else printf("Turma B cheia!\n");
            break;
        case 'C':
        case 'c':
            if (contC < 10) turmaC[contC++] = a;
            else printf("Turma C cheia!\n");
            break;
        default:
            printf("Turma inválida!\n");
    }
}


void CadastrarNota() {
    int mat;
    float n1, n2;
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &mat);
    Aluno* a = BuscarAluno(mat);
    if (a == NULL) {
        printf("Aluno não encontrado!\n");
        return;
    }
    printf("Nota 1: ");
    scanf("%f", &n1);
    printf("Nota 2: ");
    scanf("%f", &n2);
    a->nota1 = n1;
    a->nota2 = n2;
    a->media = (n1 + n2) / 2;
    if (a->media >= 7) strcpy(a->situacao, "APROVADO");
    else strcpy(a->situacao, "REPROVADO");
}

void ConsultarAluno() {
    int mat;
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &mat);
    Aluno* a = BuscarAluno(mat);
    if (a == NULL) {
        printf("Aluno não encontrado!\n");
        return;
    }
    printf("\nMatrícula: %d\n", a->matricula);
    printf("Nome: %s\n", a->nome);
    printf("Turma: %c\n", a->turma);
    printf("Nota 1: %.2f\n", a->nota1);
    printf("Nota 2: %.2f\n", a->nota2);
    printf("Média: %.2f\n", a->media);
    printf("Situação: %s\n", a->situacao);
}

void IncluirAgenda() {
    Evento e;
    printf("Turma (A/B/C): ");
    scanf(" %c", &e.turma);
    printf("Data (DD/MM/AAAA): ");
    scanf("%s", e.data);
    printf("Ocasião: ");
    fflush(stdin);
    fgets(e.evento, sizeof(e.evento), stdin);
    e.evento[strcspn(e.evento, "\n")] = 0;
    if (contEventos < 30) agenda[contEventos++] = e;
    else printf("Agenda cheia!\n");
}

void ImprimirAgenda() {
	setlocale(LC_ALL, "Portuguese");
    int i;
    printf("\n========== AGENDA ==========\n");
    for (i = 0; i < contEventos; i++) {
        printf("Turma: %c | Data: %s | Evento: %s\n", agenda[i].turma, agenda[i].data, agenda[i].evento);
    }
    if (contEventos == 0) printf("Nenhum evento registrado.\n");
}

void ImprimirTurma() {
	setlocale(LC_ALL, "Portuguese");
    char turma;
    printf("Digite a turma (A/B/C): ");
    scanf(" %c", &turma);
    int i;
    printf("\n========== ALUNOS DA TURMA %c ==========\n", turma);
    if (turma == 'A' || turma == 'a') {
        for (i = 0; i < contA; i++) {
            printf("Matrícula: %d | Nome: %s | Situação: %s\n", turmaA[i].matricula, turmaA[i].nome, turmaA[i].situacao);
        }
        if (contA == 0) printf("Nenhum aluno na turma A.\n");
    } else if (turma == 'B' || turma == 'b') {
        for (i = 0; i < contB; i++) {
            printf("Matrícula: %d | Nome: %s | Situação: %s\n", turmaB[i].matricula, turmaB[i].nome, turmaB[i].situacao);
        }
        if (contB == 0) printf("Nenhum aluno na turma B.\n");
    } else if (turma == 'C' || turma == 'c') {
        for (i = 0; i < contC; i++) {
            printf("Matrícula: %d | Nome: %s | Situação: %s\n", turmaC[i].matricula, turmaC[i].nome, turmaC[i].situacao);
        }
        if (contC == 0) printf("Nenhum aluno na turma C.\n");
    } else {
        printf("Turma inválida.\n");
    }
}
