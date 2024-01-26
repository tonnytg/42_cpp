NAME 	= hibrain
FILES 	= *.cpp

CC 	= c++ 
CC_ARGS	=  -std=c++98 -Wall -Wextra -Werror

all:
	$(CC) $(CC_ARGS) $(FILES) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean

re: fclean all

.PHONY: all clean fclean re
