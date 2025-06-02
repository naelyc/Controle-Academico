// main.c
#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    do {
        MenuPrincipal();
        switch (opMenu) {
            case 1:
                MenuCadastro();
                break;
            case 2:
                MenuNotas();
                break;
            case 3:
                MenuConsulta();
                break;
            case 4:
                MenuImpressao();
                break;
            case 5:
                MenuAgenda();
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opMenu != 0);

    return 0;
}
