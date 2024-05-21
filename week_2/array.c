#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void removeSpaces(char *str) {
  int str_ovr_idx = 0;

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != ' ') {
      str[str_ovr_idx] = str[i];
      str_ovr_idx++;
    }
  }

  str[str_ovr_idx] = '\0';
}

void sortString(char *str) {
  int str_length = strlen(str);

  for (int i = 0; i < str_length - 1; i++) {
    int temp;
    for (int j = 0; j < str_length - 1 - i; j++) {
      if (str[j] > str[j + 1]) {
        swap(&str[j], &str[j + 1]);
      }
    }
  }
}

int main() {
  char input[1000];

  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  removeSpaces(input);
  sortString(input);

  printf("%s\n", input);

  return 0;
}
