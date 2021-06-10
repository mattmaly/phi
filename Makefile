default:
	g++ -Wall -std=c++20 -lgmp -I./src/ src/main.cc src/phi/*.cc -o main
test: build/phi-tests-main.o build/test-cases/bigint-test.o
	g++ -Wall -std=c++20 -lgmp -I./src/ build/phi-tests-main.o build/test-cases/*.o src/phi/*.cc -o test
	./test
profile:
	g++ -g -pg -Wall -std=c++20 -lgmp -I./src/ src/main.cc src/phi/*.cc -o main
clean:
	rm -f main test
	rm -rf build/

build/phi-tests-main.o: testing/phi-tests-main.cc
	g++ -c -Wall -std=c++20 -lgmp testing/phi-tests-main.cc -o build/phi-tests-main.o
build/test-cases/%.o: testing/test-cases/%.cc
	g++ -c -Wall -std=c++20 -lgmp -I./src/ -I./testing/ testing/test-cases/*.cc -o $@
