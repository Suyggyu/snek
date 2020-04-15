EXE = snek

SRC_DIR = src
OBJ_DIR = obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

PPFLAGS := -I./$(SRC_DIR)
FLAGS = -Wall -Wextra -pedantic -O3

LDLIBS = 
LDFLAGS = -static-libstdc++ -static-libgcc

.PHONY: all clean files

all: $(EXE)


ifeq ($(OS), Windows_NT)

clean:
	rmdir /s /q $(OBJ_DIR)
	del $(EXE).exe
else
LDLIBS += -lncurses

clean:
	rm -rf $(OBJ_DIR) $(EXE)
endif


$(EXE): $(OBJ)
	g++ $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	g++ $(PPFLAGS) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

files:
	@echo "exe: $(EXE)"