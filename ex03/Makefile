NAME		= ./diamondtrap
CXX			= c++
CXXFLAGS	= -O3 -Wall -Wextra -Werror -I. -std=c++98 -MMD -g3
RM			= rm -rf

OBJ_DIR		= obj/
SRCS		= main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp\
			DiamondTrap.cpp

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS		= $(OBJS:.o=.d)


all:
	@TOTAL=$$($(MAKE) -n $(NAME) 2>/dev/null | grep -c "\[PROGRESS\]"); \
	if [ $$TOTAL -eq 0 ]; then \
		$(MAKE) --no-print-directory $(NAME); \
	else \
		$(MAKE) --no-print-directory $(NAME) | awk -v total=$$TOTAL ' \
		BEGIN { count = 0; } \
		/^\[PROGRESS\]/ { \
			count++; \
			percent = int(count * 100 / total); \
			printf "\r\033[1;36m[%3d%%]\033[0m Compiling : \033[1;33m%s\033[0m... \033[K", percent, substr($$0, 12); \
			fflush(); \
			next; \
		} \
		{ print $$0; fflush(); } \
		'; \
	fi

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "\n\033[1;32m[✓] Compilation done '$(NAME)' is ready\033[0m\n"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "[PROGRESS] $<"

-include $(DEPS)

clean:
	@$(RM) $(OBJ_DIR)
	@printf "\033[1;90m[✓] Cleaning obj (.o et .d).\033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[1;90m[✓] Binary deleted.\033[0m\n"

re: fclean all
.PHONY: all clean fclean re