CC=g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

all: test_bin main

test_bin:.o test.cpp
	$(CC) $(CC_FLAGS) main.o test.cpp -o test_bin $(CC_GTEST_FLAGS)

main: HW1.hpp main.cpp
	$(CC) $(CC_FLAGS) main.cpp -o main

test:
	./test_bin

clean:
	rm -f *.o main test_bin