/*
   ============================================================================
   Name        : my_linkedlist.c
   Author      : Shirase
   Version     : 0.5
   Copyright   :
   Description : Linked List Operations in C
   ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "my_linkedlist.h"


// Create a node
typedef struct Node {
        int entrada;
        struct Node * next;
}Node;


// ref: Elemento qur Encabeça a Lista Ligada
void insertAtBeginning(Node** ref, int data) {
        // Allocate memory to a node
        Node* new_node = (Node*)malloc(sizeof(Node));

        // insert the entrada
        new_node->entrada = data;
        new_node->next = (*ref);

        // Move head to new node
        (*ref) = new_node;

}

// Insert a node after a node
void insertAfter(Node* node, int data) {
        if (node == NULL) {
                printf("the given previous node cannot be NULL");
                return;
        }

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->entrada = data;
        new_node->next = node->next;
        node->next = new_node;
}

void insertMiddle (Node** ref, int pos, int data, int *tam){
        Node *temp = *ref, *prev; // temp armazeda head da lista
        int c = 0; // contador de posições
        printf("%d\n", pos);

        if(pos <= 0) {
                printf("Posicao %d não existe.", pos);
                return;
        }
        // Procura posição para deletar
        while (temp != NULL && c != pos-1) {
                c++; // Incremnta posição
                prev = temp;
                temp = temp->next;
        }
        //printf("%d\n", temp->entrada);
        if (temp == NULL) {
                printf("the given previous node cannot be NULL.\n");
                return;
        }

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->entrada = data;
        new_node->next = temp->next;
        temp->next = new_node;
        ++*tam;

}


void insertAtEnd(Node** ref, int data) {
        Node* new_node = (Node*)malloc(sizeof(Node)); // Aloca memória novo Node
        Node* last = *ref; // referêcia é head da lista, armazenado em last

        new_node->entrada = data; // Adiciona os dados ao Node
        new_node->next = NULL; // Verifica se o próximo é nulo

        if (*ref == NULL) { // Verifica se a referência já encabeça a lista
                *ref = new_node; // Adiciona o Primeiro Elemento
                return; // Finaliza a rotina
        }

        // Caminha até último elemento
        while (last->next != NULL) // Detecta Ponteiro para NULL no último elemento
                last = last->next; // Referencia o endereço para o próximo na sequência

        last->next = new_node; // Adiocna o Node criado ao fim da fila
        return;
}


void deleteDADOS(Node** ref, int pos, int * tam) {
        struct Node *temp = *ref, *prev; // temp armazeda head da lista

        int c = 0; // contador de posições

        // Deleta primeira posição
        if (temp != NULL && c == pos) { // Verifica se Existe posição 0
                --*tam; // Decrementa Total de elementos
                *ref = temp->next; //
                free(temp); // libera memória alocada
                return;
        }

        // Procura posição para deletar
        while (temp != NULL && c != pos) {
                c++; // Incremnta posição
                prev = temp;
                temp = temp->next;
        }

        // Verifica se posição existe
        if (temp == NULL) return;

        // Remove Node
        prev->next = temp->next;
        --*tam;
        free(temp); // Libera Memória Alocada
}



// Remove todos os nós
void deleteAllNodes(Node** ref) {
        Node *temp = *ref, *prox;

        // Percorre lista completa liberando todos os nós
        while (temp != NULL) {
                prox = temp->next; // armazena próxima posição
                free(temp); // libera memória alocada
                temp = prox; // prepara próximo a ser deletado no retorno do loop
        }
        *ref = NULL;
}

// Exibe Lista Completa
void showList(Node* node) {
        if (node == NULL) printf("Lista Vazia!");
        while (node != NULL) {
                printf("%d ", node->entrada);
                node = node->next;
        }
}

// Exibe Elemento Definido
void showElement(Node* node, int pos) {
        int c = 0;

        if (node == NULL) printf("Lista Vazia!");
        while (c != pos && node != NULL) {
                c++;
                node = node->next;
        }
        if (node == NULL) {
                printf("Posicao %d nao existe.", pos+1);
                return;
        }
        printf("%d", node->entrada);
}


// Mostra Conjunto de Elementos
void showConElements(Node* node, int pos, int fim){
      int c = 0;

      if (node == NULL) {printf("Lista Vazia!"); return;}
      while (c != fim+1) {
            if (node == NULL){
              printf("\nPosicao %d nao existe.", c);
              return;
            }
            if (c >= pos) printf("%d ", node->entrada);
            c++;
            node = node->next;
          }
}


// Salva Lista Com Elementos Atuais
void saveList(Node* node, int pos, int fim){
      FILE *fp;

      // Verifica Localização do Programa
      char * localDir = getenv("PWD");
      printf("\nOpen work in current dir:\n %s\n",(localDir!=NULL) ? localDir : "getenv returned NULL");

      // Cria Arquivo com a Lista
      strcat(localDir, "/list.txt");
      fp = fopen(localDir, "a+");
      if (fp == NULL)
            exit(EXIT_FAILURE);

      if (node == NULL) printf("Lista Vazia!");
      while (node != NULL) {
              fprintf(fp, "%d ",node->entrada);
              node = node->next;
      }
      fprintf(fp, "\n");
      fclose(fp);

}

void openList(Node** node, int local){

      FILE * fp;
      char * line = NULL;
      size_t len = 0;
      ssize_t read;
      int c = 0;

      // Verifica Localização do Programa
      char * localDir = getenv("PWD");
      printf("\nOpen work in current dir:\n %s\n",(localDir!=NULL) ? localDir : "getenv returned NULL");

      // Abre Arquivo
      strcat(localDir, "/list.txt");
      fp = fopen(localDir, "r+");
      if (fp == NULL)
            exit(EXIT_FAILURE);

      while ((read = getline(&line, &len, fp)) != -1 ) {
          if (c == local){
                printf("Retrieved line of length %zu:\n", read);
                printf("%s", line);
                break;
              }
          c++;
      }

      c = 0;
      while (c < read-1 ){
            insertAtEnd(node,(int)line[c]-48); // Adiciona Novos Elementos
            c+=2;
      }

      fclose(fp);
      if (line)
          free(line);

}

void showSavedLists(Node* node){

      FILE * fp;
      char * line = NULL;
      size_t len = 0;
      ssize_t read;

      // Verifica Localização do Programa
      char * localDir = getenv("PWD");
      printf("\nOpen work in current dir:\n %s\n", (localDir!=NULL) ? localDir : "getenv returned NULL");

      // Abre Arquivo
      strcat(localDir, "/list.txt");
      fp = fopen(localDir, "r+");
      if (fp == NULL)
            exit(EXIT_FAILURE);

      while ((read = getline(&line, &len, fp)) != -1 ) {
          printf("Retrieved line of length %zu:\n", read);
          printf("%s", line);
          // c++;
      }

      fclose(fp);
      if (line)
          free(line);

}
