/*
 * The libcdatetime header wrapper
 *
 * Copyright (C) 2006-2022, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _EWFTOOLS_LIBCDATETIME_H )
#define _EWFTOOLS_LIBCDATETIME_H

#include <common.h>

/* Define HAVE_LOCAL_LIBCDATETIME for local use of libcdatetime
 */
#if defined( HAVE_LOCAL_LIBCDATETIME )

#include <libcdatetime_definitions.h>
#include <libcdatetime_elements.h>
#include <libcdatetime_timestamp.h>
#include <libcdatetime_types.h>

#else

/* If libtool DLL support is enabled set LIBCDATETIME_DLL_IMPORT
 * before including libcdatetime.h
 */
#if defined( _WIN32 ) && defined( DLL_IMPORT ) && !defined( HAVE_STATIC_EXECUTABLES )
#define LIBCDATETIME_DLL_IMPORT
#endif

#include <libcdatetime.h>

#endif /* defined( HAVE_LOCAL_LIBCDATETIME ) */

#endif /* !defined( _EWFTOOLS_LIBCDATETIME_H ) */

