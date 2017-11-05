FLAGS=-Wall
STD=c++14

all:
	g++ $(FLAGS) -std=$(STD) expression.cpp main.cpp -o expressions

clean:
	rm -rf expressions
