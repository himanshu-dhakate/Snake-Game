# include "game.h"

int game_state = BEFORE_START;
char direction;
int score;

void start_game() {
    init_snake();
    init_food();
    direction = LEFT;
    game_state = START;
    score = 0;
}

void end_game() {
    game_state = ENDGAME;
}

void giveScore() {
    move(0, COLS / 2);
    printw("Score %d", score);
}

bool gameLogic() {
    paintBorder();
    giveScore();
    
    int key = getch();

    if (game_state == BEFORE_START) {
        move(LINES / 2, COLS / 2);
        addstr("Please press space to start the game");

        if (key == 32) {
            start_game();
        }
    }
    else if (game_state == START) {
        if ((key == UP || key == ARROW_UP) && direction != DOWN) {
            direction = UP;
        }
        else if ((key == LEFT || key == ARROW_LEFT) && direction != RIGHT) {
            direction = LEFT;
        }
        else if ((key == DOWN || key == ARROW_DOWN) && direction != UP) {
            direction = DOWN;
        }
        else if ((key == RIGHT || key == ARROW_RIGHT) && direction != LEFT) {
            direction = RIGHT;
        }
        paint_snake();
        paint_food();
        pair<int, int> head = move_snake(direction);

        if (eating_food(head)) {
            grow_snake();
            score++;
        }

        if (has_collision()) {
            end_game();
        }
    }
    else if (game_state == ENDGAME) {
        move(LINES / 2, COLS / 2);
        addstr("OOPS! GAME OVER, Press space to restart or q to quit");
        move(LINES / 2 + 1, COLS / 2);
        printw("Your Score is %d", score);
        if (key == 32) {
            start_game();
        }
        else if (key == 'q'){
            return true;
        }
    }
    return false;
}