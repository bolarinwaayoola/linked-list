// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/*getNode helper allocation*/
node_t *getNode(elem value) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  if (node != NULL) {
    node->value = value;
    node->next = NULL;
  }
  return node;
}

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  if (mylist != NULL) {
    mylist->head = NULL;
  }
  return mylist; 
}

void list_free(list_t *l) {
  if (l == NULL) return;
  node_t * curr = l->head;
  while (curr != NULL) {
    node_t * temp = curr;
    curr = curr->next;
    free(temp);
  }
  free(l);
}

void list_print(list_t *l) {
  if (l==NULL) return;
  node_t *curr = l->head;
  while (curr != NULL) {
    printf("%d ->", curr->value);
    curr = curr->next; 
  }
  printf("NULL\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 10024);
  if (buf == NULL) return NULL;
  buf[0] = '\0';
  if (l == NULL || l->head == NULL) {
    strcpy(buf, "NULL");
    return buf;
  }
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {
    if (l == NULL) return 0;
    int len = 0;
    node_t *curr = l->head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

void list_add_to_back(list_t *l, elem value) {
    if (l == NULL) return;
    node_t *new_node = getNode(value);
    if (new_node == NULL) return;

    if (l->head == NULL) {
        l->head = new_node;
        return;
    }

    node_t *curr = l->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
    if (l == NULL) return;
    node_t *new_node = getNode(value);
    if (new_node == NULL) return;
    new_node->next = l->head;
    l->head = new_node;
}


void list_add_at_index(list_t *l, elem value, int index) {
  if (l == NULL || index < 0) return;
  if (index == 0) {
    list_add_to_front(l, value);
    return;
  }

  node_t *curr = l->head;
  for (int i = 0; curr != NULL && i < index - 1; i++) {
    curr = curr->next;
  }

  if (curr == NULL) return; // Index out of bounds

  node_t *new_node = getNode(value);
  if (new_node == NULL) return;

  new_node->next = curr->next;
  curr->next = new_node;
}

elem list_remove_from_back(list_t *l) {
  if (l == NULL || l->head == NULL) return -1;

  if (l->head->next == NULL) {
    elem val = l->head->value;
    free(l->head);
    l->head = NULL;
    return val;
  }

  node_t *curr = l->head;
  while (curr->next->next != NULL) {
    curr = curr->next;
  }

  node_t *temp = curr->next;
  elem val = temp->value;
  curr->next = NULL;
  free(temp);
  return val;
}

elem list_remove_from_front(list_t *l) {
  if (l == NULL || l->head == NULL) return -1;

  node_t *temp = l->head;
  elem val = temp->value;
  l->head = l->head->next;
  free(temp);
  return val;
}

elem list_remove_at_index(list_t *l, int index) {
  if (l == NULL || l->head == NULL || index < 0) return -1;
  if (index == 0) return list_remove_from_front(l);

  node_t *curr = l->head;
  for (int i = 0; curr->next != NULL && i < index - 1; i++) {
    curr = curr->next;
  }

  if (curr->next == NULL) return -1; // Out of bounds

  node_t *temp = curr->next;
  elem val = temp->value;
  curr->next = temp->next;
  free(temp);
  return val;
}

bool list_is_in(list_t *l, elem value) {
  if (l == NULL) return false;
  node_t *curr = l->head;
  while (curr != NULL) {
    if (curr->value == value) return true;
    curr = curr->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if (l == NULL || index < 0) return -1;
  node_t *curr = l->head;
  for (int i = 0; curr != NULL && i < index; i++) {
    curr = curr->next;
  }
  return (curr != NULL) ? curr->value : -1;
}

int list_get_index_of(list_t *l, elem value) {
  if (l == NULL) return -1;
  node_t *curr = l->head;
  int idx = 0;
  while (curr != NULL) {
    if (curr->value == value) return idx;
    curr = curr->next;
    idx++;
  }
  return -1;
}
