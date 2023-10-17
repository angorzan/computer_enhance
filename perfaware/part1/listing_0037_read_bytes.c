#include <stdio.h>

int main() {

  FILE* file;
  unsigned char b[2];

      // Opening file in reading mode
      // unsigned char 0 to 255 range. This might be useful for displaying an octet e.g. as hex value.
    file = fopen("./listing_0037_single_register_mov", "r");

    if (NULL == file) {
        printf("file can't be opened \n");

    }


    printf("content of this file in hexadecimal format is: \n");

  while (fread(&b, 1, 2, file) == 2) {
    //1 bajt za pomocą dwucyfrowych liczb hexadecymalnych
    printf("%x %x\n", b[0], b[1]);

    // (sprawdzenie xxd listing_0037_single_register_mov, ten sam wynik 89d9)
    if(b[0] >> 2 == 0b100010) {
      //spr 89d9 w https://www.rapidtables.com/convert/number/hex-to-binary.html
      //89 = 0b100010
      // unsigned char d = (b[0] & 0b00000010) >> 1; // 0 - source in REG, 1 - dest in REG
      unsigned char d = (b[0] & 0b10) >> 1; // 0 - source in REG, 1 - dest in REG
      unsigned char w = b[0] & 0b1; // 1 = word, 0 - byte
      printf("opcode: mov, direction: %x, word/byte: %x", d, w);


      unsigned char mod = b[1] >> 6;
      //d9 = 11011001
      printf(", mod = %x", mod);
      if(mod == 0b00000011){
        printf(", register mode \n");
      }

      unsigned char reg = (b[1] >> 3) & 0b111;
      unsigned char rm = b[1] & 0b111;
//poczytac co to jest rejestr
      printf("mod: %x, register: %x, rm: %x", mod, reg, rm);

      if (rm = 0b00000001){
        printf(", rm cx");
      }
    }
    printf("\n");
  }

    //reading opcode from first byte


  //   do {
  //       // i = fgetc(file);
  //       i = fread(&i, sizeof(unsigned int), 1, file);
  //       //print unsigned int as hexadecimal every in new line
  //       //1 bajt za pomocą dwucefrowych liczb hexadecymalnych i decimalnie
  //       printf("%x\n", i);

  //       // fscanf (file, "%d", &i);

  //       // Checking if character is not EOF as unsigned char.
  //       // If it is EOF stop reading.
  //   } while (i != (unsigned int) EOF);
  // //sprawdzone przez xxd listing_0037_single_register_mov, że output jest 89d9, więc ok ff to jest jakiś znak konca linii


  //przeczytac o przesunięciach bitowych w c





    fclose(file);
}