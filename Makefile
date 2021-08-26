NAME		=	get_next_line.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

AR			=	ar rcs

RL 			= 	ranlib

SRCS		=	$(wildcard *.c)

OBJECTS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@ echo Generating $(NAME)..
			@ $(AR) $(NAME) $(OBJECTS)
			@ $(RL) $(NAME)

.c.o:
			@ echo Compiling $(<:.c=.o)..
			@ $(CC) $(CFLAGS) -c $< -o $@

clean:
			@ echo Cleaning up..
			@ $(RM) $(OBJECTS)

fclean:		clean
			@ echo Removing $(NAME)..
			@ $(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
