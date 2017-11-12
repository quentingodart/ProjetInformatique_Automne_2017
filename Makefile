##
## Makefile for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017
## 
## Made by Anaïs Foncel
## Login   <foncel_a@epitech.net>
## 
## Started on  Sun Nov 12 06:36:25 2017 Anaïs Foncel
## Last update Sun Nov 12 09:17:22 2017 Anaïs Foncel
##

NAME		= bomberman

SRCS		= main.cpp	\
		  Player.cpp

CXX		= g++

RM		= rm -f

BIN_NAME	= $(addprefix bin/, $(NAME))

LIB_DIR		= irrlicht

SRCS_DIR	= srcs

OBJS_DIR	= bin

CPPFLAGS	= -I$(LIB_DIR)/include -Iinclude -std=c++11
CXXFLAGS	= -W -Wall -Werror

LDFLAGS		+= -L$(LIB_DIR)/ -lIrrlicht
LDFLAGS		+= -lGL -lXxf86vm -lXext -lX11 -lXcursor
LDFLAGS		+=  -L./irrlicht/include/lib ./irrlicht/include/libsfml-audio.so ./irrlicht/include/libsfml-system.so

SRCS_BIN	= $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS_BIN	= $(addsuffix .o, $(basename $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS_BIN))))

DEPS_BIN	= $(addsuffix .d, $(basename $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS_BIN))))

# addprefix <prefix>, <source> : add <prefix> before <source>   | main.c -> src/main.c
# subst <a>, <b>, <source> : replace <a> by <b> in <source>     | src/main.c -> bin/main.c
# basename <source> : remove extension from <source>            | bin/main.c -> bin/main
# addsuffix <suffix>, <source> : add <suffix> behind <source>   | bin/main -> bin/main.o

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(shell mkdir -p $(OBJS_DIR))
	@$(CXX) -c -o $@ $^ $(CPPFLAGS)
	@echo "g++ -c -o $@ $^"

$(NAME): $(OBJS_BIN)
	@$(CXX) $(OBJS_BIN) $(LDFLAGS) -o $(NAME)
	@echo -e "g++ -o $(NAME)"
	export LD_LIBRARY_PATH="./irrlicht/include"

all: $(NAME)

clean:
	$(warning Cleaning ...)
	$(RM) $(OBJS_BIN) $(DEPS_BIN)

fclean: clean
	$(RM) $(BIN_NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re
