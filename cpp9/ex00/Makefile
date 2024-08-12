# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artclave <artclave@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:34:18 by arturo            #+#    #+#              #
#    Updated: 2024/08/13 01:27:57 by artclave         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
INCDIR = includes
BINDIR = bin
OBJDIR = $(BINDIR)/obj


SRCS = main.cpp \
		BitcoinExchange.cpp

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

EXEC = BitcoinExchange

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -MMD -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(BINDIR)

fclean: clean
	rm -f $(EXEC)

leaks: all
	valgrind --leak-check=full ./$(EXEC)

run: all
	$(MAKE) find-and-run

find-and-run:
	@FILE=$(shell find . -name '*.txt' | head -n 1) ; \
	if [ -n "$$FILE" ]; then \
		echo "Running with $$FILE"; \
		./$(EXEC) $$FILE; \
	else \
		echo "No .txt files found."; \
	fi
	
re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re