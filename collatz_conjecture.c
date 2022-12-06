// Collatz conjecture implementation.
//
// Read 2 numbers from user - start and end of range.
// For each number in range, perform the recursive calculation
// -- If it's odd: multiply by 3 then add 1
// -- If it's even: divide by 2
// -- Continue calculation until it gets to the final result 1
// -- Count how many steps it took to reach 1
//
// Print out results in a formatted table.

#include <stdio.h>

void read_input_from_user(int lower_bound, int upper_bound, int* dest);
int get_number_of_steps(int number);
void clear_keyboard_buffer(void);

int main(int argc, char * argv[]) {
  int start, end;

  printf("Enter the starting number. Must be between 1 and 1000: ");
  read_input_from_user(1, 1000, &start);

  printf("Enter the starting number. Must be between %d and 10000: ", start);
  read_input_from_user(start, 10000, &end);

  for (int i = start; i <= end; i++) {
    int steps = get_number_of_steps(i);
    printf("%5d:%-5d", i, steps);
    if ((i - start + 1) % 7 == 0)
      printf("\n");
  }
  return 0;
}

void read_input_from_user(int from, int to, int* dest) {
  scanf("%d", dest);
  clear_keyboard_buffer();
  while (*dest <= from || *dest > to) {
    printf("Please enter the number between %d and %d: ", from, to);
    scanf("%d", dest);
    clear_keyboard_buffer();
  }
}

int get_number_of_steps(int number) {
  if (number == 1) {
    return 0;
  }
  if (number % 2 == 1) {
    number = number * 3 + 1;
    return 1 + get_number_of_steps(number);
  } else {
    number = number / 2;
    return 1 + get_number_of_steps(number);
  }
}

void clear_keyboard_buffer(void) {
  char c;
  scanf("%c", & c);
  while (c != '\n') {
    scanf("%c", & c);
  }
}