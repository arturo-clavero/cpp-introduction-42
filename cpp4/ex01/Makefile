# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arturo <arturo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:34:18 by arturo            #+#    #+#              #
#    Updated: 2024/07/23 18:21:07 by arturo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
INCDIR = includes
BINDIR = bin
OBJDIR = $(BINDIR)/obj

SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/Animal.cpp \
	   $(SRCDIR)/Dog.cpp \
	   $(SRCDIR)/Cat.cpp \
	   $(SRCDIR)/WrongAnimal.cpp \
	   $(SRCDIR)/WrongCat.cpp \
	   $(SRCDIR)/Brain.cpp \

OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

HEADERS = $(INCDIR)/Animal.hpp \
		  $(INCDIR)/Cat.hpp \
		  $(INCDIR)/Dog.hpp \
		  $(INCDIR)/WrongAnimal.hpp \
		  $(INCDIR)/WrongCat.hpp \
		  $(INCDIR)/Brain.hpp \

EXEC = Brain

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
