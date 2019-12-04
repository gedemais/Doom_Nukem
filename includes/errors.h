/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:34 by gedemais          #+#    #+#             */
/*   Updated: 2019/12/04 03:20:19 by demaisonc        ###   ########.fr       */
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

# define BMP_HEADER "Wrong path or file format for "

#endif
