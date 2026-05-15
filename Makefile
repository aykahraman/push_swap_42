# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 10:00:00 by ahmet             #+#    #+#              #
#    Updated: 2026/05/14 00:53:03 by akahrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I .

OBJDIR		= objs
SRCS		= main.c \
			  parse_args.c \
			  parse_utils.c \
			  validate.c \
			  stack_init.c \
			  stack_utils.c \
			  index.c \
			  exec_op.c \
			  ops_swap.c \
			  ops_push.c \
			  ops_rotate.c \
			  ops_rev_rotate.c \
			  sort_tiny.c \
			  sort_small.c \
			  sort_simple.c \
			  sort_medium.c \
			  sort_complex.c \
			  sort_adaptive.c \
			  adaptive_lis.c \
			  adaptive_cost.c \
			  adaptive_exec.c \
			  disorder.c \
			  bench.c \
			  free.c \
			  error.c

OBJS		= $(SRCS:%.c=$(OBJDIR)/%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
			rm -rf $(OBJDIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

reclean:
			$(MAKE) fclean
			$(MAKE) all
			$(MAKE) clean

.PHONY:		all clean fclean re reclean
