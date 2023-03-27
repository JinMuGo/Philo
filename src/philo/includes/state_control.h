/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_control.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:58:06 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 18:38:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_CONTROL_H
# define STATE_CONTROL_H

t_proc_state	get_proc_state(void);
void			set_proc_state(t_proc_state arg);

#endif