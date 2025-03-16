#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "todo.h"

void promptRemove(TodoList* tl) {

  size_t line_length = sizeof(char) * 256;
  char* buff = malloc(line_length);

  printf("Enter the id of the todo you want to remove\n> ");
  int inp = getline(&buff, &line_length, stdin);

  int index = atoi(buff);

  todolistPop(tl, index-1);
}

void promptToggle(TodoList* tl) {

  size_t line_length = sizeof(char) * 256;
  char* buff = malloc(line_length);

  printf("Enter the id of the todo you want to change\n> ");
  int inp = getline(&buff, &line_length, stdin);
  int index = atoi(buff);

  Task* task = listAt(tl, index-1);
  task->state = task->state == Pending ? Done : Pending;
}

void promptAppend(TodoList* tl) {

  size_t line_length = sizeof(char) * 256;
  char* buff = malloc(line_length);

  printf("Enter the content of the todo you want to append\n> ");
  int inp = getline(&buff, &line_length, stdin);

  for (int i = 0; i < 256; i++) {
    if (buff[i] == '\n') {
      buff[i] = '\0';
    }
  }

  Task* task = taskInit(buff, Pending);
  todolistAppend(tl, task);
}

int prompt(TodoList* tl) {

  printf("\n\n### CDO - Terminal TODO ###\n");
  todolistPrint(tl);
  printf("What do you want to do? ( (a)dd, (r)emove, (t)oggle, (q)uit )\n> ");

  size_t size = sizeof(char) * 256;
  char* buff = malloc(size);
  int inp = getline(&buff, &size, stdin);

  switch (buff[0]) {
    case 'a':
      promptAppend(tl);
      break;

    case 'r':
      promptRemove(tl);
      break;

    case 't':
      promptToggle(tl);
      break;

    case 'q':
      return 0;
      break;
  }

  return 1;

  printf("\n\n");
}

int main() {

  TodoList* todolist = todolistInit();

  while (prompt(todolist)) {
    continue;
  }
}
