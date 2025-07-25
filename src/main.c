#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

union COUNT
{
  int ROLL_COUNT;
  char buffer[50];
};

void printWithDelay(const char *str, int delay)
{
  while (*str)
  {
    putchar(*str++);
    fflush(stdout);
    usleep(delay);
  }
}

void print_dice_face(int rolled_value)
{
  const char *dice_faces[6][3] = 
  {
      {"   ", " o ", "   "},
      {"o  ", "   ", "  o"},
      {"o  ", " o ", "  o"},
      {"o o", "   ", "o o"},
      {"o o", " o ", "o o"},
      {"o o", "o o", "o o"}
  };

  int face = rolled_value - 1;

  printWithDelay("\n-----\n", 10000);
  for (int i = 0; i < 3; i++)
  {
    char buffer[10];
    sprintf(buffer, "|%s|\n", dice_faces[face][i]);
    printWithDelay(buffer, 10000);
  }
  printWithDelay("-----\n", 10000);
}

int main(void)
{
  union COUNT count;
  srand(time(NULL));

  printWithDelay("define number of rolls you want to have: ", 10000);
  scanf("%d", &count.ROLL_COUNT);

  int total = 0;

  for (int i = 0; i < count.ROLL_COUNT; i++)
  {
    int rolled_value = (rand() % 6) + 1;  
    total += rolled_value;
    print_dice_face(rolled_value);
  }

  printf("\n");

  sprintf(count.buffer, "\nYour value: %d\n", total);
  printWithDelay(count.buffer, 10000);

  return 0;
}
