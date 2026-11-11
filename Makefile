# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 17:48:44 by svogrig           #+#    #+#              #
#    Updated: 2026/11/11 19:12:07 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS		+= --no-print-directory

GREEN			:=	\033[32m
BOLD_GREEN		:=	\033[1;32m
NC				:=	\033[0m

NAME			:= scop

# includes --------------------------------------------------------------------#

DIR_INC			:=	include
CPPFLAGS 		:=	$(addprefix -I,$(DIR_INC))
DEP_FLAGS		:=	-MMD -MP

# sources ---------------------------------------------------------------------#

DIR_SRC			:=	src
SRC				:=	main.cpp

SRC				:=	$(addprefix $(DIR_SRC)/, $(SRC))

# objects ---------------------------------------------------------------------#

DIR_OBJ			:=	.build
OBJ				:=	$(addprefix $(DIR_OBJ)/, $(SRC:.cpp=.o))
DEPS            :=	$(OBJ:.o=.d)

# compilation -----------------------------------------------------------------#

CXX 			:= 	c++
CXXFLAGS 		:= 	-Wall -Werror -Wextra -std=c++17

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: $(NAME)

clean:
	@if [ -d $(DIR_OBJ) ]; then \
		rm -rf $(DIR_OBJ); \
		printf "Cleaned : $(DIR_OBJ)\n"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "Cleaned : $(NAME)\n"; \
	fi

re: fclean all

run: $(NAME)
	@./$(NAME)

#------------------------------------------------------------------------------#
# compilation                                                                  #
#------------------------------------------------------------------------------#

$(DIR_OBJ)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	@printf "Compiling : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(DEP_FLAGS) -o $@ -c $<
	@printf "$(GREEN)done$(NC)\n"

#------------------------------------------------------------------------------#
# linkage                                                                      #
#------------------------------------------------------------------------------#

$(NAME): $(OBJ)
	@printf "Creating : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@printf "$(BOLD_GREEN)done$(NC)\n"

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

-include $(DEPS)

.PHONY:	all \
		clean \
		fclean \
		re \
		run
