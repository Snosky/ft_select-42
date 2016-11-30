EXEC = ft_select

CC = clang
CFLAGS = -Werror -Wextra -Wall

INCLUDES = -Iincludes -Ilibft/includes

LIBFTDIR = libft/
LIBS = libft/libft.a -ltermcap

SRCDIR = srcs/
OBJDIR = objs/

SRC_FILES = main.c \
			ft_term.c \
			ft_error.c \
			ft_tputs.c \
			tputc.c \
			init_term.c \
			reset_default_term.c \
			init_signals.c \
			sig_exit.c \
			sig_win_resize.c \
			sig_stop.c \
			sig_cont.c \
			winsize.c \
			refresh_screen.c \
			init_entries.c \
			print_entries.c \
			free_entries.c \
			get_key.c \
			ft_goto_up.c \
			ft_goto_down.c \
			ft_goto_right.c \
			ft_goto_left.c \
			ft_delete.c \
			do_space.c \
			return_result.c \
			scroll_bar.c \
			refresh_padding_left.c \

DIRS = $(OBJDIR)

OBJS = $(SRC_FILES:%.c=$(OBJDIR)%.o)

all: directories $(EXEC)

$(EXEC): $(OBJS)
	@($(MAKE) -C $(LIBFTDIR))
	$(CC) -o $@ $^ $(LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: directories re clean fclean

re: fclean all

clean:
	rm -rf $(DIRS)
	@($(MAKE) -C $(LIBFTDIR) $@)

fclean: clean
	rm -rf $(EXEC)
	@($(MAKE) -C $(LIBFTDIR) $@)

directories: $(DIRS)

$(DIRS):
	mkdir $@
