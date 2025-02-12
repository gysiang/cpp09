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

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
