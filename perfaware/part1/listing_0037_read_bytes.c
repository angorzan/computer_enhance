#include <stdio.h>

int main() {

  FILE* file;
  char ch;
      // Opening file in reading mode
    file = fopen("./test.txt", "r");

    if (NULL == file) {
        printf("file can't be opened \n");
    }

    printf("content of this file are \n");

        // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(file);
        printf("%c", ch);

        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);

    // Closing the file
    fclose(file);
  return 0;
}