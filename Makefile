default:
	g++ -Wall -std=c++20 -lgmp -I./src/ src/main.cc src/phi/*.cc -o main
test:
	g++ -Wall -std=c++20 -lgmp -I./src/ src/phi/*.cc testing/phi-tests.cc -o test
	./test
clean:
	rm -f main
