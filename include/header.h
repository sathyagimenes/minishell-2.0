/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:27:47 by briferre          #+#    #+#             */
/*   Updated: 2023/05/07 18:45:31 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "minishell.h"
# include "variables.h"
# include "terminal.h"
# include "redirection.h"
# include "pipes.h"
# include "sigaction.h"
# include "check_cmd.h"
# include "libfte.h"
# include "builtins.h"

/// @brief Create a new process
/// @param pid Pid from fork function
/// @param tml Struct t_ml
void		fk_call_new_process(t_ml *tml);

/// @brief Wait for processes to be finished
/// @param tml Struct t_ml that holds a list of pids
void		fk_wait_execs(t_ml *tml);

/// @brief Get text from file text
/// @param path Path from file text
/// @return t_string with text
t_string	fl_get_text(t_string path);

/// @brief Prints customized message to stderr
/// @param arg Arg that generated the error
/// @param message Customized message
/// @param freeArg Inform if should free arg memory
void		ft_print_error(char *arg, char *message, t_bool freeArg);

/// @brief Search for $?
/// @param start t_varlist to get value of $?
/// @param string t_string
/// @param i int position in string
/// @return Value $? or ""
t_string	get_exit_status_var(t_varlist *start, t_string string, int *i);

/// @brief Fd newfd is redirected to refer to the same fd as oldfd.
/// Unused fds are closed.
/// @param oldfd fd where to redirect
/// @param newfd fd to be redirected
/// @return Returns 1 if error and 0 if success
int			fd_dup2(int oldfd, int newfd);

/// @brief Close a file descriptor
/// @param fd File to be closed
void		fd_close(int fd);

/// @brief Saves stdin and stdout file descriptor
/// @param tml Struct t_ml
void		ft_dup_stdin_out(t_ml *tml);

#endif