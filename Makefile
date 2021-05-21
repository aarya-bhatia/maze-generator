SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj
TEST_DIR := test

EXE := $(BIN_DIR)/main

CXX := g++
EXT := cpp
CXXFLAGS := -Wall -g -std=c++14 -o1

# find all src files in src dir
SRC := $(shell find $(SRC_DIR) -name *.cpp)

# substitue src and .cpp with obj and .o for all src files
OBJS := $(SRC:$(SRC_DIR)/%.$(EXT)=$(OBJ_DIR)/%.o)

# include all dirs in src dir in compilation
INC_FLAGS := $(addprefix -I, $(shell find $(SRC_DIR) -type d))

# preprocessor flags(-mmd -mp will generate .d files)
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# sfml libs
LDLIBS := -lsfml-graphics -lsfml-system -lsfml-window

.PHONY: all clean
all: $(EXE)

# link all object files in obj dir to create target exe in bin dir
$(EXE): $(OBJS)
	mkdir -p $(dir $@);
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

# compile all src files in src dir to create obj files in obj dir
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(EXT)
	mkdir -p $(dir $@);
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# create exe for all tests in test dir
test: $(BIN_DIR)/$(TEST_DIR)/hello

$(BIN_DIR)/$(TEST_DIR)/%: $(OBJ_DIR)/$(TEST_DIR)/%.o
	mkdir -p $(dir $@);
	$(CXX) $^ -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(dir $@);
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# remove bin and obj dirs
clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)