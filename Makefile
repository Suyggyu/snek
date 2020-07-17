EXE = snek

BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

CC = g++

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -pedantic

LDLIBS = 
LDFLAGS = 

.PHONY: all clean files release

ifeq ($(OS), Windows_NT)
EXE := $(BIN_DIR)/$(EXE)_windows.exe
all: $(EXE)

clean:
	del $(OBJ_DIR)\*
else
EXE := $(BIN_DIR)/$(EXE)_linux
all: $(EXE)

LDLIBS += -lncurses

clean:
	rm -rf $(OBJ_DIR)/*
endif

release: FLAGS = -O3
release: LDFLAGS = -static-libstdc++ -static-libgcc
release: clean
release: all	

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir $@

files:
	@echo "exe: $(EXE)"
	@echo "src: $(SRC)"
	@echo "obj: $(OBJ)"
