# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 20:10:46 by jgo               #+#    #+#              #
#    Updated: 2023/03/19 10:13:20 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./config/Rules.mk
include ./config/color_rules.mk

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C src $@

$(NAME):
	$(MAKE) TOPDIR=`pwd` -C src $@

.PHONY: all clean fclean re bonus