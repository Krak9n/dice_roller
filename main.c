#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void sleep_ms(int milliseconds) 
{
  usleep(milliseconds * 1000);
}

void print_dice_face(int rolled_value) 
{

  const char* dice_faces[6][3] = 
  {
      {"   ", " o ", "   "},  
      {"o  ", "   ", "  o"},  
      {"o  ", " o ", "  o"},  
      {"o o", "   ", "o o"},  
      {"o o", " o ", "o o"},  
      {"o o", "o o", "o o"}   
  };

  int face = rolled_value - 1;  

  printf("-----\n");
  for (int i = 0; i < 3; i++) 
  {
      printf("|%s|\n", dice_faces[face][i]);
  }
  printf("-----\n");
}

int main(void) 
{   
    
  char character;
  int number;

  srand(time(NULL)); 
  
  char minecharacter[50];  

  while (strcmp(minecharacter, "dice") == 0)  
  {
    while (1)
    {
      printf("what dice would you like to throw?\nchoose between these:\nd4, d6, d8, d10, d12, or d20?\nyour choice: ");
      scanf(" %c%d", &character, &number);  
  
      if (character != 'd' || (number != 4 && number != 6 && number != 8 && number != 10 && number != 12 && number != 20)) 
      {
          printf("Invalid dice input. Please enter a valid dice type (d4, d6, d8, d10, d12, d20).\n");
          return 1;
      }
  
      int num_dice = (number == 20) ? 4 : ((number == 12 || number == 10 || number == 8) ? 2 : 1);
  
      int total = 0;  
      for (int i = 0; i < num_dice; i++) 
      {
          int rolled_value = rand() % 6 + 1; 
          total += rolled_value;  
          print_dice_face(rolled_value);  
      }
  
      printf("\nyour value: %d\n", total);
      
    }
  }


  return 0;
}
