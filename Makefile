CXX=g++
CFLAGS=-Wall -Wextra -std=c++17
TARGET=bin/sudoku
DEPS=player.o board.o game.o main.o

all: $(TARGET)

$(TARGET): $(DEPS)
	$(CXX) $(CFLAGS) -o $(TARGET) $(DEPS)

player.o: lib/player.cpp
	$(CXX) -c lib/player.cpp

board.o: lib/board.cpp
	$(CXX) -c lib/board.cpp

game.o: lib/game.cpp
	$(CXX) -c lib/game.cpp

main.o: lib/main.cpp
	$(CXX) -c lib/main.cpp

clean:
	$(RM) bin/sudoku *.o
