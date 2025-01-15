#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char numbers[] = "0123456789";
char low_letters[] = "abcdefghijklmnoqprstuvwyzx";
char upper_letters[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
char symbols[] = "!@#$^&*_?";

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Please provide a password lenght as argument.");
    return 1;
  }

  int password_lenght;
  password_lenght = atoi(argv[1]);

  if (password_lenght <= 0) {
    printf("Lenght must be greater than 0.");
    return 1;
  }

  int i = 0;
  int randomizer = 0;
  srand((unsigned int)(time(NULL)));

  char password[password_lenght + 1];

  randomizer = rand() % 4;

  for (i = 0; i < password_lenght; i++) {
    switch (randomizer) {
    case 1:
      password[i] = numbers[rand() % 10];
      randomizer = rand() % 4;
      break;
    case 2:
      password[i] = symbols[rand() % 9];
      randomizer = rand() % 4;
      break;
    case 3:
      password[i] = low_letters[rand() % 26];
      randomizer = rand() % 4;
      break;
    default:
      password[i] = upper_letters[rand() % 26];
      randomizer = rand() % 4;
      break;
    }
  }

  password[password_lenght] = '\0';

  printf("%s\n", password);

  return 0;
}
