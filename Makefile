EXEC = ft_select

CC = clang
CFLAGS = -Werror -Wextra -Wall 

INCLUDES = -Iincludes -Ilibft/includes

LIBS = libft/libft.a -ltermcap

SRCDIR = srcs/
OBJDIR = objs/

SRC_FILES = main.c \

DIRS = $(OBJDIR)

OBJS = $(SRC_FILES:%.c=$(OBJDIR)%.o)

.SILENT:

all: directories $(EXEC)

$(EXEC):
	@($(MAKE) -C libft)
	@echo "\\033[1;34m--- $(EXEC) compilation ---\\033[39m"
	@echo "\\033[1;35mObjects compilation : \\033[39m"
	$(MAKE) $(OBJS)
	@echo "\n\033[1;35mFinal compilation\\033[0;39m"
	$(CC) -o $@ $(OBJS) $(LIBS)
	@echo "\\033[1;34m--- $(EXEC) compilation done ---\\033[39m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	echo -n "\\033[1;32m.\\033[0;39m"
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: directories re clean fclean

re: fclean all

clean:
	rm -rf $(OBJDIR)
	echo "\033[32m--- Objects form $(EXEC) deleted ---\\033[0;39m"
	#@($(MAKE) -C libft $@)

fclean: clean
	rm -rf $(EXEC)
	echo "\033[32m--- $(EXEC) deleted ---\\033[0;39m"
	#@($(MAKE) -C libft $@)

directories: $(DIRS)

$(DIRS):
	mkdir $@
