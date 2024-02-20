# include "ui.h"

char borderch = (char)219;

void initScreen() {
    initscr();
    nodelay(stdscr, TRUE);
    curs_set(0);
    noecho();
}

void endScreen() {
    endwin();
}

void paintBorder() {
    for (int i = 0; i < COLS; i++) {
        move(0, i);
        addch(borderch);
        move(LINES - 1, i);
        addch(borderch);
    }

    for (int i = 1; i < LINES - 1; i++) {
        move(i, 0);
        addch(borderch);
        move(i, COLS - 1);
        addch(borderch);
    }
}