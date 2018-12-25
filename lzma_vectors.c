/*
 * Copyright (C) 2014-2018 Fredrik Wikstrom <fredrik@a500.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS `AS IS'
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "lzma_vectors.h"

STATIC CONST APTR main_v1_vectors[] =
{
	_main_Obtain,
	_main_Release,
	NULL,
	NULL,
	lzma_code,
	lzma_end,
	lzma_memusage,
	lzma_memlimit_get,
	lzma_memlimit_set,
	lzma_block_header_size,
	lzma_block_header_encode,
	lzma_block_header_decode,
	lzma_block_compressed_size,
	lzma_block_unpadded_size,
	lzma_block_total_size,
	lzma_block_encoder,
	lzma_block_decoder,
	lzma_block_buffer_bound,
	lzma_block_buffer_encode,
	lzma_block_buffer_decode,
	lzma_check_is_supported,
	lzma_check_size,
	lzma_crc32,
	lzma_crc64,
	lzma_get_check,
	lzma_easy_encoder_memusage,
	lzma_easy_decoder_memusage,
	lzma_easy_encoder,
	lzma_easy_buffer_encode,
	lzma_stream_encoder,
	lzma_alone_encoder,
	lzma_stream_buffer_bound,
	lzma_stream_buffer_encode,
	lzma_stream_decoder,
	lzma_auto_decoder,
	lzma_alone_decoder,
	lzma_stream_buffer_decode,
	lzma_filter_encoder_is_supported,
	lzma_filter_decoder_is_supported,
	lzma_filters_copy,
	lzma_raw_encoder_memusage,
	lzma_raw_decoder_memusage,
	lzma_raw_encoder,
	lzma_raw_decoder,
	lzma_filters_update,
	lzma_raw_buffer_encode,
	lzma_raw_buffer_decode,
	lzma_properties_size,
	lzma_properties_encode,
	lzma_properties_decode,
	lzma_filter_flags_size,
	lzma_filter_flags_encode,
	lzma_filter_flags_decode,
	lzma_physmem,
	lzma_index_memusage,
	lzma_index_memused,
	lzma_index_init,
	lzma_index_end,
	lzma_index_append,
	lzma_index_stream_flags,
	lzma_index_checks,
	lzma_index_stream_padding,
	lzma_index_stream_count,
	lzma_index_block_count,
	lzma_index_size,
	lzma_index_stream_size,
	lzma_index_total_size,
	lzma_index_file_size,
	lzma_index_uncompressed_size,
	lzma_index_iter_init,
	lzma_index_iter_rewind,
	lzma_index_iter_next,
	lzma_index_iter_locate,
	lzma_index_cat,
	lzma_index_dup,
	lzma_index_encoder,
	lzma_index_decoder,
	lzma_index_buffer_encode,
	lzma_index_buffer_decode,
	lzma_index_hash_init,
	lzma_index_hash_end,
	lzma_index_hash_append,
	lzma_index_hash_decode,
	lzma_index_hash_size,
	lzma_mf_is_supported,
	lzma_mode_is_supported,
	lzma_lzma_preset,
	lzma_stream_header_encode,
	lzma_stream_footer_encode,
	lzma_stream_header_decode,
	lzma_stream_footer_decode,
	lzma_stream_flags_compare,
	lzma_version_number,
	lzma_version_string,
	lzma_vli_encode,
	lzma_vli_decode,
	lzma_vli_size,
	lzma_get_progress,
	(APTR)-1
};

