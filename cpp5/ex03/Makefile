# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arturo <arturo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:34:18 by arturo            #+#    #+#              #
#    Updated: 2024/07/04 04:24:29 by arturo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
INCDIR = includes
BINDIR = bin
OBJDIR = $(BINDIR)/obj


SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/Bureaucrat.cpp \
	   $(SRCDIR)/AForm.cpp \
	   $(SRCDIR)/Form.cpp \
	   $(SRCDIR)/ShrubberyCreationForm.cpp \
	   $(SRCDIR)/RobotomyRequestForm.cpp \
	   $(SRCDIR)/PresidentialPardonForm.cpp \
	   $(SRCDIR)/Intern.cpp \
	   
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

HEADERS = $(INCDIR)/Bureaucrat.hpp \
		  $(INCDIR)/AForm.hpp \
		  $(INCDIR)/Form.hpp \
	      $(INCDIR)/ShrubberyCreationForm.hpp \
		  $(INCDIR)/RobotomyRequestForm.hpp \
		  $(INCDIR)/PresidentialPardonForm.hpp \
		  $(INCDIR)/Intern.hpp \

EXEC = executable

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
