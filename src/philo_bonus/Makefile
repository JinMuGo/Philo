# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/06/06 15:37:12 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif

include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/ColorRules.mk

NAME = $(BONUS_NAME)

DIRS =	utils_bonus \
		error_bonus \
		life_bonus \
		set_meta_bonus

LIBS = $(addsuffix .a, $(addprefix lib/, $(DIRS)))

HEADS =	def_bonus.h \
 		const_bonus.h \
		enum_bonus.h \
		error_bonus.h \
		philo_bonus.h \
		utils_bonus.h \
		state_control_bonus.h \
		set_meta_bonus.h

SRCS = philo_bonus.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/Recipes.mk
