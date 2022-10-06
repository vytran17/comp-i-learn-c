// Program that will simulate Rock, Paper, Scissors game between 2 players and will decide who wins.

#include <stdio.h>

void clear_keyboard_buffer() {
  char c;
  scanf("%c", &c);
  while (c != '\n') {
    scanf("%c", &c);
  }
}

char read_player_input(int player_number) {
  char player_input;
  do {
    printf("Player %d it is your turn!\nPlease chose (r)ock, (p)aper, or (s)cissors: ", player_number);
    scanf("%c", &player_input);
    clear_keyboard_buffer();
    switch (player_input) {
    case 'R':
    case 'r':
      player_input = 'r';
      break;
    case 'P':
    case 'p':
      player_input = 'p';
      break;
    case 'S':
    case 's':
      player_input = 's';
      break;
    default:
      printf("I'm sorry but you must enter either 'r' or 'p' or 's'.\n");
    }
  }
  while (player_input != 'p' && player_input != 'r' && player_input != 's');
  return player_input;
}

void play_game() {
  char player1_input = read_player_input(1);
  char player2_input = read_player_input(2);
  if (player1_input == player2_input) {
    printf("Draw, nobody wins.\n");
  } else if (player1_input == 'p' && player2_input == 'r') {
    printf("Paper covers rock. Player 1 wins.\n");
  } else if (player1_input == 'r' && player2_input == 's') {
    printf("Rock breaks scissors. Player 1 wins.\n");
  } else if (player1_input == 's' && player2_input == 'p') {
    printf("Scissors cut paper. Player 1 wins.\n");
  } else if (player2_input == 'p' && player1_input == 'r') {
    printf("Paper covers rock. Player 2 wins.\n");
  } else if (player2_input == 'r' && player1_input == 's') {
    printf("Rock breaks scissors. Player 2 wins.\n");
  } else if (player2_input == 's' && player1_input == 'p') {
    printf("Scissors cut paper. Player 2 wins.\n");
  }
}

int main(int argc, char * argv[]) {
  char y_or_n = 'y';
  while (y_or_n == 'y') {
    play_game();
    printf("Do you wish to countinue? (y/n): ");
    scanf("%c", &y_or_n);
    clear_keyboard_buffer();
    while (y_or_n != 'y' && y_or_n != 'n') {
      printf("I'm sorry but you must enter either 'y' or 'n'.\n");
      printf("Do you wish to countinue? (y/n): ");
      scanf("%c", &y_or_n);
      clear_keyboard_buffer();
    }
  }
  return 0;
}