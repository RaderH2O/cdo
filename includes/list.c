#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

List* listInit(size_t capacity) {
  List* list = malloc(sizeof(List));

  list->capacity = capacity;
  list->data = malloc(sizeof(void*) * list->capacity);

  return list;
}

void  listAppend(List* list, void* value) {

  // Handling NULL pointer
  if (!list) {
    return;
  }

  while (list->length >= list->capacity) {
    list->capacity *= 2;

    void** new_data = realloc(list->data, list->capacity);
    list->data = new_data;
  }

  list->data[list->length] = value;
  list->length++;
}

void  listPop(List* list, size_t index) {

  // Handling NULL pointer
  if (!list) {
    return;
  }

  for (size_t i = index; i < list->length-1; i++) {
    list->data[i] = list->data[i+1];
  }

  list->length--;
}

void* listAt(List* list, size_t index) {

  // Handling NULL pointer
  if (!list) {
    return NULL;
  }
  return list->data[index];
}
void  listFree(List* list) {

  // Handling NULL pointer
  if (!list) {
    return;
  }

  if (list->data) {
    free(list->data);
  }

  free(list);
}
