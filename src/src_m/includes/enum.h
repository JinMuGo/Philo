/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:12:47 by jgo               #+#    #+#             */
/*   Updated: 2023/03/16 16:23:24 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_state t_state;
typedef enum e_err   t_err;
typedef enum e_bool  t_bool;

enum e_state
{
	INIT,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
};

enum e_err
{
	ERR_ARGS,
	ERR_ALLOC
};

enum e_bool
{
	TRUE,
	FALSE
};

#endif
