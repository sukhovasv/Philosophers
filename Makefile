NAME		:= philo
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
DEBUG_FLAGS	:= -g
BUILD_DIR	= out
BIN_DIR		= .
OBJ_DIR		= $(BUILD_DIR)/obj
SRC_DIR		= src
INCLUDES	:= -Iinclude
CFLAGS		+= $(INCLUDES)
RM 			:= rm -rf

ifeq ($(DEBUG),1)
CFLAGS += $(DEBUG_FLAGS)
endif

SRCS = src/main.c src/eat.c src/forks.c src/init_data.c src/monitoring.c src/parse.c src/routine.c src/state.c src/time.c src/utils.c src/actions.c src/get.c src/get_time.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(BIN_DIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
