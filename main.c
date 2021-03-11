/*
 ============================================================================
 Name        : main.c
 Author      : Felipe Costa
 Version     : 0.5
 Copyright   :
 Description : Principal
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_linkedlist.h"
#include "bub.c"

// Exibe o comando de entrada
void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
  Node *L=NULL, *aux = NULL;
  int tam=0;
  char input[201];


	while(1) {

		printf("prompt>");


		// Entrada de dados ---------------------------------------------#
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		// Saída do Sistema ---------------------------------------------#
		if (strncmp(input, "exit\n", 5) == 0) {
      showList(L);
      printf("%d\n", strncmp(input, "exit\n", 5) == 0);
      printf("Leaving. Good bye.\n");
			break;
		}

		// Verifica Comando de Adição ao Inicio da Lista --------------------------#
    if (strncmp(input, "begin\n", 5) == 0) {
      tam++; // Incrementa Info com Tamanho da Lista
      insertAtBeginning(&L,(int)input[6]-48); // Adiciona Novos Elementos
      showList(L); // Exibe Lista completa com o novo elemento
			printf("| %d", tam);
    }

		// Verifica Comando de Adição ao Fim da Lista --------------------------#
    if (strncmp(input, "put\n", 3) == 0) {
      tam++; // Incrementa Info com Tamanho da Lista
      insertAtEnd(&L,(int)input[4]-48); // Adiciona Novos Elementos
      showList(L); // Exibe Lista completa com o novo elemento
			printf("| %d", tam);
    }

		// Verifica Comando de Adição ao Meio da Lista --------------------------#
    if (strncmp(input, "middle\n", 6) == 0) {
      insertMiddle(&L,(int)input[7]-48, (int)input[9]-48, &tam); // Adiciona Novos Elementos
      showList(L); // Exibe Lista completa com o novo elemento
			printf("| %d", tam);
    }


		// Comando Para Remoção de Elemento --------------------------#
		if (strncmp(input, "remove\n", 6) == 0) {
      	deleteDADOS(&L, (int)input[7]-49, &tam);
				showList(L);
    }

		// Comando Para Remoção de Todos os Elementos --------------------------#
		if (strncmp(input, "clear\n", 5) == 0) {
      	deleteAllNodes(&L); tam=0;
				showList(L);
    }

		// Comando para listagem dos valores -------------------------#
		if (strncmp(input, "list\n", 4) == 0) {
			showList(L);
    }


		// Exibe Primeiro Elemento -----------------------------------#
    if (strncmp(input, "first\n", 5) == 0) showElement(L, 0);

		// Exibe Ultimo Elemento--------------------------------------#
    if (strncmp(input, "last\n", 4) == 0) showElement(L, tam-1);

		// Exibe Único Elemento Solicitado ---------------------------#
    if (strncmp(input, "get\n", 3) == 0) showElement(L, (int)input[4]-49);

		// Exibe Único Elemento Solicitado ---------------------------#
    if (strncmp(input, "con\n", 3) == 0) showConElements(L, (int)input[4]-49, (int)input[6]-49);

		// Salva Lista -----------------------------------------------#
    if (strncmp(input, "save\n", 4) == 0) saveList(L, (int)input[5]-49, (int)input[7]-49);

		// Abre Lista Salva ------------------------------------------#
    if (strncmp(input, "open\n", 4) == 0) openList(&L, (int)input[5]-49);



    // Ordena a Lista ---------------------------------------------#
    if (strncmp(input, "sort\n", 4) == 0) {
      if (L != NULL) bubbleSort(L);
			showList(L);
    }
		printf("\n");
	}

	return EXIT_SUCCESS;
}
