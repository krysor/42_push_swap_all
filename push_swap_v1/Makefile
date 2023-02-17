SRCS	= main.c ft_parse.c ft_atopi.c ft_issorted.c ft_iscis.c ft_cistosorted.c \
			ft_solve.c ft_saveswap.c ft_savepush.c ft_saverotate.c ft_saverevrotate.c \
			 ft_lstdup.c ft_get_nb_ra.c ft_get_nb_rra.c ft_get_nb_rb.c ft_get_nb_rrb.c \
				ft_putbest.c ft_getallbestmoves.c ft_getthebestmoves.c ft_makethebestmoves.c \
					ft_max.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			${MAKE} -C libft
			${MAKE} bonus -C libft
			#${MAKE} -C lists
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a #lists/lists.a

all:		${NAME}

bonus:		all

clean:
			${RM} ${OBJS}
			$(MAKE) clean -C libft

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all bonus clean fclean re