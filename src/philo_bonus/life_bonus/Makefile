# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 08:31:25 by jgo               #+#    #+#              #
#    Updated: 2023/04/02 19:59:03 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../../../)
endif

include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/Color_rules.mk

SRCS = 	watch_philo_lives_bonus.c \
		be_born_philo_bonus.c \
		begin_life_bonus.c \
		eat_bonus.c \
		fork_bonus.c \
		sleep_bonus.c \
		think_bonus.c

NAME = life_bonus.a

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus : 
	$(Q)$(call color_printf,$(CYAN),$(NAME),🎯 starting compile $(NAME))
	$(Q)$(MAKE) $(NAME)
	$(Q)$(call color_printf,$(GREEN),$(NAME),🔰 done!)

$(NAME): $(OBJS)
	$(Q)$(call color_printf,$(GREEN),$(NAME),📚 archive object)
	$(AR) $(ARFLAGS) $@ $^
	$(Q)$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR)/$(BONUS_LIB_DIR) link_files
	
clean:
	$(Q)$(MAKE) files="$(NAME)" src_dir=`pwd` dst_dir=$(TOPDIR)/$(BONUS_LIB_DIR) unlink_files
	$(Q)$(call color_printf,$(RED),$(NAME),🗑️  remove Objects && Dependency file)
	$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(Q)$(call color_printf,$(RED),$(NAME),🗑️  remove $(NAME))
		$(RM) $(NAME)
	
re : fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus