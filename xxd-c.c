#include <stdio.h>

int main(int argc, char *argv[]) {

  // normal read
  FILE *file_read;
  file_read = fopen(argv[1], "r");

  // binary/hex read
  FILE *file_hex;
  file_hex = fopen(argv[1], "rb");

  int linecount = 0;
  int c;           // for the characters
  unsigned char h; // for the hex

  while (c != EOF) {

    // print the line count (00000000)
    printf("%08d: ", linecount);
    linecount += 10;

    for (int i = 0; i < 16; i++) {
      fread(&h, sizeof(char), 1, file_hex);
      printf("%02x", h);
      if (i % 2 == 1)
        printf(" ");
    }

    printf("  ");

    // this prints the file itself (16 chars each line)
    for (int i = 0; i < 16; i++) {
      c = fgetc(file_read);
      if (c == EOF)
        break;
      else if (c == (int)'\n')
        printf(".");
      else
        printf("%c", c);
    }

    printf("\n");
  }

  fclose(file_read);
  fclose(file_hex);
  return 0;
}
