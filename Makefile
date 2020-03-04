snek: main.o screen.o snake.o
	g++ main.o screen.o snake.o -lncurses -o snek

main.o: main.cpp
	g++ -c main.cpp

screen.o: screen.cpp
	g++ -c screen.cpp

snake.o: snake.cpp
	g++ -c snake.cpp

clean:
	rm -rf *.o
