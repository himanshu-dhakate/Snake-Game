slither: main.cpp ui.cpp game.cpp snake.cpp food.cpp
	g++ main.cpp ui.cpp game.cpp snake.cpp food.cpp -lncurses -o slither && ./slither

clear:
	rm -f slither