#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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
    const char *dice_faces[6][3] = {
        {"   ", " o ", "   "},
        {"o  ", "   ", "  o"},
        {"o  ", " o ", "  o"},
        {"o o", "   ", "o o"},
        {"o o", " o ", "o o"},
        {"o o", "o o", "o o"}};

    int face = rolled_value - 1;

    printWithDelay("-----\n", 10000);
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
    char minecharacter[10];
    int number;

    srand(time(NULL));

    printWithDelay("What dice would you like to throw?\nChoose between these:\nd4, d6, d8, d10, d12, or d20?\nYour choice: ", 10000);
    scanf("%s", minecharacter);

    while (minecharacter[0] != 'd')
    {
        printWithDelay("Invalid input. Dice must start with 'd'. Try again: ", 10000);
        scanf("%s", minecharacter);
    }

    number = atoi(&minecharacter[1]);

    while (!(number == 4 || number == 6 || number == 8 || number == 10 || number == 12 || number == 20))
    {
        printWithDelay("Invalid dice type. Enter again (d4, d6, d8, d10, d12, d20): ", 10000);
        scanf("%s", minecharacter);
        number = atoi(&minecharacter[1]);  
    }

    int num_dice = 1; 
    int total = 0;

    for (int i = 0; i < num_dice; i++)
    {
        int rolled_value = (rand() % 6) + 1;  
        total += rolled_value;
        print_dice_face(rolled_value);
    }

    char buffer[50];
    sprintf(buffer, "\nYour value: %d\n", total);
    printWithDelay(buffer, 10000);

    return 0;
}
