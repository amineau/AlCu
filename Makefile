CC =	/usr/bin/clang
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir

NAME = alum1

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/includes
LIBPATH =	$(ROOT)/libft
LFTHPATH =	$(LIBPATH)/includes

CFLAGS = -Wall -Werror -Wextra -I $(HPATH) -I $(LFTHPATH)
LIBS = -L $(LIBPATH) -lft

SRC = main.c \
	  alum_read.c \
	  alum_tab.c \
	  alum_display.c \
	  alum_game.c \
	  alum_ia.c

OFILES = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "$(NAME) : Building Libft"
	@$(MAKE) -C $(LIBPATH)
	@echo "$(NAME) : Building $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "\x1B[32mDone !\x1B[0m"

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "$(NAME) : Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "$(NAME) : Creating objs directory"
	@$(MKDIR) $@

clean:
	@echo "$(NAME) : Deleting objs"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "$(NAME) : Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\x1B[32mDone !\x1B[0m"

lib.fclean:
	@$(MAKE) fclean -C $(LIBPATH)

re: fclean all

# little memo
# $@ = rule's name
# $^ = all the rule dependecies
# $< = only the first dependence

# Color for c
#   NRM  "\x1B[0m"
#   RED  "\x1B[31m"
#   GRN  "\x1B[32m"
#   YEL  "\x1B[33m"
#   BLU  "\x1B[34m"
#   MAG  "\x1B[35m"
#   CYN  "\x1B[36m"
#   WHT  "\x1B[37m"
