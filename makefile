
CC := g++
CFLAGS :=
NAME := framework

SRC := src
OBJ := bin

SOURCES := $(wildcard $(SRC)/main.cpp $(SRC)/helpers/*.cpp $(SRC)/process/*.cpp $(SRC)/process/*/*.cpp)
DEPS := $(wildcard $(SRC)/*/*.h $(SRC)/*/*/*.h)
OBJECTS := $(patsubst notdir %.cpp,$(OBJ)/%.o,$(SOURCES))

$(OBJ)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean test

clean:
	rm -f $(NAME) $(OBJ)/*.o *~ core $(INCDIR)/*~