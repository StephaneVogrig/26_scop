# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 17:48:44 by svogrig           #+#    #+#              #
#    Updated: 2026/11/11 23:47:40 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS		+=	--no-print-directory

GREEN			:=	\033[32m
BOLD_GREEN		:=	\033[1;32m
NC				:=	\033[0m

NAME			:=	scop

# sources ---------------------------------------------------------------------#

DIR_SRC			:=	src
SRC				:=	main.cpp

SRC				:=	$(addprefix $(DIR_SRC)/, $(SRC))

DIR_BUILD 		:=	.build
DIR_TMP			:=	$(DIR_BUILD)/tmp

# libraries -------------------------------------------------------------------#

DIR_LIBS		:=	libs
DIR_LIB			:=	$(DIR_LIBS)/lib
DIR_LIBS_INC	:=	$(DIR_LIBS)/include

CMAKE 			:=	$(shell command -v cmake 2>/dev/null)
ifeq ($(CMAKE),)
CMAKE = $(DIR_LIBS)/cmake/bin/cmake
endif
CMAKE_DIR	 	:=	$(DIR_LIBS)/cmake
CMAKE_DIR_TMP	:=	$(DIR_TMP)/cmake

GLFW_LIB		:=	$(DIR_LIB)/libglfw3.a
GLFW_DIR_TMP	:=	$(DIR_TMP)/glfw

LDLIBS			:=	$(GLFW_LIB) -lGL -ldl -lpthread -lX11

# includes --------------------------------------------------------------------#

DIR_INC			:=	include
CPPFLAGS 		:=	-I$(DIR_INC) -I$(DIR_LIBS_INC)
DEP_FLAGS		:=	-MMD -MP


# objects ---------------------------------------------------------------------#

OBJ				:=	$(addprefix $(DIR_BUILD)/, $(SRC:.cpp=.o))
DEPS			:=	$(OBJ:.o=.d)

# compilation -----------------------------------------------------------------#

CXX 			:= 	c++
CXXFLAGS 		:= 	-Wall -Werror -Wextra -std=c++17

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: $(NAME)

clean:
	@if [ -d $(DIR_BUILD) ]; then \
		rm -rf $(DIR_BUILD); \
		printf "Cleaned : $(DIR_BUILD)\n"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "Cleaned : $(NAME)\n"; \
	fi; \
	if [ -d $(DIR_LIBS) ]; then \
		rm -rf $(DIR_LIBS); \
		printf "Cleaned : $(DIR_LIBS)\n"; \
	fi

re: fclean all

run: $(NAME)
	@./$(NAME)

$(CMAKE):
	@set -e; \
	printf "CMake not found, downloading portable bin ... "; \
	mkdir -p $(CMAKE_DIR_TMP); \
	curl -sfL https://github.com/Kitware/CMake/releases/download/v3.31.5/cmake-3.31.5-linux-x86_64.tar.gz \
		| tar -xz -C $(CMAKE_DIR_TMP); \
	mkdir -p $(CMAKE_DIR); \
	mv $(CMAKE_DIR_TMP)/cmake-3.31.5-linux-x86_64/* $(CMAKE_DIR)/; \
	rm -rf $(CMAKE_DIR_TMP); \
	printf "$(GREEN)done$(NC)\n"

$(GLFW_LIB): $(CMAKE) | check_deps
	@set -e; \
	rm -rf $(GLFW_DIR_TMP); \
	mkdir -p $(GLFW_DIR_TMP); \
	printf "downloading glfw ... "; \
	git -c advice.detachedHead=false clone --depth 1 --branch 3.4 -q https://github.com/glfw/glfw.git "$(GLFW_DIR_TMP)/src"; \
	printf "$(GREEN)done$(NC)\n"; \
	printf "Compiling glfw ... "; \
	$(CMAKE) -S "$(GLFW_DIR_TMP)/src" -B "$(GLFW_DIR_TMP)/build" \
		-DGLFW_BUILD_EXAMPLES=OFF \
		-DGLFW_BUILD_TESTS=OFF \
		-DGLFW_BUILD_DOCS=OFF \
		-DGLFW_BUILD_WAYLAND=OFF \
		-DCMAKE_BUILD_TYPE=Release > /dev/null; \
	$(CMAKE) --build "$(GLFW_DIR_TMP)/build" -j$$(nproc) > /dev/null; \
	mkdir -p $(DIR_LIB) $(DIR_LIBS_INC); \
	mv $(GLFW_DIR_TMP)/build/src/libglfw3.a $(DIR_LIB)/; \
	cp -r $(GLFW_DIR_TMP)/src/include/GLFW $(DIR_LIBS_INC)/; \
	rm -rf "$(GLFW_DIR_TMP)"; \
	printf "$(GREEN)done$(NC)\n"

check_deps:
	@for h in X11/Xlib.h X11/extensions/Xrandr.h X11/extensions/Xinerama.h \
			X11/Xcursor/Xcursor.h X11/extensions/XInput2.h GL/glcorearb.h; do \
		echo "#include <$$h>" | $(CXX) -E -x c++ - >/dev/null 2>&1 \
			|| { echo "Missing header: $$h"; exit 1; }; \
	done

#------------------------------------------------------------------------------#
# compilation                                                                  #
#------------------------------------------------------------------------------#

$(DIR_BUILD)/%.o: %.cpp Makefile | $(GLFW_LIB)
	@mkdir -p $(@D)
	@printf "Compiling : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(DEP_FLAGS) -o $@ -c $<
	@printf "$(GREEN)done$(NC)\n"

#------------------------------------------------------------------------------#
# linkage                                                                      #
#------------------------------------------------------------------------------#

$(NAME): $(OBJ) $(GLFW_LIB)
	@printf "Creating : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(OBJ) $(LDLIBS) -o $@
	@printf "$(BOLD_GREEN)done$(NC)\n"

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

-include $(DEPS)

.PHONY:	all \
		clean \
		fclean \
		re \
		run \
		check_deps
