NAME := push_swap

SRCS_DIR := srcs

SRCS := push_swap.c \
	utils.c \
	utils2.c \
	instructions.c \
	instructions2.c \
	instructions3.c \
	split.c \
	print.c \
	init.c \
	init2.c \
	check.c \
	find.c \
	sort.c \
	solve.c \
	solve2.c \
	solve3.c \
	../../ft_printf_fd/ft_add_struct.c \
	../../ft_printf_fd/ft_itoa.c \
	../../ft_printf_fd/ft_output.c \
	../../ft_printf_fd/ft_print_cux_and_add_struct2.c \
	../../ft_printf_fd/ft_print_d.c \
	../../ft_printf_fd/ft_print_d2.c \
	../../ft_printf_fd/ft_print_p.c \
	../../ft_printf_fd/ft_print_p2.c \
	../../ft_printf_fd/ft_print_s.c \
	../../ft_printf_fd/ft_print_s2.c \
	../../ft_printf_fd/ft_printf.c \
	../../get_next_line/get_next_line.c \
	../../get_next_line/get_next_line_utils.c

OBJ_DIR := objs

OBJECTS := $(addprefix ${OBJ_DIR}/, ${SRCS:.c=.o})

HEADERS_FOLDER := includes/

CC := gcc

RM := rm -f

CFLAGS := -Wall -Wextra -Werror -I${HEADERS_FOLDER}

all: ${NAME}

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${NAME}: ${OBJ_DIR} ${OBJECTS}
	@echo "Making push_swap"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJECTS}

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files"
	@${RM} ${OBJECTS}
	@rm -rf ${OBJ_DIR}
	rm -rf push_swap.dSYM

fclean: clean

	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
