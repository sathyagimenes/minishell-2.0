/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:17:52 by briferre          #+#    #+#             */
/*   Updated: 2023/04/22 20:15:19 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_CMD_H
# define CHECK_CMD_H

# include "terminal.h"

// command check coming from user
int			ck_check(t_ml *tml);

// turns text enclosed in quotes into a variable
int			ck_quotes(t_ml *tml);

// check for redirect commands
int			ck_redictions(t_ml *tml);

int			ck_isllongint(t_string num);

int			ft_foreach(t_string string, int (f)(int));

#endif