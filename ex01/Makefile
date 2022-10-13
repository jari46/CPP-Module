NAME		:= phonebook0

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
RM			:= rm -f

ifdef STD
	CXXFLAGS	+=	-std=c++98
endif

ifdef DEBUG
	CXXFLAGS	+=	 -g
endif

SRCS	:= \
				Main.cpp \
				Contact.cpp \
				PhoneBook.cpp

OBJS		= $(SRCS:.cpp=.o)

.PHONY:			all std debug clean fclean re

all:			$(NAME)

std:			fclean
				$(MAKE) STD=true

debug:			fclean
				$(MAKE) DEBUG=true

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $^ -o $@