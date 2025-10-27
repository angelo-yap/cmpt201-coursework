#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// used in last version
/*void resetArray(char *array[], size_t max) {*/
/*  for (int i = 0; i < max; i++) {*/
/*    free(array[i]);*/
/*    array[i] = NULL;*/
/*  }*/
/*}*/

void printArray(char *array[], size_t count) {
  for (int i = 0; i < count; i++) {
    printf("%s\n", array[i]);
  }
}

void shiftArrayItems(char *array[], size_t count, const size_t MAX) {
  for (int i = count - 1; i > 0; i--) {
    // free last item in array to prevent memory leak
    if (i == MAX - 1) {
      free(array[i]);
    }
    array[i] = array[i - 1];
  }

  array[0] = NULL;
}

void clearGetlineBuffer(size_t *size, char **buffer) {
  *size = 0;
  *buffer = NULL;
}

int main() {
  char *history[5] = {NULL, NULL, NULL, NULL, NULL};
  const size_t MAX = 5;
  size_t count = 1;

  char *buffer;
  size_t size = 0;
  ssize_t num_char;

  for (;;) {
    printf("Enter input: ");
    fflush(stdout);

    num_char = getline(&buffer, &size, stdin);

    if (num_char == -1) {
      // return error
      perror("getline failed");
      exit(EXIT_FAILURE);
    }

    shiftArrayItems(history, count, MAX);

    // remove newline
    buffer[strcspn(buffer, "\n")] = 0;

    // set latest input as whatever inputted in buffer
    history[0] = buffer;

    if (strcmp(buffer, "print") == 0) {
      printArray(history, count);
    }

    clearGetlineBuffer(&size, &buffer);

    // used for nice printing when array isnt full
    if (count < 5) {
      count++;
    }
  }
}
