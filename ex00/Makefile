CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I include -MMD -MP

TARGET = a.out

# Define source and object directories
SRC_DIR = src
OBJ_DIR = obj

SRCS = main.cpp \
	BitcoinExchange.cpp

# Add "src/" prefix for compilation
SRCS_PATH = $(addprefix $(SRC_DIR)/, $(SRCS))

# Generate object file names
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
