# ifndef DEF_SNAKE

# define DEF_SNAKE
# include <curses.h>
# include "settings.h"
# include <vector>
# include <chrono>
using namespace std;

void init_snake();
void paint_snake();
pair<int, int> move_snake(char);
void grow_snake();
bool has_collision();
# endif