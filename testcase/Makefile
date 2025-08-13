# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable names
GENERATOR = generate
TEST_RUNNER = main

# Source files
GENERATOR_SRC = generate.cpp
TEST_RUNNER_SRC = main.cpp
TAY_NGUYEN = tay_nguyen_campaign.cpp

# Folder for test cases
TESTCASE_FOLDER = testcases
OUTPUT_FOLDER = outputs

# Number of test cases
NUM_TESTCASES = 5  # Change this to generate more test cases

all: $(GENERATOR) $(TEST_RUNNER) generate_testcases run_tests

# Compile the testcase generator
$(GENERATOR): $(GENERATOR_SRC)
	$(CXX) $(CXXFLAGS) -o $(GENERATOR) $(GENERATOR_SRC)

# Compile the test runner
$(TEST_RUNNER): $(TEST_RUNNER_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_RUNNER) $(TEST_RUNNER_SRC) $(TAY_NGUYEN) -I .

# Generate test cases
generate_testcases: $(GENERATOR)
	./$(GENERATOR) $(NUM_TESTCASES)

# Run multiple test cases sequentially
run_tests: $(TEST_RUNNER)
	@echo "Running test cases..."
	@for %%f in ($(TESTCASE_FOLDER)/*) do ( \
		echo Running %%f... & \
		$(TEST_RUNNER) $(TESTCASE_FOLDER)/%%f $(OUTPUT_FOLDER)/%%f \
	)

# Clean up compiled binaries and test cases
clean:
	@if exist $(GENERATOR) del /f $(GENERATOR)
	@if exist $(TEST_RUNNER) del /f $(TEST_RUNNER)

.PHONY: all generate_testcases run_tests clean