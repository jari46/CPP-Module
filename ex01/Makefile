NAME		:= phonebook0

CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -g
RM			:= rm -f

ifdef std
	CXXFLAGS	+=	-std=c++98
endif

SRCS	:= \
				Main.cpp \
				Contact.cpp \
				PhoneBook.cpp

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