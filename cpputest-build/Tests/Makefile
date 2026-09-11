CC       = gcc
CXX      = g++
CFLAGS   = -c -Wall -Wextra -std=gnu99   -g -O0
CXXFLAGS = -c -Wall -Wextra -std=gnu++17 -g -O0
LDFLAGS  = -pthread

BUILD_DIR    = build
SRC_DIR      = ../Src
TEST_DIR     = tests
MOCKS_DIR    = mocks
CPPUTEST_DIR = cpputest

# Framework objects live outside BUILD_DIR to survive 'make clean'
CPPUTEST_OBJ_DIR = $(CPPUTEST_DIR)/obj

###########################################
#                INCLUDES
###########################################

INCLUDES += -I $(CPPUTEST_DIR)/include
INCLUDES += -I ../Inc
INCLUDES += -I $(TEST_DIR)
INCLUDES += -I $(MOCKS_DIR)

###########################################
#            CPPUTEST DEFAULTS
###########################################

# Disable memory leak detection; if changed, run 'make clean-cpputest' too
DEFINES += -DCPPUTEST_MEM_LEAK_DETECTION_DISABLED

# Test executable flags (-c = colored output)
RUN_FLAGS = -c

############################################
#               SOURCE FILES
############################################

# Production code under test
OBJS      += $(BUILD_DIR)/led.o

# Test cases and the runner
TEST_OBJS += $(BUILD_DIR)/LedTest.o
TEST_OBJS += $(BUILD_DIR)/AllTests.o

# CppUTest framework + CppUMock
CPPUTEST_SRCS  = $(wildcard $(CPPUTEST_DIR)/src/CppUTest/*.cpp)
CPPUTEST_SRCS += $(filter-out %/GTest.cpp,$(wildcard $(CPPUTEST_DIR)/src/CppUTestExt/*.cpp))
CPPUTEST_SRCS += $(CPPUTEST_DIR)/src/Platforms/Gcc/UtestPlatform.cpp
CPPUTEST       = $(patsubst $(CPPUTEST_DIR)/src/%.cpp,$(CPPUTEST_OBJ_DIR)/%.o,$(CPPUTEST_SRCS))

all: $(BUILD_DIR) $(BUILD_DIR)/run_tests
	./$(BUILD_DIR)/run_tests $(RUN_FLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

$(BUILD_DIR)/%.o: $(MOCKS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

$(CPPUTEST_OBJ_DIR)/%.o: $(CPPUTEST_DIR)/src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

$(BUILD_DIR)/run_tests: $(TEST_OBJS) $(OBJS) $(CPPUTEST)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)/*

clean-cpputest:
	rm -rf $(CPPUTEST_OBJ_DIR)
