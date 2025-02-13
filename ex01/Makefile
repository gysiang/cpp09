CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I include -MMD -MP -g

TARGET = RPN

# Define source and object directories
SRC_DIR = src
OBJ_DIR = obj

# Automatically get all .cpp files in the source directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Generate object file names from source files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

DEPS = $(OBJS:.o=.d)

# Define test input (each input should be enclosed in double quotes)
TEST_INPUTS = "8 9 * 9 - 9 - 9 - 4 - 1 +" \
			  "7 7 * 7 -" \
			  "1 2 * 2 / 2 * 2 4 - +" \
			  "(1 + 1)"

# Define the test command
TEST_CMD = ./$(TARGET)

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Add a new target for testing
test: $(TARGET)
	@echo "Running tests..."
	@for input in $(TEST_INPUTS); do \
		echo "Input: $$input"; \
		$(TEST_CMD) "$$input"; \
		echo "----------------"; \
	done

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re test
