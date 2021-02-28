/*
 ============================================================================
 Name        : bub.c
 Author      : Felipe Costa Garcia
 Version     :
 Copyright   :
 Description : BubbleSort
 ============================================================================
 */

// Implementação do BubbleSort
#include <stdio.h>
#include <stdlib.h>
// #include "my_linkedlist.c"


// Declaração da Função de Bubble SOrt
void bubbleSort(Node *inicio);

/* Function to swap entrada of two nodes a and b*/
void swap(Node *a, Node *b);


/* Bubble sort the given linked list */
void bubbleSort(Node *inicio)
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;

    /* Checking for empty list */
    if (inicio == NULL) // Verifica se existe elemento 0
        return;

    do
    {
        swapped = 0;
        ptr1 = inicio; //  Recebe Inicio da Lista Solicitada Para Ordenação

        while (ptr1->next != lptr) // Enquanto Houver elementos na Lista
        {
            if (ptr1->entrada > ptr1->next->entrada) // Verifica Qual o Maior Elemento
            {
                swap(ptr1, ptr1->next); // Chama Swap Para Troca
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


void swap(Node *a, Node *b)
{
    int temp = a->entrada; // Temporio, armazena o dado antes da troca
    a->entrada = b->entrada; // troca de posição
    b->entrada = temp; // Recebe valor anteriormente em a
}
