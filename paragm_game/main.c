#include "Partaker/Partaker.h"

int main()
{
    char** field = (char**)malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++)
    {
        field[i] = (char*)malloc(sizeof(char) * 3);
        for (int j = 0; j < 3; j++)
        {
            field[i][j] = 'E';//thats mean "Empty"
        }
        
    }
    
    struct Partaker player;
    struct Partaker ai;

    meeting_ai(&ai, &player);
    menu(field, &ai, &player);

    system("PAUSE");

    return 0;
}