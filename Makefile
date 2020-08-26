TARGET = mathlib.a

SRC = $(wildcard src/*)

OBJ = $(notdir $(SRC:%.cpp=%.o))

INC = -I inc

%.o: src/%.cpp
	clang++ -std=c++17 -c $< $(INC)

all: $(OBJ)
	ar -cr $(TARGET) $(OBJ)

uninstall u:
	@rm $(TARGET)
	@rm $(OBJ)

test:
	clang++ -std=c++17 $(INC) $(TARGET) main.cpp