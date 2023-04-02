# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 14:02:20 by jgo               #+#    #+#              #
#    Updated: 2023/04/02 19:32:42 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL = all

PROJECT_NAME = philo
BONUS_NAME = philo_bonus

MANDATORY_DIR = $(PROJECT_NAME)
BONUS_DIR = $(BONUS_NAME)

MANDATORY_LIB_DIR = src/$(MANDATORY_DIR)/lib
BONUS_LIB_DIR = src/$(BONUS_DIR)/lib

ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -MMD -MP

CPPFLAGS = $(if $(findstring bonus, $(MAKECMDGOALS)), -I$(TOPDIR)/src/$(BONUS_DIR)/includes, -I$(TOPDIR)/src/$(MANDATORY_DIR)/includes)
LDFLAGS = $(if $(findstring bonus, $(MAKECMDGOALS)), -lpthread, -lpthread) 

# verbose
Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

# debug
ifdef DEBUG
	CFLAGS = -g3 -MMD -MP
	LDFLAGS += -g3
endif

# just compile
ifdef JUST
	CFLAGS = -MMD -MP
endif

# address
ifdef ADDR
	CFLAGS += -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

ifdef RACE
	CFLAGS = -fsanitize=thread -MMD -MP -g3
	LDFLAGS += -fsanitize=thread -g3
endif

link_files:: unlink_files
	$(Q)$(call color_printf,$(GRAY),includes,📁 make includes folder)
	mkdir -p $(dst_dir);
	$(Q)$(foreach file,$(files), $(call color_printf,$(CYAN),$(file),🔗 linking file\n) ln -sf $(src_dir)/$(file) $(dst_dir);)
	$(Q)$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir);)

unlink_files::
	$(Q)$(foreach file,$(files), $(call color_printf,$(GRAY),$(file),🚫 unlinking file\n) $(RM) $(dst_dir)/$(file);)
	$(Q)$(foreach file,$(files), $(RM) $(dst_dir)/$(file);)
