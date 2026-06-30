#include <stdio.h>
#include <stdlib.h>

int hexer(unsigned char *file, int len);

int main(int argc, char *argv[]) {

  // just read the file to forward it to the function
  // raw bytes
  FILE *file;
  file = fopen(argv[1], "rb");

  int len = 0;
  unsigned char *file_arr = malloc(sizeof(*file_arr));
  int check = 0;
  unsigned char *temp = NULL;

  while (1) {
    check = fread(&file_arr[len], sizeof(*file_arr), 1, file);
    len += check;
    if (check == 0)
      break;
    unsigned char *temp = realloc(file_arr, sizeof(*file_arr) * (len + 1));
    if (file_arr == NULL || temp == NULL) {
      break;
    }
    file_arr = temp;
  }

  // pass the buffer into the function
  hexer(file_arr, len);

  free(file_arr);
  fclose(file);
  return 0;
}

int hexer(unsigned char *file, int len) {

  // just read the number of bytes given
  // change the buffer type later
  int lc = 0; // linecount
  int i = 0;

  while (i < len) {

    // print lc
    printf("%08d: ", lc);
    lc += 10;
    int c[16]; // to print the file after the hexes

    // print the hexes
    for (int j = 0; j < 16; j++) {
      if (i >= len) {
        printf("  ");
        c[j] = EOF;
        continue;
      }
      printf("%02x", file[i]);
      if (j % 2 == 1)
        printf(" ");
      c[j] = file[i];
      i++;
    }

    if (i >= len)
      printf(" ");

    // now the chars
    printf("  ");
    for (int j = 0; j < 16; j++) {
      if (c[j] == EOF)
        break;
      else if (c[j] == '\n')
        printf(".");
      else
        printf("%c", c[j]);
    }

    printf("\n");
  }

  return 0;
}
