#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 18

char matrix[N][N];

void init_matrix() {
  // Initialize matrix with ' ' (empty)
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix[i][j] = ' ';
    }
  }

  // Add border to matrix
  for (int i = 0; i < N; i++) {
    matrix[i][0] = '*';
    matrix[i][N - 1] = '*';
  }
  for (int j = 0; j < N; j++) {
    //matrix[0][j] = '*';
    //matrix[N - 1][j] = '*';
  }

  // Add mines to matrix
  srand(time(0));
  int num_mines = 20;
  while (num_mines > 0) {
    int i = rand() % (N - 2) + 1;
    int j = rand() % (N - 2) + 1;
    if (matrix[i][j] != 'M') {
      matrix[i][j] = 'M';
      num_mines--;
    }
  }
}

void print_matrix() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  init_matrix();
  print_matrix();

  // Place user at bottom of matrix
  int x = N - 2;
  int y = 1 + rand() % (N - 2);
  matrix[x][y] = 'U';

  while (x > 0) {
    system("clear");
    print_matrix();

    // Move user in a random direction (up, left, or right)
    int dir = rand() % 3;
    if (dir == 0) {
      // Move up
       matrix[x][y] = '^';
      x--;
     
    } else if (dir == 1) {
      // Move left
      matrix[x][y] = '<';
      y--;
      
    } else {
      // Move right
       matrix[x][y] = '>';
      y++;
     
    }

    // Check if user has hit a mine
    if (matrix[x][y] == 'M') {
      printf("You hit a mine! Game over.\n");
      return 0;
    }

    // Update user position on matrix
    matrix[x][y] = 'U';
    usleep(50000);
  }

  printf("Congratulations! You made it to the top without hitting a mine.\n");

  return 0;
}
