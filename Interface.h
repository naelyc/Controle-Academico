// Interface.h
#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

int opMenu, opCad, opImp;

void MenuPrincipal() {
	setlocale(LC_ALL, "Portuguese");
    printf("===============================================\n");
    printf("         SISTEMA DE CONTROLE ACADEMICO         \n");
    printf("===============================================\n");
    printf("       1 - Cadastro de Aluno                   \n");
    printf("       2 - Cadastro de Nota                    \n");
    printf("       3 - Consultar Aluno                     \n");
    printf("       4 - Impressões                          \n");
    printf("       5 - Incluir Evento na Agenda            \n");
    printf("       0 - Sair                                \n");
    printf("===============================================\n");
    printf("Escolha: ");
    scanf("%i", &opMenu);
}

void MenuCadastro() {
    system("cls");
    CadastrarAluno();
    system("pause");
    system("cls");
}

void MenuNotas() {
    system("cls");
    CadastrarNota();
    system("pause");
    system("cls");
}

void MenuConsulta() {
    system("cls");
    ConsultarAluno();
    system("pause");
    system("cls");
}

void MenuAgenda() {
    system("cls");
    IncluirAgenda();
    system("pause");
    system("cls");
}

void MenuImpressao() {
    printf("===============================================\n");
    printf("              MENU DE IMPRESSAO                \n");
    printf("===============================================\n");
    printf("       1 - Imprimir Agenda                     \n");
    printf("       2 - Imprimir Turma                      \n");
    printf("       3 - Voltar                              \n");
    printf("===============================================\n");
    printf("Escolha: ");
    scanf("%i", &opImp);

    switch(opImp) {
        case 1:
            system("cls");
            ImprimirAgenda();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            ImprimirTurma();
            system("pause");
            system("cls");
            break;
        default:
            system("cls");
            break;
    }
}
