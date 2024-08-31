# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 12:36:20 by lhabacuc          #+#    #+#              #
#    Updated: 2024/06/12 12:36:27 by lhabacuc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            := fdf
BONUSNAME       := fdf_bonus
CC              := cc
RM              := rm -f
FLAGS           := -Wall -Wextra -Werror
DEBUG           := -g

HEADDIR         := ./includes/
HEADLIST        := fdf.h
HEADERS         := $(addprefix ${HEADDIR}, ${HEADLIST})

HEADDIRBONUS    := ./includes/includes_bonus/
HEADLISTBONUS   := fdf_bonus.h
HEADERSBONUS    := $(addprefix ${HEADDIRBONUS}, ${HEADLISTBONUS})

SRCSDIR         := ./src/
SRCSLIST        := main.c \
                    ft_ajust_map1.c \
                    ft_ajust_map2.c \
                    ft_define_color.c \
                    ft_draw_map1.c \
                    ft_draw_map2.c \
                    ft_draw_matriz1.c \
                    ft_draw_matriz2.c \
                    ft_project_iso.c
SRCS            := $(addprefix ${SRCSDIR}, ${SRCSLIST})

BONUSSRCSLIST   := ft_init_Bonus.c \
                    ft_define_cores_Bonus.c \
                    ft_draw_map1_Bonus.c \
                    ft_draw_map2_Bonus.c \
                    ft_draw_matriz1_Bonus.c \
                    ft_draw_matriz2_Bonus.c \
                    ft_key_hooks_Bonus.c \
                    ft_iso_rot_map_Bonus.c \
                    ft_banner_bonus.c
BONUSSRCS       := $(addprefix ${SRCSDIR}, ${BONUSSRCSLIST})

OBJSDIR         := ./obj/
OBJSDIRBONUS    := ./obj_bonus/
OBJSLIST        := ${SRCSLIST:.c=.o}
OBJS            := $(addprefix ${OBJSDIR}, ${OBJSLIST})
BONUSOBJSLIST   := ${BONUSSRCSLIST:.c=.o}
BONUSOBJS       := $(addprefix ${OBJSDIRBONUS}, ${BONUSOBJSLIST})

LIBFTDIR        := ./libft/
LIBFT           := ${LIBFTDIR}libft.a

MLXDIR          := ./minilibx-linux/
MLX             := ${MLXDIR}libmlx.a

LIBS            := -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx -lXext -lX11 -lm
INCS            := -I${HEADDIR} -I${LIBFTDIR} -I${MLXDIR}
INCSBONUS       := -I${HEADDIRBONUS} -I${LIBFTDIR} -I${MLXDIR}

CYAN            := \033[0;36m
RESET           := \033[0m

# Compilação do executável principal
${NAME}:        ${MLX} ${LIBFT} ${OBJSDIR} ${OBJS}
		@echo ""
		@echo "${CYAN}Compilando ${NAME} ordem dos três idiotas(Daniel, Mauro e Liedson) ...${RESET}"
		${CC} ${OBJS} -o ${NAME} ${LIBS} ${INCS}
		@echo ""
		@echo "${CYAN}${NAME} Criado com sucesso... Os três idiotas!${RESET}"

# Compilação do executável bônus
${BONUSNAME}:   ${MLX} ${LIBFT} ${OBJSDIRBONUS} ${BONUSOBJS}
		@echo ""
		@echo "${CYAN}Compilando ${BONUSNAME} ...${RESET}"
		${CC} ${BONUSOBJS} -o ${BONUSNAME} ${LIBS} ${INCSBONUS}
		@echo ""
		@echo "${CYAN}${BONUSNAME} Criado com sucesso...${RESET}"

${LIBFT}:
		make -C ${LIBFTDIR}

${MLX}:
		@echo ""
		@echo "${CYAN}Compilando... ${MLX} ...${RESET}"
		git submodule init
		git submodule update
		make -C ${MLXDIR}

${OBJSDIR}%.o: ${SRCSDIR}%.c ${HEADERS}
		${CC} ${INCS} -c $< -o $@

${OBJSDIRBONUS}%.o: ${SRCSDIR}%.c ${HEADERSBONUS}
		${CC} ${INCSBONUS} -c $< -o $@

${OBJSDIR}:
		mkdir -p ${OBJSDIR}

${OBJSDIRBONUS}:
		mkdir -p ${OBJSDIRBONUS}

.PHONY: all clean fclean re bonus test bonustest

all: ${NAME}

clean:
		@echo ""
		@echo "${CYAN}Deletando $(NAME) e $(BONUSNAME) Objects ...${RESET}"
		${RM} -r ${OBJSDIR}
		${RM} -r ${OBJSDIRBONUS}
		make -C ${LIBFTDIR} clean
		make -C ${MLXDIR} clean

fclean: clean
		@echo ""
		@echo "${CYAN}Deletando $(NAME) e $(BONUSNAME) Executáveis ...${RESET}"
		${RM} ${NAME}
		${RM} ${BONUSNAME}
		make -C ${LIBFTDIR} fclean

re: fclean all
bonus: ${BONUSNAME}

test: all
		./${NAME} test_maps/42.fdf

bonustest: bonus
		./${BONUSNAME} test_maps/42.fdf
