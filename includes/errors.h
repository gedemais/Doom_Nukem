/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */ /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:34 by gedemais          #+#    #+#             */
/*   Updated: 2020/03/09 17:03:01 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define MLX_INIT_FAIL "mlx_init() failed\n"
# define MLX_NW_FAIL "mlx_new_window() failed\n"
# define MLX_NI_FAIL "mlx_new_image() failed\n"
# define MLX_GDA_FAIL "mlx_get_data_addr() failed\n"

# define BMP_READER "bmp file reader failed\n"

# define OPEN_DEVICE "alcOpenDevice() failed\n"
# define CREATE_CONTEXT "alcCreateContext() failed\n"
# define CONTEXT_CURRENT "alcMakeContextCurrent() failed\n"
# define SAMPLE_NF " : sample not found\n"

# define NEL_MAP "Wrong number of lines in config file of map "

# define OBJ_LINE_FORMAT "Unexpected line format in obj file : "

# define BMP_HEADER "Wrong path or file format for "

# define ICS_ERR "Illegal context switch. Abort"
# define ISCS_ERR "Illegal sub_context switch. Abort"

#endif
