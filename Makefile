NAME			=	prototypes

DIR_SRCS		=	srcs
DIR_OBJS		=	objs

SRCS_NAMES		=	get_next_line.c \
					put_file_to.c \
					main.c

SRCS			=	$(addprefix $(DIR_SRCS)/, $(SRCS_NAMES))
OBJS			=	$(addprefix $(DIR_OBJS)/, $(OBJS_NAMES))

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}
DEPS			=	${SRCS_NAMES:.c=.d}

CC			=		cc
CFLAGS		=		-Wall -Wextra -Werror
CDFLAGS		=		-MMD -MP
INCLUDE		=		-Iinclude
RM			=		rm -rf

all:		${NAME}

${NAME}:	${DIR_OBJS} ${OBJS}
				${CC} ${CFLAGS} ${CDFLAGS} ${OBJS} -o ${NAME}

${OBJS} :	${DIR_OBJS}/%.o : ${DIR_SRCS}/%.c
				${CC} ${CFLAGS} ${CDFLAGS} ${INCLUDE} -c $< -o $@

${DIR_OBJS}:
				mkdir -p ${DIR_OBJS}

clean:
				${RM} ${DIR_OBJS}
				${RM} ${DEPS}

fclean:		clean
				${RM} ${addprefix ${NAME}, .txt}
				${RM} ${NAME}

re:			fclean all

d:			CFLAGS += -g3
d:			all
red:		fclean d

.PHONY:		all clean fclean re
