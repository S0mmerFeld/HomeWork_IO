all: main.o
	g++ main.cpp -o main
main.o:
	g++ main.cpp

clean:
	rm -f main
