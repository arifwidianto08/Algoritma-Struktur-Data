#include <stdio.h>

const char CARD_VALUES[] = "123456789TJQK";

// Function to perform the swap of two card values
void swap(int *a, int *b, int *swaps) {
  int temp = *a;
  *a = *b;
  *b = temp;
  (*swaps)++;
}

// Function to count the minimum number of swaps using selection sort
int count_minimum_swaps(int N, int cards[]) {
  int swaps = 0;
  for (int i = 0; i < N - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < N; j++) {
      if (cards[j] < cards[min_index]) {
        min_index = j;
      }
    }

    if (min_index != i) {
      swap(&cards[min_index], &cards[i], &swaps);

      printf("Pertukaran %d :", swaps);
      for (int idx = 0; idx < N; idx++) {
        printf(" %c", CARD_VALUES[cards[idx] - 1]);
      }
      printf("\n");
    }
  }
  return swaps;
}

// Function to convert card values to numeric values
int convert_card_value(char card[]) {
  // Define a mapping for card values
  int i;
  for (i = 0; CARD_VALUES[i] != card[0]; i++)
    ;
  return i + 1;
}

int main() {
  int N;
  scanf("%d", &N); // Read the number of cards

  int cards[N];
  for (int i = 0; i < N; i++) {
    char card[3];
    scanf("%s", card);

    // Convert card values to numeric values
    cards[i] = convert_card_value(card);
  }

  // Call the function to count the minimum number of swaps
  int minimal_swaps = count_minimum_swaps(N, cards);

  // Output the minimum number of swaps
  printf("%d\n", minimal_swaps);

  return 0;
}
