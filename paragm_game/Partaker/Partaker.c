#include "Partaker.h"

void print_field(char** field_)
{
    printf("\n\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", field_[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");
    
}

void menu(char** field_, struct Partaker* ai_, struct Partaker* player_)
{
    int answer = 0;
    printf("Choose the number:\n");
    do
    {
        printf("1.Print field\n2.Move\n0.Exit\n\n>_");

        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            print_field(field_);
            break;
        case 2:
            answer = move_player(field_, ai_, player_);
            if (answer == 1)
            {
                answer = move_ai(field_, ai_, player_);
            }
            break;
        case 0:
            printf("Goodbye!\n\n");
            break;
        
        default:
            printf("Error!");
            //Write check to stupid
            break;
        }
    } while (answer != 0);
    

}

void meeting_ai(struct Partaker* ai_, struct Partaker* player_)
{
    ai_->name = (char*)malloc(sizeof(char) * 3);
    ai_->name = "AI";

    printf(" Hello, user! My name is %s. Please, enter your name:\n\n>_", ai_->name);

    meeting_player(player_);

    printf("You choose %c\n\n", player_->symbol);

    if (player_->symbol == 'X')
    {
        ai_->symbol = 'O';
    } else
    {
        ai_->symbol = 'X';
    }

    printf("Hello again, %s! Let's begin!\n\n", player_->name);
    
}

void meeting_player(struct Partaker* player_)
{
    player_->name = (char*)malloc(sizeof(char) * 20);

    scanf("%s", player_->name);

    printf("And choose your symbol(X or O):\n\n>_");
    char check = 1;

    do
    {
        getchar();
        scanf("%c", &player_->symbol);

        switch (player_->symbol)
        {
        case 'X':
            check = 0;
            break;
        case 'O':
            check = 0;
            break;
        
        default:
            printf("Error! Try again(X or O):\n\n>_");
            break;
        }

    } while (check != 0);
    

}

int move_player(char** field_, struct Partaker* ai_, struct Partaker* player_)
{
    int m = 0, n = 0;
    int answer = 0;

    printf("Choose the mesh:\n");

    do
    {
        printf("1.left-top\n2.middle-top\n3.right-top\n");
        printf("4.middle-left\n5.middle\n6.middle-right\n");
        printf("7.low-left\n8.middle-low\n9.right-low");
        print_field(field_);
        printf(">_");
        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 2:
            m = 1;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 3:
            m = 2;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 4:
            n = 1;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 5:
            n = 1;
            m = 1;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 6:
            n = 1;
            m = 2;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 7:
            n = 2;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 8:
            n = 2;
            m = 1;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        case 9:
            n = 2;
            m = 2;
            answer = check_field(field_, n, m, player_, ai_);
            break;
        
        default:
            printf("Error\n\n");
            //write check to stupid
            break;
        }
    } while (answer == 0);

    field_[n][m] = player_->symbol;

    return  check_win(field_, ai_, player_);

}

int move_ai(char** field_, struct Partaker* ai_, struct Partaker* player_)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field_[i][j] != player_->symbol && field_[i][j] != ai_->symbol)
            {
                field_[i][j] = ai_->symbol;
                print_field(field_);
                return check_win(field_, ai_, player_);
            }
            
        }
        
    }
}

int check_win(char** field_, struct Partaker* ai_, struct Partaker* player_)
{
    int counter_sum = 0;

    int counter_fdiagonals = 0;
    int counter_column = 0;
    int counter_string = 0;
    int counter_sdiagobals = 0;

    //Check digonals, middle-column, middle-string
    if (field_[1][1] != 'E')
    {
        for (int i = 0, j = 2; i < 3; i+=2, j-=2)
        {
            if (field_[1][1] == field_[i][i])
            {
                counter_fdiagonals++;   
            }

            if (field_[1][1] == field_[i][1])
            {
                counter_column++;
            }

            if (field_[1][1] == field_[1][i])
            {
                counter_string++;
            }

            if (field_[1][1] == field_[i][j])
            {
                counter_sdiagobals++;
            }
        }

        if (counter_column == 2 || counter_string == 2 || counter_fdiagonals == 2 || counter_sdiagobals == 2)
        {
            if (field_[1][1] == player_->symbol)
            {
                printf("%s WIN\n\n", player_->name);
                return 0;
            } else
            {
                printf("%s WIN\n\n", ai_->name);
                return 0;
            }
        }

        counter_column = counter_string = 0;
    }

    //check other columns and string
    for (int i = 0; i < 3; i+=2)
    {
        for (int j = 0; j < 2; j++)
        {
            if (field_[i][j] == field_[i][j+1])
            {
                counter_string++;
            }

            if (counter_string == 2)
            {
                if (field_[i][j] == player_->symbol)
                {
                    printf("%s WIN!!!\n\n", player_->name);
                    return 0;
                } else if (field_[i][j] == ai_->symbol)
                {
                    printf("%s WIN!!!\n\n", ai_->name);
                    return 0;
                }
            }

            if (field_[j][i] == field_[j+1][i])
            {
                counter_column++;
            }

            if (counter_column == 2)
            {
                if (field_[j][i] == player_->symbol)
                {
                    printf("%s WIN!!!\n\n", player_->name);
                    return 0;
                } else if (field_[j][i] == ai_->symbol)
                {
                    printf("%s WIN!!!\n\n", ai_->name);
                    return 0;
                }
            }
        }        
    }

    //check for dead heat
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field_[i][j] == player_->symbol || field_[i][j] == ai_->symbol)
            {
                counter_sum++;
            }   
        }
    }
    if (counter_sum == 9)
    {
        printf("DEAD HEAT!!!\n\n");
        return 0;
    }
    
    return 1;
}

int check_field(char** field_, int n, int m, struct Partaker* player_, struct Partaker* ai_)
{
    if (field_[n][m] == player_->symbol || field_[n][m] == ai_->symbol)
    {
        printf("This is mesh is full!\n\n");
        return 0;
    }
    return 1;
}