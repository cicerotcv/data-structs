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
int queue_int_empty(queue_int *q) {
    return q->last == NULL && q->first == NULL;
}

void queue_int_put(queue_int *q, int value) {
    node *new = malloc(sizeof(node));
    new->value = value;

    if (queue_int_empty(q)) {
        q->first = new;
        q->last = new;
        return;
    }

    q->last = new;
}

int queue_int_get(queue_int *q) {
    node *current = q->first;
    int value = current->value;
    q->first = current->next;
    free(current);
    return value;
}

void queue_int_delete(queue_int **_q);

int main() {
    queue_int *q = queue_int_new();

    free(q);
    return 0;
}