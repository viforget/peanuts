NAME = peanuts

SRC = ft_strdup.c\
	  ft_strjoin.c\
	  main.c\
	  send_mail.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc -o $(NAME) $(SRC)
	@echo "\033[32mCOMPILATION OK\033[0m"

clean :
	@rm -rf $(OBJ)
	@echo "\033[36mCLEAN FILLIT OK\033[0m"

fclean :
	@rm -rf $(OBJ) $(NAME)
	@echo "\033[36mFCLEAN FILLIT OK\033[0m"

re : fclean all

.PHONY: all clean fclean re
