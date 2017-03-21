/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:20:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/20 17:29:20 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*
** COLORS
*/

# define RESET "\033[0m"

/*
** Regular Colors
*/

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

/*
** Blold
*/

# define BBLACK "\033[1;30m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BPURPLE "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"

/*
** Underline
*/

# define UBLACK "\033[4;30m"
# define URED "\033[4;31m"
# define UGREEN "\033[4;32m"
# define UYELLOW "\033[4;33m"
# define UBLUE "\033[4;34m"
# define UPURPLE "\033[4;35m"
# define UCYAN "\033[4;36m"
# define UWHITE "\033[4;37m"

/*
** inversed/Reverse
*/

# define RBLACK "\033[7;30m"
# define RRED "\033[7;31m"
# define RGREEN "\033[7;32m"
# define RYELLOW "\033[7;33m"
# define RBLUE "\033[7;34m"
# define RPURPLE "\033[7;35m"
# define RCYAN "\033[7;36m"
# define RWHITE "\033[7;37m"

/*
** Light colors
*/

# define LBLACK "\033[0;90m"
# define LRED "\033[0;91m"
# define LGREEN "\033[0;92m"
# define LYELLOW "\033[0;93m"
# define LBLUE "\033[0;94m"
# define LPURPLE "\033[0;95m"
# define LCYAN "\033[0;96m"
# define LWHITE "\033[0;97m"

/*
** Couleurs de fond (Background)
*/

# define FBLACK "\033[40m"
# define FRED "\033[41m"
# define FGREEN "\033[42m"
# define FYELLOW "\033[43m"
# define FBLUE "\033[44m"
# define FPURPLE "\033[45m"
# define FCYAN "\033[46m"
# define FWHITE "\033[47m"

#endif
