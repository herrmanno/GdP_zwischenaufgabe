main: src/*.cpp
	clang++ -Wall --std=c++17 -o main src/*.cpp

test: main
	@./main lorem.txt -o test.out
	@cmp --silent test.out lorem.out && echo "Test succeeded" || echo "Test failed"