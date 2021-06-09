#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _stack_int {
    node *top;
};

stack_int *stack_int_new() {
    stack_int *s = malloc(sizeof(stack_int));
    s->top = NULL;
    return s;
}

int stack_int_empty(stack_int *s) { return s->top == NULL; }

void stack_int_push(stack_int *s, int value) {
    node *n = malloc(sizeof(node));  // aloca memória para o novo node
    n->next = s->top;                // antigo topo se torna o próximo
    n->value = value;                // atribuição de valor
    s->top = n;                      // topo da fila se torna o novo node
}

int stack_int_pop(stack_int *s) {
    node *n = s->top;      // endereco do topo atual
    s->top = n->next;      // redefinição do topo
    int value = n->value;  // guarda o valor do topo atual
    free(n);               // desaloca a memória para o node removido
    return value;          // devolve o valor do node removido
}

/*
for (node *n = s->top; n != NULL; n = n->next) {
    printf("%d\n", n->value);
}
*/

void stack_int_delete(stack_int **_s) {
    stack_int *s = *_s;
    node *n = s->top;
    while (n != NULL) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(s);
    *_s = NULL;
}

int main() {
    stack_int *stack = stack_int_new();

    stack_int_push(stack, 3);
    stack_int_push(stack, 5);
    stack_int_push(stack, 7);
    stack_int_push(stack, 9);

    while (!stack_int_empty(stack)) {
        printf("value: %d\n", stack_int_pop(stack));
    }

    stack_int_delete(&stack);

    return 0;
}