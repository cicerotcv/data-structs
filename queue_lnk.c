#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _queue_int {
    node *first;
    node *last;
};

queue_int *queue_int_new() {
    queue_int *new = malloc(sizeof(queue_int));
    new->first = NULL;
    new->last = NULL;
    return new;
}
int queue_int_empty(queue_int *q) { return q->last == NULL; }

void queue_int_put(queue_int *q, int value) {
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;

    if (queue_int_empty(q)) {
        q->first = new;
    } else {
        q->last->next = new;
    }
    q->last = new;
}

int queue_int_get(queue_int *q) {
    node *current = q->first;    // guarda endereço do primeiro node
    int value = current->value;  // guarda o valor dele
    q->first = current->next;    // o primeiro node da fila se torna o próximo
    if (q->first == NULL) {      // se o primeiro for NULL
        q->last = NULL;          // o último também é
    }
    free(current);  // desalocamos a memória
    return value;
}

void queue_int_delete(queue_int **_q) {
    queue_int *q = *_q;
    node *n = q->first;
    while (n != NULL) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(q);
    *_q = NULL;
}

int main() {
    queue_int *q = queue_int_new();

    queue_int_put(q, 1);
    queue_int_put(q, 2);
    queue_int_get(q);
    queue_int_put(q, 3);
    queue_int_put(q, 4);

    while (!queue_int_empty(q)) {
        int value = queue_int_get(q);
        printf("value: %d\n", value);
    }

    queue_int_delete(&q);

    return 0;
}