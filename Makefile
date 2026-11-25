# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 17:48:44 by svogrig           #+#    #+#              #
#    Updated: 2026/11/25 20:38:58 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS		+=	--no-print-directory

GREEN			:=	\033[32m
BOLD_GREEN		:=	\033[1;32m
NC				:=	\033[0m

NAME			:=	scop
NAME_DEBUG		:=	scopdbg

# sources ---------------------------------------------------------------------#

DIR_SRC			:=	src
SRC				:=  $(wildcard $(DIR_SRC)/*.cpp)

DIR_BUILD		:=	.build
DIR_TMP			:=	$(DIR_BUILD)/tmp

# libraries -------------------------------------------------------------------#

DIR_LIBS		:=	libs
DIR_LIB			:=	$(DIR_LIBS)/lib
DIR_LIBS_INC	:=	$(DIR_LIBS)/include

CMAKE			:=	$(shell command -v cmake 2>/dev/null)
ifeq ($(CMAKE),)
CMAKE = $(DIR_LIBS)/cmake/bin/cmake
endif
CMAKE_DIR		:=	$(DIR_LIBS)/cmake
CMAKE_DIR_TMP	:=	$(DIR_TMP)/cmake

GLFW_LIB		:=	$(DIR_LIB)/libglfw3.a
GLFW_DIR_TMP	:=	$(DIR_TMP)/glfw

LDLIBS			:=	$(GLFW_LIB) -lGL -ldl -lpthread -lX11

# includes --------------------------------------------------------------------#

DIR_INC			:=	include
CPPFLAGS		:=	-I$(DIR_INC) -I$(DIR_LIBS_INC)
DEP_FLAGS		:=	-MMD -MP


# objects ---------------------------------------------------------------------#

DIR_OBJ_REL		:=	$(DIR_BUILD)/release
DIR_OBJ_DBG		:=	$(DIR_BUILD)/debug

OBJ_REL			:=	$(addprefix $(DIR_OBJ_REL)/, $(SRC:.cpp=.o))
OBJ_DBG			:=	$(addprefix $(DIR_OBJ_DBG)/, $(SRC:.cpp=.o))
DEPS			:=	$(OBJ:.o=.d)

# compilation -----------------------------------------------------------------#

CXX 			:= 	c++
CXXFLAGS		:= 	-Wall -Werror -Wextra -std=c++17
DEBUGFLAGS		:=  -g -O0

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

.PHONY:	all
all: $(NAME)

.PHONY:	clean
clean:
	@if [ -d $(DIR_BUILD) ]; then \
		rm -rf $(DIR_BUILD); \
		printf "Cleaned : $(DIR_BUILD)\n"; \
	fi

.PHONY:	fclean
fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "Cleaned : $(NAME)\n"; \
	fi; \
	if [ -f $(NAME_DEBUG) ]; then \
		rm -f $(NAME_DEBUG); \
		printf "Cleaned : $(NAME_DEBUG)\n"; \
	fi; \
	if [ -d $(DIR_LIBS) ]; then \
		rm -rf $(DIR_LIBS); \
		printf "Cleaned : $(DIR_LIBS)\n"; \
	fi

.PHONY:	re
re: fclean all

.PHONY:	run
run: $(NAME)
	@./$(NAME)

.PHONY: debug
debug: $(NAME_DEBUG)

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

.PHONY:	check_deps
check_deps:
	@for h in X11/Xlib.h X11/extensions/Xrandr.h X11/extensions/Xinerama.h \
			X11/Xcursor/Xcursor.h X11/extensions/XInput2.h GL/glcorearb.h; do \
		echo "#include <$$h>" | $(CXX) -E -x c++ - >/dev/null 2>&1 \
			|| { echo "Missing header: $$h"; exit 1; }; \
	done

#------------------------------------------------------------------------------#
# compilation                                                                  #
#------------------------------------------------------------------------------#

$(DIR_OBJ_REL)/%.o: %.cpp Makefile | $(GLFW_LIB)
	@mkdir -p $(@D)
	@printf "Compiling : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(DEP_FLAGS) -o $@ -c $<
	@printf "$(GREEN)done$(NC)\n"

$(DIR_OBJ_DBG)/%.o: %.cpp Makefile | $(GLFW_LIB)
	@mkdir -p $(@D)
	@printf "Compiling (debug) : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $(CPPFLAGS) $(DEP_FLAGS) -o $@ -c $<
	@printf "$(GREEN)done$(NC)\n"

#------------------------------------------------------------------------------#
# linkage                                                                      #
#------------------------------------------------------------------------------#

$(NAME): $(OBJ_REL) $(GLFW_LIB)
	@printf "Creating : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(OBJ_REL) $(LDLIBS) -o $@
	@printf "$(BOLD_GREEN)done$(NC)\n"

$(NAME_DEBUG): $(OBJ_DBG) $(GLFW_LIB)
	@printf "Creating : %s ... " $@
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $(OBJ_DBG) $(LDLIBS) -o $@
	@printf "$(BOLD_GREEN)done$(NC)\n"

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

-include $(DEPS)
