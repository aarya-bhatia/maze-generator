SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj
EXE := $(BIN_DIR)/main

CXX := g++
EXT := cpp
CXXFLAGS := -Wall -g -std=c++14 # -o1

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

##########################################

TEST_DIR := test
TEST_SRC := $(shell find $(TEST_DIR) -name *.cpp)
TEST_OBJ_DIR := $(OBJ_DIR)/$(TEST_DIR)
TEST_OBJ := $(TEST_SRC:$(TEST_DIR)/%.cpp=$(TEST_OBJ_DIR)/%.o)
TEST_EXE := $(BIN_DIR)/test
TEST_INC := -I $(TEST_DIR) -I $(SRC_DIR)/math

##########################################

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

##########################################

$(TEST_EXE): $(TEST_OBJ) | make-bin
	g++ $^ -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_SRC) | make-test-obj-dir
	$(CXX) $(CXXFLAGS) $(TEST_INC) -c $< -o $@

make-bin:
	mkdir -p $(BIN_DIR);

make-test-obj-dir:
	mkdir -p $(TEST_OBJ_DIR)

clean-test:
	rm $(TEST_EXE) $(TEST_OBJ)

##########################################

# remove bin and obj dirs
clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)