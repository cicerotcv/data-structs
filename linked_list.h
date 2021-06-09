#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct _linked_list;

typedef struct _linked_list linked_list;

linked_list *linked_list_new();
void linked_list_delete(linked_list **_l);
int linked_list_empty(linked_list *l);
int linked_list_size(linked_list *l);
void linked_list_insert_end(linked_list *l, int value);
int linked_list_get(linked_list *l, int index);
void linked_list_remove(linked_list *l, int index);
int linked_list_pop(linked_list *l);

#endif