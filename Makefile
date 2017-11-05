FLAGS=-Wall -fsanitize=address
STD=c++14

all:
	g++ $(FLAGS) -std=$(STD) *.cpp -o expressions

clean:
	rm -rf expressions