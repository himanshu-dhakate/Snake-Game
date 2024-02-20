# include "food.h"

vector<pair<int, int>> nibbles;

pair<int, int> make_food() {
    return {rand() % (LINES - 2) + 1, rand() % (COLS - 2) + 1};
}

void init_food() {
    nibbles.clear();
    for (int i = 0; i < FOOD_COUNT; i++) {
        nibbles.push_back(make_food());
    }
}

void paint_food() {
    for (int i = 0; i < nibbles.size(); i++) {
        move(nibbles[i].first, nibbles[i].second);
        addch('*');
    }
}

bool eating_food(pair<int, int> head) {
    for (int i = 0; i < nibbles.size(); i++) {
        if (head.first == nibbles[i].first && head.second == nibbles[i].second) {
            nibbles.erase(nibbles.begin() + i);
            nibbles.push_back(make_food());
            return true;
        }
    }
    return false;
}