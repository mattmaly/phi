default:
	g++ -Wall -std=c++20 -lgmp -I./src/ src/main.cc -o main
clean:
	rm -f main
