# include "snake.h"

vector<pair<int, int>> body;
pair<int, int> snake_tail;

void init_snake() {
    body.clear();
    body.push_back({LINES / 2, COLS / 2});
    body.push_back({LINES / 2, COLS / 2 + 1});
    body.push_back({LINES / 2, COLS / 2 + 2});
}

void paint_snake() {
    for (auto elem : body) {
        move(elem.first, elem.second);
        addch('#');
    }
}

// to move the snake we need to add head and remove the tail
pair<int, int> move_snake(char direction) {
    snake_tail = body[body.size() - 1];
    body.pop_back();
    pair<int, int> new_head = body[0];
    if (direction == UP) {
        new_head.first--;
    }
    else if (direction == DOWN) {
        new_head.first++;
    }
    else if (direction == RIGHT) {
        new_head.second++;
    }
    else if (direction == LEFT) {
        new_head.second--;
    }
    // body.push_back(new_head);
    body.insert(body.begin(), new_head);
    return body[0];
}

void grow_snake() {
    body.push_back(snake_tail);
}

bool has_collision() {
    pair<int, int> head = body[0];
    int x = head.first;
    int y = head.second;

    if (x == 0 || y == 0 || x == LINES - 1 || y == COLS - 1) {
        return true;
    }

    for (int i = 1; i < body.size(); i++) {
        if (head == body[i]) {
            return true;
        }
    }
    return false;
}