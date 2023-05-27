
CC := g++
CFLAGS :=
NAME := run
FRMWK := framework
SRC := src
OBJ := bin

SOURCES := $(wildcard $(FRMWK)/main.cpp $(FRMWK)/*/*.cpp $(SRC)/*.cpp)
DEPS := $(wildcard $(FRMWK)/*/*.h $(SRC)/*.h)
OBJECTS := $(patsubst notdir %.cpp,$(OBJ)/%.o,$(SOURCES))

$(OBJ)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(NAME) $(OBJ)/*.o *~ core $(INCDIR)/*~