NAME		:= megaphone

CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
RM			:= rm -f

ifdef std
	CXXFLAGS	+=	-std=c++98
endif

SRCS	:= \
				megaphone.cpp
				

OBJS		= $(SRCS:.cpp=.o)

.PHONY:			all std clean fclean re

all:			$(NAME)

std:			fclean
				$(MAKE) DEBUG=true

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $@