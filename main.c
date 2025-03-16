#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "todo.h"

void promptToggle(TodoList* tl) {

  size_t line_length = sizeof(char) * 256;
  char* buff = malloc(line_length);

  printf("Enter the id of the todo you want to change\n> ");
  getline(&buff, &line_length, stdin);
  int index = atoi(buff);

  Task* task = listAt(tl, index-1);
  task->state = task->state == Pending ? Done : Pending;
}

void promptAppend(TodoList* tl) {

  size_t line_length = sizeof(char) * 256;
  char* buff = malloc(line_length);

  printf("Enter the content of the todo you want to append\n> ");
  getline(&buff, &line_length, stdin);

  for (int i = 0; i < 256; i++) {
    if (buff[i] == '\n') {
      buff[i] = '\0';
    }
  }

  Task* task = taskInit(buff, Pending);
  todolistAppend(tl, task);
}

int prompt(TodoList* tl) {

  printf("### CDO - Terminal TODO ###\n");
  todolistPrint(tl);
  printf("What do you want to do? ( (a)dd, (t)oggle, (q)uit )\n> ");

  char* buff;

  size_t size = sizeof(buff);
  int inp = getline(&buff, &size, stdin);

  switch (buff[0]) {
    case 'a':
      promptAppend(tl);
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
