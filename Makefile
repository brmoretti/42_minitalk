#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME				=	minitalk
CLIENT				=	client
SERVER				=	server
CC					=	cc
CC_FLAGS			=	-Wall	\
						-Wextra	\
						-Werror	\
						-O2

#≻───░⋆ ✪ PROJECT DIRECTORIES & FILES ✪ ⋆░───────────────────────────────────≺#
SRC_DIR_CLIENT		=	src/client
SRC_DIR_SERVER		=	src/server
INCLUDE_DIR			=	include
INCLUDE_FILES		=	client.h	\
						server.h
INCLUDES			=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE_FILES))
BUILD_DIR			=	build
SRC_FILES_CLIENT	=	client.c	\
						errors.c
SRC_FILES_SERVER	=	server.c
SRCS_CLIENT			=	$(addprefix $(SRC_DIR_CLIENT)/, $(SRC_FILES_CLIENT))
SRCS_SERVER			=	$(addprefix $(SRC_DIR_SERVER)/, $(SRC_FILES_SERVER))
OBJS_CLIENT			=	$(SRC_FILES_CLIENT:.c=.o)
OBJS_SERVER			=	$(SRC_FILES_SERVER:.c=.o)
BUILDS_CLIENT		=	$(addprefix $(BUILD_DIR)/, $(OBJS_CLIENT))
BUILDS_SERVER		=	$(addprefix $(BUILD_DIR)/, $(OBJS_SERVER))

#≻───░⋆ ✪ LIBFT EXTRA ✪ ⋆░───────────────────────────────────────────────────≺#
LIBFT_REPO			=	https://github.com/brmoretti/42_libft_extra.git
LIBFT_LIB_NAME		=	libft.a
LIBFT_DIR			=	libft
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/include
LIBFT_LIB			=	$(LIBFT_DIR)/$(LIBFT_LIB_NAME)
LIBFT_LIBS			=	-lft
LIBFT_CC			=	-I./$(LIBFT_INCLUDE_DIR)	\
						-L./$(LIBFT_DIR)			\
						$(LIBFT_LIBS)

#≻───░⋆ ✪ COLORS ✪ ⋆░────────────────────────────────────────────────────────≺#
BLUE				=	\033[0;34m
MAGENTA				=	\033[0;35m
GREEN				=	\033[0;32m
DEFAULT 			=	\033[0:0m

#≻───░⋆ ✪ RULES ✪ ⋆░─────────────────────────────────────────────────────────≺#
.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT_LIB) $(BUILD_DIR) $(BUILDS_CLIENT) $(INCLUDES)
	@ $(CC) -o $@			\
	  $(BUILDS_CLIENT)		\
	  -I./$(INCLUDE_DIR)	\
	  $(LIBFT_CC)			\
	  $(CC_FLAGS)
	  @ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(SERVER): $(LIBFT_LIB) $(BUILD_DIR) $(BUILDS_SERVER) $(INCLUDES)
	@ $(CC) -o $@			\
	  $(BUILDS_SERVER)		\
	  -I./$(INCLUDE_DIR)	\
	  $(LIBFT_CC)			\
	  $(CC_FLAGS)
	  @ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR_CLIENT)/%.c $(INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<				\
	  -I./$(INCLUDE_DIR)		\
	  -I./$(LIBFT_INCLUDE_DIR)	\
	  -o $@						\
	  $(CC_FLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR_SERVER)/%.c $(INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<				\
	  -I./$(INCLUDE_DIR)		\
	  -I./$(LIBFT_INCLUDE_DIR)	\
	  -o $@						\
	  $(CC_FLAGS)

clean: clean_libft
	@ rm -rf $(BUILD_DIR)

fclean: fclean_libft clean
	@ rm -rf $(NAME)

re: fclean all

$(LIBFT_LIB): $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR)

$(LIBFT_DIR):
	@ git clone $(LIBFT_REPO) $(LIBFT_DIR)

clean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) clean

fclean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) fclean

clear_libft:
	@ rm -rf $(LIBFT_DIR)

clear: fclean clear_libft
	@ rm -rf client
	@ rm -rf server
