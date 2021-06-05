default:
	g++ -Wall -std=c++20 -lgmp -I./src/ src/main.cc src/phi/*.cc -o main
clean:
	rm -f main
