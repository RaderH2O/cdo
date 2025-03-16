#include <stddef.h>

typedef struct {
  void** data;
  size_t length;
  size_t capacity;
} List;

List* listInit(size_t capacity);
void  listAppend(List* list, void* value);
void  listPop(List* list, size_t index);
void* listAt(List* list, size_t index);
void  listFree(List* list);
