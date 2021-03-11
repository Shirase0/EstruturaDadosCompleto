/*
 ============================================================================
 Name        : my_linkedlist.h
 Author      : Shirase
 Version     : 0.5
 Copyright   :
 Description : Linked List Operations Functions Declaration
 ============================================================================
 */

#ifndef MY_LINKEDLIST
#define MY_LINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include "my_linkedlist.c"


// ref: Elemento qur Encabeça a Lista Ligada
void insertAtBeginning(Node** ref, int data);

// Insere Elemento Depois de Outro
void insertAfter(Node* node, int data);

// Insere Elemento Após Posição Definida
void insertMiddle (Node** ref, int pos, int data, int *tam);

// Isere Elemento ao Fim da Lista
void insertAtEnd(Node** ref, int data);

// Remove dado na posição específica
void deleteDADOS(Node** ref, int pos, int * tam);

// Remove todos os nós
void deleteAllNodes(Node** ref);

// Exibe Lista Completa
void showList(Node* node);

// Exibe Elemento Definido
void showElement(Node* node, int pos);

// Exibe Conjunto de Elementos
void showConElements(Node* node, int pos, int fim);

// Salva Lista em Arquivo txt
void saveList(Node* node, int pos, int fim);

// Abre Lista em Arquivo txt
void openList(Node** node, int local);

// Exibe Listas Salvas
void showSavedLists(Node* node);

#endif
