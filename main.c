#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define ROWS 4
#define COLS 3

void hello_there()
{
    char taking[50];  

    printf("\nits a simple logical quest.\nhere i'd like u to solve some puzzles.\n");
    printf("u're trapped in the mansion. ye, just like in resident evil.\n i'd like to get out, but who knows. maybe u'll die.\n");
    printf("shall we begin? (type 'yeah')");
    scanf("%s", taking);

    while (strcmp(taking, "yeah") != 0)  
    {
        printf("r u blind? \nre-read please. \ninsert: \n");
        scanf("%s", taking); 
    }

    printf("\nYou awaken in the dimly lit, musty Library, your head throbbing from an unknown force. \nThe door behind you is locked, and the room feels eerily quiet. \n");
    printf("Dust floats in the air, and the bookshelves around you are filled with ancient tomes. \nAs you gather your bearings, a voice echoes in your mind:\n");
}

typedef struct {
    char name[50];  
    char puzzle[100];  
} Room;

Room mansion[ROWS][COLS] = {
    {{"Entrance Hall", "A strange code is required to open the door."},
     {"Library", "Decrypt a Caesar cipher to reveal a hidden key."},
     {"Dining Room", "Arrange the candles in a particular order."}},
     
    {{"Study", "Solve a riddle to find a hidden compartment."},
     {"Secret Room", "The safe's combination is linked to the player's steps."},
     {"Master Bedroom", "Find a hidden key under the mattress."}},
     
    {{"Cellar", "Observe rat patterns to unlock a safe."},
     {"Exit Room", "Arrange the items from all rooms on a pedestal."},
     {""}}  
};

void printMap() 
{
    printf("Mansion Map:\n");
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            printf("| %-15s ", mansion[i][j].name);
        }
        printf("|\n");
        for (int j = 0; j < COLS; j++) {
            printf("+-------------------");
        }
        printf("+\n");
    }
}

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
    hello_there();

    if('map' == 0)
    {
        printMap();
    }

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
