# include <iostream>
# include <curses.h>
# include "ui.h"
# include "game.h"
# include <chrono>
# include "settings.h"

using namespace std;

int df;

void eventLoop() {
    while (true) {
        auto last_time = chrono::system_clock::now();
        erase();
        bool gameover = gameLogic();
        refresh();
        do {
            auto current_time = chrono::system_clock::now();
            df = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
        } while (df < time_delay_betwn_frames);

        if (gameover) break;
    }
}

int main() {
    initScreen();
    eventLoop();
    endScreen();
    cout << "Thanks for playing the snake game\n";
    return 0;
}