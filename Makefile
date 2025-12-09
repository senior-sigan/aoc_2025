DATA_PATH ?= data
CC= clang
RM= rm -f

CFLAGS= -Wall -Wextra -pedantic -std=c23 -ggdb # -Werror
LIBS= -lm

all: day01_1 day01_2

build:
	mkdir -p build

.PHONY: day01_1
day01_1: build
	$(CC) $(LIBS) $(CFLAGS) day01_1.c -o build/day01_1
	./build/day01_1 < $(DATA_PATH)/day01.txt

.PHONY: day01_2
day01_2: build
	$(CC) $(LIBS) $(CFLAGS) day01_2.c -o build/day01_2
	./build/day01_2 < $(DATA_PATH)/day01.txt

.PHONY: day02_1
day02_1: build
	$(CC) $(LIBS) $(CFLAGS) day02_1.c -o build/day02_1
	./build/day02_1 < $(DATA_PATH)/day02.txt

.PHONY: day02_2
day02_2: build
	$(CC) $(LIBS) $(CFLAGS) day02_2.c -o build/day02_2
	./build/day02_2 < $(DATA_PATH)/day02.txt
