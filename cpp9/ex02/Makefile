# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arturo <arturo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:34:18 by arturo            #+#    #+#              #
#    Updated: 2024/07/23 11:59:38 by arturo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
INCDIR = includes
BINDIR = bin
OBJDIR = $(BINDIR)/obj


SRCS = main.cpp \
	PmergeMe.cpp\
	   
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

HEADERS = PmergeMe.hpp\

EXEC = PmergeMe

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -MMD -MP -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(BINDIR)

fclean: clean
	rm -f $(EXEC)

leaks: all
	valgrind --leak-check=full ./$(EXEC)

run: all
	./$(EXEC)
	
re: fclean all

.PHONY: all clean fclean re
