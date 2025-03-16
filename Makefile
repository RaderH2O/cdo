WARNING_FLAGS = -Wall -Wextra
OTHER_FLAGS = -pedantic-errors -O2
INCLUDES = -Iincludes/
LIBRARIES =
FILES = main.c includes/list.c includes/todo.c
OUTPUT_FILE = cdo

linux:
	gcc $(WARNING_FLAGS) $(OTHER_FLAGS) $(FILES) $(INCLUDES) $(LIBRARIES) -o $(OUTPUT_FILE)
	echo File compiled.

windows:
	gcc $(WARNING_FLAGS) $(OTHER_FLAGS) $(FILES) $(INCLUDES) $(LIBRARIES) -o $(OUTPUT_FILE).exe
	echo File compiled.

