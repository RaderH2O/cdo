#include "list.h"

typedef enum {
  Done = 1,
  Pending = 0
} State;

// Task
typedef struct {
  char* content;
  State state;
} Task;

// Initializes a task
Task*     taskInit(char* content, State state);

// TodoList
typedef List TodoList;

// Initializes a todo list (a list with cap 2)
TodoList* todolistInit();

// Appends a task to the todolist tl
void      todolistAppend(TodoList* tl, Task* task);

// Finds a task with the content
Task*     todolistFind(TodoList* tl, char* content);

// Print the todolist
//
// In the form:
//
// [ ] This is a task that is not done
// [X] This is a task that is done
//
void      todolistPrint(TodoList* tl);

// Pop an item with the index
void      todolistPop(TodoList* tl, size_t index);

// Toggle the state of a task
void      todolistToggle(TodoList* tl, char* content);
