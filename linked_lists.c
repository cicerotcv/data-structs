#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _linked_list {
    node *first;
};

linked_list *linked_list_new() {
    linked_list *l = malloc(sizeof(linked_list));
    l->first = NULL;
    return l;
}
int linked_list_empty(linked_list *l) { return l->first == NULL; }

void linked_list_insert_end(linked_list *l, int value) {
    node *new = malloc(sizeof(node));  // alocação de memória para um novo nó;
    new->next = NULL;                  // próximo é NULL
    new->value = value;                // atribuição do valor

    if (l->first == NULL) {  // se a lista está vazia
        l->first = new;      // o primeiro elemento é criado
        return;              // interrompe a execução
    }

    node *element = l->first;        // iteração sobre a lista
    while (element->next != NULL) {  // até que o próximo elemento seja NULL
        element = element->next;
    }
    element->next = new;  // guardamos o novo elemento no lugar dele
}

int linked_list_insert_at(linked_list *l, int value, int index) {
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;

    if (l->first == NULL) {
        l->first = new;
        return 0;
    }

    if (index == 0) {
        new->next = l->first;
        l->first = new;
        return 0;
    }

    node *el = l->first;

    int i = 0;
    while (i < index - 1 && el->next != NULL) {
        el = el->next;
        i++;
    }
    node *next = el->next;
    new->next = next;
    el->next = new;
    return i;
}

int linked_list_size(linked_list *l) {
    node *current = l->first;
    int size = 0;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

int linked_list_get(linked_list *l, int index) {
    int i = 0;                    // contador
    node *element = l->first;     // iterador
    while (i < index) {           // supor que index é menor o tamanho da lista
        element = element->next;  // avança na list
        i++;                      // avança no contador
    }
    return element->value;  // devolve o elemento n posição 'i'
}
void linked_list_remove(linked_list *l, int index) {
    if (index == 0) {
        node *first = l->first;
        l->first = first->next;
        free(first);
        first = NULL;
        return;
    }

    int i = 0;
    node *previous = l->first;
    while (i < index - 1) {
        previous = previous->next;
        i++;
    }
    // o loop termina no elemento anterior ao que queremos remover
    node *el = previous->next;
    previous->next = el->next;
    free(el);
}

void linked_list_delete(linked_list **_l) {
    linked_list *l = *_l;      // guardamos o endereço da lista
    node *n = l->first;        // começamos a iterar sobre a lista
    while (n != NULL) {        // até que o elemento seja NULL
        node *next = n->next;  // guardamos o endereço do próximo
        free(n);               // desalocamos o espaço do atual
        n = next;              // avançamos na lista
    }                          //
    free(l);                   // desalocamos a lista
    *_l = NULL;                // limpamos o endereço da variável local
}

void print_list(linked_list *list) {
    if (linked_list_empty(list)) {
        printf("[]\n");
    } else {
        printf("[");
        int size = linked_list_size(list);
        for (int i = 0; i < size - 1; i++) {
            printf(" %d,", linked_list_get(list, i));
        }
        printf(" %d", linked_list_get(list, size - 1));
        printf(" ]\n");
    }
}

int main() {
    linked_list *list = linked_list_new();

    linked_list_insert_end(list, 2);
    print_list(list);

    linked_list_insert_end(list, 3);
    print_list(list);

    linked_list_insert_end(list, 5);
    print_list(list);

    linked_list_insert_end(list, 6);
    print_list(list);

    linked_list_insert_at(list, 4, 2);  // inserir no meio
    print_list(list);

    linked_list_insert_at(list, 1, 0);  // inserir no começo
    print_list(list);

    int size = linked_list_size(list);

    linked_list_insert_at(list, size + 1, size);  // inserir no fim
    print_list(list);

    linked_list_remove(list, 0);  // remover do começo
    print_list(list);

    size = linked_list_size(list);
    linked_list_remove(list, size - 1);  // remover do fim
    print_list(list);

    linked_list_remove(list, 2);  // remover do meio
    print_list(list);

    linked_list_delete(&list);

    return 0;
}