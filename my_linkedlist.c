// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

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
  while (c != pos) {
    c++;
    node = node->next;
  }
  printf("%d", node->entrada);
}
