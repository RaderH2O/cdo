#include <stdio.h>
#include <stdlib.h>

#include "todo.h"

Task*     taskInit(char* content, State state) {

  Task* task    = malloc(sizeof(Task));

  task->content = content;
  task->state   = state;

  return task;
}

TodoList* todolistInit() {
  return listInit(2);
}

void      todolistAppend(TodoList* tl, Task* task) {
  listAppend(tl, task);
}

Task*     todolistFind(TodoList* tl, char* content) {

  if (!tl) {
    return NULL;
  }

  for (size_t i = 0; i < tl->length; i++) {

    Task* task = listAt(tl, i);
    char* other = task->content;

    int charEqual = 1;

    while (*other != '\0' && *content != '\0') {
      if (*other != *content) {
        charEqual = 0;
        break;
      }
      other++;
      content++;
    }

    if (charEqual) {
      return task;
    }
  }
  return NULL;
}

void      todolistPrint(TodoList* tl) {

  if (!tl) {
    return;
  }

  for (size_t i = 0; i < tl->length; i++) {
    Task* task = listAt(tl, i);
    char state = task->state == Done ? 'X' : ' ';

    printf("%lu [%c] %s\n", i+1, state, task->content);
  }
}

void      todolistPop(TodoList* tl, size_t index) {
  listPop(tl, index);
}

void      todolistToggle(TodoList* tl, char* content) {

  Task* task = todolistFind(tl, content);

  task->state = task->state == Done ? Pending : Done;
}
