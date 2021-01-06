main: src/*.cpp
	clang++ -Wall --std=c++17 -o main src/*.cpp

test: main
	@./main lorem.txt -o test.out
	@cmp --silent test.out lorem.out && echo "Test succeeded" || echo "Test failed"

zip:
	@zip -r oliver_herrmann_78403.zip src lorem.out lorem.txt makefile COMPILE.txt TEST.txt

.PHONY: zip