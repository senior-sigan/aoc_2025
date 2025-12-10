DATA ?= data
DAY ?= 01
PART ?= 1
CC= clang
RM= rm -f

CFLAGS= -Wall -Wextra -pedantic -std=c23 -ggdb # -Werror
LIBS= -lm

all: day01_1 day01_2

build:
	mkdir -p build

.PHONY: day
day: build
	$(CC) $(LIBS) $(CFLAGS) day$(DAY)_$(PART).c -o build/day$(DAY)_$(PART)
	./build/day$(DAY)_$(PART) < $(DATA)/day$(DAY).txt
