/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:49:53 by briferre          #+#    #+#             */
/*   Updated: 2023/05/08 12:33:50 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include "minishell.h"

typedef struct s_ml
{
	t_string			user;
	t_string			host;
	t_string			pwd;
	t_string			prompt;

	t_string			cmd;
	t_string			*pp_cmd;
	t_string			*split_cmd;

	t_varlist			*local_vars;
	t_varlist			*env_vars;
	t_varlist			*quotes_vars;

	t_varlist			*pid_list;

	int					running;
	int					exit_status;

	int					pp_quant;
	int					**pp_lpipes;
	int					fd_pipe[2];
	int					i;
	int					redirect_out;
	int					redirect_in;
	int					stdin;
	int					stdout;
	t_string			here_doc;
}t_ml;

void		tml_init(int argc, t_string *argv, t_string *env, t_ml *tml);

int			tml_exec_father(t_ml *tml);

/// @brief Run program in terminal
/// @param tml Struct t_ml
int			tml_exec_child(t_ml *tml, int *fd);

/// @brief Get user, host and path from user
/// @param tml Struct t_ml
void		tml_get_uhp(t_ml *tml);

/// @brief Create line who is show in terminal
/// @param tml Struct t_ml
void		tml_create_prompt(t_ml *tml);

/// @brief Free user, host and path from t_ml
/// @param tml	Struct t_ml
void		tml_free_uhp(t_ml *tml);

/// @brief Free a list from t_string
/// @param string_list List from t_string
void		tml_free_sprt_cmd(t_string *string_list);

t_string	vr_descompress(t_ml *tml, t_string string);

t_string	get_var(t_ml *tml, t_string string, int *i);

t_string	*tml_construct_env(t_ml *tml);

int			tml_find_exec(t_ml *tml);

int			tml_check_access(t_ml *tml);

void		check_empty_line(t_ml *tml);

int			vr_new_assignment(t_ml *tml);

void		tml_exit_status(t_varlist **start, int value, int init);

int			tml_set_exit_status(t_string msg, int exit);

int			tml_set_pexit_status(t_string message, int type);

#endif