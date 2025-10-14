NAME = phone


OUTDIR = out
SRCDIR = src
INCLUDES = includes

SRCS =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp \
		PhoneBookInterface.cpp

VPATH		= $(CURDIR)/$(SRCDIR)
OBJS		= $(addprefix $(OUTDIR)/, $(SRCS:.cpp=.o))

INCFLAGS	= -I$(CURDIR)/$(INCLUDES)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

all: $(NAME)

$(NAME): $(OUTDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
