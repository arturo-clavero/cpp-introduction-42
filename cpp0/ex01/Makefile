# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arturo <arturo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:34:18 by arturo            #+#    #+#              #
#    Updated: 2024/06/27 15:03:56 by arturo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
INCDIR = includes
BINDIR = bin
OBJDIR = $(BINDIR)/obj

# List all source files explicitly
SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/Contact.cpp \
       $(SRCDIR)/PhoneBook.cpp

# Generate corresponding object file paths
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Specify header files
HEADERS = $(INCDIR)/PhoneBook.hpp \
          $(INCDIR)/Contact.hpp

EXEC = executable

# Default target
all: $(EXEC)

# Linking executable from object files
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compiling each source file to object file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean build artifacts
clean:
	rm -rf $(BINDIR)

# Full clean including executable
fclean: clean
	rm -f $(EXEC)

# Rebuild entire project
re: fclean all

# Phony targets to prevent conflict with files of same name
.PHONY: all clean fclean re
