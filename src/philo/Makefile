# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/06/06 15:34:05 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../)
endif

include $(TOPDIR)/make_config/src/Rules.mk
include $(TOPDIR)/make_config/com/ColorRules.mk

NAME = $(PROJECT_NAME)

DIRS = utils error set_meta life clerk
LIBS = $(addsuffix .a, $(addprefix lib/, $(DIRS)))

HEADS =	def.h \
 		const.h \
		enum.h \
		error.h \
		life.h \
		mutex.h \
		philo.h \
		queue.h \
		set_meta.h \
		state_control.h \
		utils.h

SRCS = philo.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

include $(TOPDIR)/make_config/src/Recipes.mk
