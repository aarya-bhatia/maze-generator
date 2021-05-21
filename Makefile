SRC_DIR := src

BIN_DIR := bin

OBJ_DIR := obj

TEST_DIR := test

EXE := $(BIN_DIR)/main

CXX := g++

EXT := cpp

CXXFLAGS := -Wall -g -std=c++14

SRC := $(shell find $(SRC_DIR) -name *.cpp)

OBJS := $(SRC:$(SRC_DIR)/%.$(EXT)=$(OBJ_DIR)/%.o)

INC_FLAGS := $(addprefix -I, $(shell find $(SRC_DIR) -type d))

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

test: $(BIN_DIR)/$(TEST_DIR)/hello

$(BIN_DIR)/$(TEST_DIR)/%: $(OBJ_DIR)/$(TEST_DIR)/%.o
	mkdir -p $(dir $@);
	$(CXX) $^ -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(dir $@);
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)