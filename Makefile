##
## Makefile for  in /home/foncel_a/UQAR/rendu/ProjetInformatique_Automne_2017
## 
## Made by Anaïs Foncel
## Login   <foncel_a@epitech.net>
## 
## Started on  Sun Nov 12 06:36:25 2017 Anaïs Foncel
## Last update Sun Nov 12 10:08:43 2017 Anaïs Foncel
##

NAME		= bombertrash

NAME_MAP	= mapgenerator

SRCS		= main.cpp		\
		  Errors.cpp		\
		  Player.cpp		\
		  map.cpp		\
		  Bombe.cpp		\
		  tools.cpp		\
		  MenuCore.cpp		\
		  Core.cpp		\
		  fileManager.cpp	\
		  IA.cpp		\
		  Son.cpp		\
		  GUIBonus.cpp		\
		  HUD.cpp

SRCS_MAP	= main.cpp

CXX		= g++

RM		= rm -f

BIN_NAME	= $(addprefix bin/, $(NAME))

BIN_NAME_MAP	= $(addprefix bin_generator/, $(NAME_MAP))

LIB_DIR		= irrlicht

SRCS_DIR	= srcs

SRCS_DIR_MAP	= map_generator

OBJS_DIR	= bin

OBJS_DIR_MAP	= bin_generator

CPPFLAGS	= -I$(LIB_DIR)/include -Iinclude -std=c++11
CXXFLAGS	= -W -Wall -Werror

LDFLAGS		+= -I./include/
LDFLAGS		+= -L$(LIB_DIR)/ -lIrrlicht
LDFLAGS		+= -lGL -lXxf86vm -lXext -lX11 -lXcursor
LDFLAGS		+=  -L./irrlicht/include/lib ./irrlicht/include/libsfml-audio.so ./irrlicht/include/libsfml-system.so

SRCS_BIN	= $(addprefix $(SRCS_DIR)/, $(SRCS))

SRCS_BIN_MAP	= $(addprefix $(SRCS_DIR_MAP)/, $(SRCS_MAP))

OBJS_BIN	= $(addsuffix .o, $(basename $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS_BIN))))

OBJS_BIN_MAP	= $(addsuffix .o, $(basename $(subst $(SRCS_DIR_MAP), $(OBJS_DIR_MAP), $(SRCS_BIN_MAP))))

DEPS_BIN	= $(addsuffix .d, $(basename $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS_BIN))))

# addprefix <prefix>, <source> : add <prefix> before <source>   | main.c -> src/main.c
# subst <a>, <b>, <source> : replace <a> by <b> in <source>     | src/main.c -> bin/main.c
# basename <source> : remove extension from <source>            | bin/main.c -> bin/main
# addsuffix <suffix>, <source> : add <suffix> behind <source>   | bin/main -> bin/main.o

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(shell mkdir -p $(OBJS_DIR))
	@$(CXX) -c -o $@ $^ $(CPPFLAGS)
	@echo "g++ -c -o $@ $^"

$(OBJS_DIR_MAP)/%.o: $(SRCS_DIR_MAP)/%.cpp
		$(shell mkdir -p $(OBJS_DIR_MAP))
		@$(CXX) -c -o $@ $^ $(CPPFLAGS)
		@echo "g++ -c -o $@ $^"

$(NAME): $(OBJS_BIN)
	@$(CXX) $(OBJS_BIN) -o $(NAME) $(LDFLAGS)
	@echo -e "g++ -o $(NAME)"
	export LD_LIBRARY_PATH="./irrlicht/include"

$(NAME_MAP): $(OBJS_BIN_MAP)
	@$(CXX) $(OBJS_BIN_MAP) -o $(NAME_MAP) $(LDFLAGS)
	@echo -e "g++ -o $(NAME_MAP)"

all: $(NAME) $(NAME_MAP)

clean:
	$(warning Cleaning ...)
	$(RM) $(OBJS_BIN) $(DEPS_BIN)
	$(RM) $(OBJS_BIN_MAP)

fclean: clean
	$(RM) $(BIN_NAME) $(NAME)
	$(RM) $(BIN_NAME_MAP) $(NAME_MAP)

re: fclean all

.PHONY: all clean fclean re
