CC := g++
CCF := -std=c++17 -Wall -Wextra -s -Os
SRC := $(wildcard *.cpp)
OUT := mmclc

main:
	$(CC) $(CCF) $(SRC) -o $(OUT)
