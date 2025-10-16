NAME = phone


OUTDIR = out
OUTDIR_DEBUG = out_debug
SRCDIR = src
INCLUDES = includes

SRCS =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp \
		PhoneBookInterface.cpp

OBJS = $(addprefix $(OUTDIR)/, $(SRCS:.cpp=.o))
DOBJS = $(addprefix $(OUTDIR_DEBUG)/, $(SRCS:.cpp=.o))
INCFLAGS	= -I$(CURDIR)/$(INCLUDES)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
DBG_CXXFLAGS = -g -fsanitize=address -Wall -Wextra -Werror -std=c++17

all: $(NAME)

$(NAME): $(OUTDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OUTDIR):
	mkdir $(OUTDIR)

$(OUTDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OUTDIR_DEBUG):
	mkdir $(OUTDIR_DEBUG)

$(OUTDIR_DEBUG)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(DBG_CXXFLAGS) $(INCFLAGS) -c $< -o $@

debug: $(OUTDIR_DEBUG) $(DOBJS)
	$(CXX) $(DBG_CXXFLAGS) $(DOBJS) -o $(NAME)

clean:
	rm -rf $(OUTDIR) $(OUTDIR_DEBUG)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
