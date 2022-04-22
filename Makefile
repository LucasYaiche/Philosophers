#=======================================#
#[PHILO] Fonctions partie principale#
#=======================================#

PHILO_SRC = philo.c

COMMON_SRC = ft_putstr_error.c ft_strlen.c arg_error.c ft_isdigit.c check_argv.c \
			ft_atoi.c nbr_len.c double_check.c launch.c routine.c check_dead.c \
			ft_time.c ft_usleep.c
				
COMMON_OBJ = ${addprefix ${OBJDIR}, ${COMMON_SRC:%.c=%.o}}

PHILO_OBJ = ${addprefix ${OBJDIR}, ${PHILO_SRC:%.c=%.o}} ${COMMON_OBJ}

#====#
#Tags#
#====#

OBJDIR = ./objs/
SRCDIR = ./src/
COMMONDIR = ./common/
INCLUDES = ./includes/
NAME = philo
CFLAGS = -Wall -Wextra -Werror ${SANIFLAG}
SANIFLAG = -fsanitize=address -g

#=========#
#Commandes#
#=========#					

${OBJDIR}%.o : ${SRCDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}
${OBJDIR}%.o : ${CHECKDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${OBJDIR}%.o : ${COMMONDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}: 						${OBJDIR} ${PHILO_OBJ}
								@gcc ${CFLAGS} ${PHILO_OBJ} -o ${NAME}
								@printf "\e[32;3m$@ successfully built\e[0m\n"

${OBJDIR}:						
								@mkdir -p ${OBJDIR}

all:							${NAME}
								

clean:
								@rm -rf ${OBJDIR}
								@printf "\e[31;3mClean files\e[0m\n"

fclean:							clean
								@rm -f ${NAME}
								@printf "\e[31;3mClean exec\e[0m\n"

re:								fclean all

.PHONY:							all clean fclean re