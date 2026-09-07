#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();

  // Empty lists
  if (list_length(mylist) != 0) printf("FAIL: Empty list length != 0\n");
  if (list_get_elem_at(mylist, 1) != -1) printf("FAIL: get on empty list != -1\n");
  if (list_remove_from_front(mylist) != -1) printf("FAIL: remove front on empty list != -1\n");
  if (list_remove_from_back(mylist) != -1) printf("FAIL: remove back on empty list != -1\n");
  if (list_is_in(mylist, 10)) printf("FAIL: is_in on empty list returned true\n");

  //test 2 (add to front 100 down to 10)
  for (int val = 10; val <= 100; val += 10) {
      list_add_to_front(mylist, val);
    }

  char *str = listToString(mylist);
  if (strcmp("100->90->80->70->60->50->40->30->20->10->NULL", str) != 0) {
    printf("FAIL: list_add_to_front mismatch. Got: %s\n", str);
  }
  free(str);

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_add_to_front : FAILED\n");
  }

  list_print(mylist);
  list_remove_at_index(mylist, 3);
  list_print(mylist);

  if(strcmp("100->90->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }

  list_remove_at_index(mylist, 20);
  list_print(mylist);
  list_remove_at_index(mylist, 1);
  list_print(mylist);
  list_remove_at_index(mylist, 6);
  list_print(mylist);

  if(strcmp("90->70->60->50->40->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }

  // test: list_add_at_index & list_free
  printf("\n--- Testing list_add_at_index & list_free ---\n");
  list_t *test_list = list_alloc();

  // Insert at index 1 on an empty list
  list_add_at_index(test_list, 50, 1); // 50->NULL
  // Insert at index 1 to test new head insertion
  list_add_at_index(test_list, 25, 1); // 25->50->NULL
  // Insert in middle (index 2)
  list_add_at_index(test_list, 35, 2); // 25->35->50->NULL
  // Attempt invalid/out-of-bounds indices (should do nothing)
  list_add_at_index(test_list, 999, 0);  // Invalid: < 1
  list_add_at_index(test_list, 999, 10); // Invalid: out of bounds

  char *ins_str = listToString(test_list);
  if (strcmp("25->35->50->NULL", ins_str) != 0) {
    printf("FAIL: list_add_at_index mismatch. Got: %s\n", ins_str);
  } else {
    printf("PASS: list_add_at_index works for head, middle, and invalid bounds\n");
  }
  free(ins_str);

  list_free(test_list);  

  // printf("The list length is %d\n", list_length(mylist));

  // list_add_to_back(mylist, 39);
  // list_print(mylist);
  // list_add_to_back(mylist, 18);
  // list_add_to_back(mylist, 42);
  // list_add_to_back(mylist, 190);
  // list_print(mylist);
  // list_free(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 81);
  // list_add_to_back(mylist, 4);
  // list_add_to_front(mylist, 308);
  // list_add_to_back(mylist, 70);
  // list_add_to_front(mylist, 290);
  // list_print(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  
  // list_add_at_index(mylist, 21, 1);
  // list_add_at_index(mylist, 65, 0);
  // list_add_at_index(mylist, 10, 8);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 7);
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 3);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
  printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
  printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
  printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
  printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
  printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
  // printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  
  // list_free(mylist);
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 0);
  // list_print(mylist);
  // list_add_at_index(mylist, 20, 1);
  // list_print(mylist);
  // list_free(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_remove_from_front(mylist);
  // list_remove_at_index(mylist, -3);
  // list_remove_at_index(mylist, 0);
  // list_remove_at_index(mylist, 2);
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_add_at_index(mylist, 50, 1);
  // list_add_at_index(mylist, 0, 6);
  // list_add_at_index(mylist, 70, 0);
  // list_add_at_index(mylist, 80, 12);
  // list_print(mylist);

  // list_free(mylist);
  // list_free(mylist);
  // list_add_to_back(mylist, 100);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_add_to_back(mylist, 13);  
  // list_print(mylist);
  // list_remove_from_back(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_remove_at_index(mylist, -2);
  // list_print(mylist);
  // list_remove_at_index(mylist, 7);
  // list_print(mylist);
  // list_remove_at_index(mylist, 4);
  // list_print(mylist);

  // list_free(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 1);
  // list_print(mylist);
  // list_add_to_front(mylist, 80);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // list_add_to_back(mylist, 50);
  // list_add_to_back(mylist, 60);
  // list_add_to_back(mylist, 70);
  // list_add_to_back(mylist, 80);
  // list_add_to_back(mylist, 90);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30));
  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // printf("Is %d in the list?: %d\n", 80, list_is_in(mylist, 80));
  // list_add_to_back(mylist, 70);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 70, list_is_in(mylist, 70));
  
  // printf("The list length is %d\n", list_length(mylist));
  // printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(mylist, -4));
  // printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(mylist, 10));
  // printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(mylist, 6));
  // printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_free(mylist);
  // list_print(mylist);
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_remove_at_index(mylist, 0);
  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  // printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21));
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 50);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // printf("Index of %d?: %d\n", 30, list_get_index_of(mylist, 30));
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 60, list_get_index_of(mylist, 60));
  // list_add_to_front(mylist, 10);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // list_add_to_back(mylist, 40);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 40, list_get_index_of(mylist, 40));
  list_free(mylist);
  return 0;
}