#include <stdio.h>
#include <stdlib.h>

struct Partaker
{
    char* name;
    char symbol;
};

void print_field(char**);
void menu(char**, struct Partaker*, struct Partaker*);
void meeting_ai(struct Partaker*, struct Partaker*);
void meeting_player(struct Partaker*);
int move_player(char**, struct Partaker*, struct Partaker*);
int move_ai(char**, struct Partaker*, struct Partaker*);
int check_win(char**, struct Partaker*, struct Partaker*);
int check_field(char**, int, int, struct Partaker*, struct Partaker*);