#include "threads/readline.h"

char* readline(const char* prompt) {
    // input_init();
    printf("%s", prompt);

    long malloc_sz = 8;
    char* line = malloc(malloc_sz);
    long index = 0;
    for (char c; 1; ++index) {
        c = input_getc();

        if (index >= malloc_sz-1) {
            malloc_sz *= 2;
            line = realloc(line, malloc_sz);
        }

        if (c == '\n') {
            line[index] = '\0';
            putchar(c);
            return line;
        }
        else {
            line[index] = c;
            putchar(c);
        }
    }
}