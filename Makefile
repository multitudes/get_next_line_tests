# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I../

# Add a variable for BUFFER_SIZE
BUFFER_SIZE ?= 10

# Source files
SRCS = ../get_next_line.c ../get_next_line_utils.c
TEST_SRC = get_next_line_tests.c

# Object files
OBJS = $(SRCS:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

# Executable name
TESTS = get_next_line_tests

# Compilation rules
all: $(TESTS)

$(TESTS): $(OBJS) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -DBUFFER_SIZE=$(BUFFER_SIZE) $^ -o $@
	sh ./runtests.sh
	
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJ)

fclean: clean
	rm -f $(TESTS)

re: fclean all

.PHONY: all clean fclean re 


#will not work on mac
valgrind:
	@echo
	@echo "==================\nLaunching valgrind..."
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)
