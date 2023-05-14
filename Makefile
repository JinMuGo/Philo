# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 20:10:46 by jgo               #+#    #+#              #
#    Updated: 2023/05/14 09:50:28 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./make_config/Rules.mk
include ./make_config/color_rules.mk

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C src $@

$(NAME):
	$(MAKE) TOPDIR=`pwd` -C src $@

norm:
	@norminette ./src/

leaks: all
	leaks ./$(NAME)

.PHONY: all clean fclean re bonus norm leaks