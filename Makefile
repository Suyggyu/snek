EXE = snek

SRC_DIR = src
OBJ_DIR = obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

PPFLAGS = 
FLAGS = -Wall -Wextra -pedantic -O3

LDLIBS = 
LDFLAGS = -static-libstdc++ -static-libgcc

.PHONY: all clean files


ifeq ($(OS), Windows_NT)
EXE := $(EXE)_windows.exe

all: $(EXE)

clean:
	rmdir /s /q $(OBJ_DIR)

else
EXE := $(EXE)_linux
LDLIBS += -lncurses
LDFLAGS =

all: $(EXE)

clean:
	rm -rf $(OBJ_DIR)

endif


$(EXE): $(OBJ)
	g++ $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	g++ $(PPFLAGS) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

files:
	@echo "exe: $(EXE)"
	@echo "src: $(SRC)"
	@echo "obj: $(OBJ)"
