# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artclave <artclave@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:34:18 by arturo            #+#    #+#              #
#    Updated: 2024/07/25 16:00:00 by artclave         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
INCDIR = includes
BINDIR = bin
OBJDIR = $(BINDIR)/obj

SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/ClapTrap.cpp \
	   $(SRCDIR)/ScavTrap.cpp \

OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

HEADERS = $(INCDIR)/ClapTrap.hpp \
		  $(INCDIR)/ScavTrap.hpp \

EXEC = ScavTrap

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(BINDIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

leaks: all
	valgrind --leak-check=full ./$(EXEC)

run: all
	./$(EXEC)

.PHONY: all clean fclean re
