/*
 * Info handle
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

#if !defined( _INFO_HANDLE_H )
#define _INFO_HANDLE_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include "ewftools_libcerror.h"
#include "ewftools_libewf.h"

#if defined( __cplusplus )
extern "C" {
#endif

enum INFO_HANDLE_OUTPUT_FORMAT_TYPES
{
	INFO_HANDLE_OUTPUT_FORMAT_TEXT		= (uint8_t) 't',
	INFO_HANDLE_OUTPUT_FORMAT_DFXML		= (uint8_t) 'x'
};

typedef struct info_handle info_handle_t;

struct info_handle
{
	/* The output format
	 */
	uint8_t output_format;

	/* The date format
	 */
	uint8_t date_format;

	/* The header codepage
	 */
	int header_codepage;

	/* The libewf input handle
	 */
	libewf_handle_t *input_handle;

	/* The bodyfile output stream
	 */
	FILE *bodyfile_stream;

	/* The notification output stream
	 */
	FILE *notify_stream;
};

int info_handle_initialize(
     info_handle_t **info_handle,
     libcerror_error_t **error );

int info_handle_free(
     info_handle_t **info_handle,
     libcerror_error_t **error );

int info_handle_signal_abort(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_set_bodyfile(
     info_handle_t *info_handle,
     const system_character_t *filename,
     libcerror_error_t **error );

int info_handle_set_maximum_number_of_open_handles(
     info_handle_t *info_handle,
     int maximum_number_of_open_handles,
     libcerror_error_t **error );

int info_handle_open_input(
     info_handle_t *info_handle,
     system_character_t * const * filenames,
     int number_of_filenames,
     libcerror_error_t **error );

int info_handle_close(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_set_output_format(
     info_handle_t *info_handle,
     const system_character_t *string,
     libcerror_error_t **error );

int info_handle_set_date_format(
     info_handle_t *info_handle,
     const system_character_t *string,
     libcerror_error_t **error );

int info_handle_set_header_codepage(
     info_handle_t *info_handle,
     const system_character_t *string,
     libcerror_error_t **error );

int info_handle_posix_time_value_fprint(
     info_handle_t *info_handle,
     const char *value_name,
     int64_t value_64bit,
     libcerror_error_t **error );

int info_handle_section_header_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     const char *description,
     libcerror_error_t **error );

int info_handle_section_footer_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     libcerror_error_t **error );

int info_handle_section_value_string_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     size_t identifier_length,
     const char *description,
     size_t description_length,
     const system_character_t *value_string,
     libcerror_error_t **error );

int info_handle_section_value_32bit_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     const char *description,
     size_t description_length,
     uint32_t value_32bit,
     libcerror_error_t **error );

int info_handle_section_value_64bit_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     const char *description,
     size_t description_length,
     uint64_t value_64bit,
     libcerror_error_t **error );

int info_handle_section_value_size_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     const char *description,
     size_t description_length,
     size64_t value_size,
     libcerror_error_t **error );

int info_handle_section_value_boolean_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     const char *description,
     size_t description_length,
     int value_boolean,
     libcerror_error_t **error );

int info_handle_sub_section_header_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     const char *description,
     libcerror_error_t **error );

int info_handle_sub_section_footer_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     libcerror_error_t **error );

int info_handle_header_value_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     size_t identifier_length,
     const char *description,
     size_t description_length,
     libcerror_error_t **error );

int info_handle_header_values_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_header_value_password_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_header_value_compression_level_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_header_value_extents_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_media_information_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_hash_value_fprint(
     info_handle_t *info_handle,
     const char *identifier,
     size_t identifier_length,
     libcerror_error_t **error );

int info_handle_hash_values_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_acquiry_errors_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_sessions_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_tracks_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_access_control_entry_value_fprint(
     info_handle_t *info_handle,
     libewf_access_control_entry_t *access_control_entry,
     libcerror_error_t **error );

int info_handle_attribute_value_fprint(
     info_handle_t *info_handle,
     libewf_attribute_t *attribute,
     libcerror_error_t **error );

int info_handle_source_value_fprint(
     info_handle_t *info_handle,
     libewf_source_t *source,
     libcerror_error_t **error );

int info_handle_file_entry_value_fprint(
     info_handle_t *info_handle,
     libewf_file_entry_t *file_entry,
     const system_character_t *path,
     libcerror_error_t **error );

int info_handle_logical_files_hierarchy_fprint_file_entry(
     info_handle_t *info_handle,
     libewf_file_entry_t *file_entry,
     const system_character_t *path,
     uint8_t is_root,
     libcerror_error_t **error );

int info_handle_file_entry_fprint_by_path(
     info_handle_t *info_handle,
     const system_character_t *path,
     libcerror_error_t **error );

int info_handle_logical_files_hierarchy_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_file_entry_fprint(
     info_handle_t *info_handle,
     libewf_file_entry_t *file_entry,
     const system_character_t *path,
     libcerror_error_t **error );

int info_handle_image_fprint(
     info_handle_t *info_handle,
     char info_option,
     libcerror_error_t **error );

int info_handle_dfxml_header_fprint(
     FILE *stream,
     libcerror_error_t **error );

int info_handle_dfxml_footer_fprint(
     FILE *stream,
     libcerror_error_t **error );

int info_handle_dfxml_build_environment_fprint(
     FILE *stream,
     libcerror_error_t **error );

int info_handle_dfxml_execution_environment_fprint(
     FILE *stream,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _INFO_HANDLE_H ) */

