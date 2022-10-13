NAME		:= megaphone

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
RM			:= rm -f

ifdef STD
	CXXFLAGS	+=	-std=c++98
endif

SRCS	:= \
				megaphone.cpp
				

OBJS		= $(SRCS:.cpp=.o)

.PHONY:			all std clean fclean re

all:			$(NAME)

std:			fclean
				$(MAKE) STD=true

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

$(NAME):		$(OBJS)
				$(CXX) $(CFLAGS) $^ -o $@