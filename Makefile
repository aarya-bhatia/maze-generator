SRC_DIR := src

BIN_DIR := bin

OBJ_DIR := obj

EXE := $(BIN_DIR)/main

CXX := g++

EXT := cpp

CXXFLAGS := -Wall -g -std=c++14

SRC := $(shell find $(SRC_DIR) -name *.cpp)

OBJS := $(SRC:$(SRC_DIR)/%.$(EXT)=$(OBJ_DIR)/%.o)

INC_FLAGS := $(addprefix -I, $(shell find $(SRC_DIR) -type d))
# INC_FLAGS := $(addprefix -I, $(dir $(SRC))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

LDLIBS := -lsfml-graphics -lsfml-system -lsfml-window

.PHONY: all clean
all: $(EXE)

$(EXE): $(OBJS)
	mkdir -p $(dir $@);
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(EXT)
	mkdir -p $(dir $@);
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

infoSrc:
	echo $(SRC)

infoObj:
	echo $(OBJS)

infoCppflags:
	echo $(CPPFLAGS)

clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)