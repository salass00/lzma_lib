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

#include <interfaces/lzma.h>

asm("\t.section\t\".text\"\n"
	"\t.align\t2\n"
	"\t.globl\t__CallLZMA\n"
	"\t.type\t__CallLZMA, @function\n"
	"__CallLZMA:\n"
	"\tlis\t%r11,ILZMA@ha\n"
	"\tlwz\t%r0,ILZMA@l(%r11)\n"
	"\tlwzx\t%r11,%r12,%r0\n"
	"\tmtctr\t%r11\n"
	"\tbctr\n"
	"\t.size\t__CallLZMA, .-__CallLZMA");

#define LZMACall(function, offset) \
asm("\t.section\t\".text\"\n" \
	"\t.align\t2\n" \
	"\t.globl\t" #function "\n" \
	"\t.type\t" #function ", @function\n" \
	#function ":\n" \
	"\tli\t%r12," #offset "\n" \
	"\tb\t__CallLZMA\n" \
	"\t.size\t" #function ", .-" #function);

LZMACall(lzma_code, 76)
LZMACall(lzma_end, 80)
LZMACall(lzma_memusage, 84)
LZMACall(lzma_memlimit_get, 88)
LZMACall(lzma_memlimit_set, 92)
LZMACall(lzma_block_header_size, 96)
LZMACall(lzma_block_header_encode, 100)
LZMACall(lzma_block_header_decode, 104)
LZMACall(lzma_block_compressed_size, 108)
LZMACall(lzma_block_unpadded_size, 112)
LZMACall(lzma_block_total_size, 116)
LZMACall(lzma_block_encoder, 120)
LZMACall(lzma_block_decoder, 124)
LZMACall(lzma_block_buffer_bound, 128)
LZMACall(lzma_block_buffer_encode, 132)
LZMACall(lzma_block_buffer_decode, 136)
LZMACall(lzma_check_is_supported, 140)
LZMACall(lzma_check_size, 144)
LZMACall(lzma_crc32, 148)
LZMACall(lzma_crc64, 152)
LZMACall(lzma_get_check, 156)
LZMACall(lzma_easy_encoder_memusage, 160)
LZMACall(lzma_easy_decoder_memusage, 164)
LZMACall(lzma_easy_encoder, 168)
LZMACall(lzma_easy_buffer_encode, 172)
LZMACall(lzma_stream_encoder, 176)
LZMACall(lzma_alone_encoder, 180)
LZMACall(lzma_stream_buffer_bound, 184)
LZMACall(lzma_stream_buffer_encode, 188)
LZMACall(lzma_stream_decoder, 192)
LZMACall(lzma_auto_decoder, 196)
LZMACall(lzma_alone_decoder, 200)
LZMACall(lzma_stream_buffer_decode, 204)
LZMACall(lzma_filter_encoder_is_supported, 208)
LZMACall(lzma_filter_decoder_is_supported, 212)
LZMACall(lzma_filters_copy, 216)
LZMACall(lzma_raw_encoder_memusage, 220)
LZMACall(lzma_raw_decoder_memusage, 224)
LZMACall(lzma_raw_encoder, 228)
LZMACall(lzma_raw_decoder, 232)
LZMACall(lzma_filters_update, 236)
LZMACall(lzma_raw_buffer_encode, 240)
LZMACall(lzma_raw_buffer_decode, 244)
LZMACall(lzma_properties_size, 248)
LZMACall(lzma_properties_encode, 252)
LZMACall(lzma_properties_decode, 256)
LZMACall(lzma_filter_flags_size, 260)
LZMACall(lzma_filter_flags_encode, 264)
LZMACall(lzma_filter_flags_decode, 268)
LZMACall(lzma_physmem, 272)
LZMACall(lzma_index_memusage, 276)
LZMACall(lzma_index_memused, 280)
LZMACall(lzma_index_init, 284)
LZMACall(lzma_index_end, 288)
LZMACall(lzma_index_append, 292)
LZMACall(lzma_index_stream_flags, 296)
LZMACall(lzma_index_checks, 300)
LZMACall(lzma_index_stream_padding, 304)
LZMACall(lzma_index_stream_count, 308)
LZMACall(lzma_index_block_count, 312)
LZMACall(lzma_index_size, 316)
LZMACall(lzma_index_stream_size, 320)
LZMACall(lzma_index_total_size, 324)
LZMACall(lzma_index_file_size, 328)
LZMACall(lzma_index_uncompressed_size, 332)
LZMACall(lzma_index_iter_init, 336)
LZMACall(lzma_index_iter_rewind, 340)
LZMACall(lzma_index_iter_next, 344)
LZMACall(lzma_index_iter_locate, 348)
LZMACall(lzma_index_cat, 352)
LZMACall(lzma_index_dup, 356)
LZMACall(lzma_index_encoder, 360)
LZMACall(lzma_index_decoder, 364)
LZMACall(lzma_index_buffer_encode, 368)
LZMACall(lzma_index_buffer_decode, 372)
LZMACall(lzma_index_hash_init, 376)
LZMACall(lzma_index_hash_end, 380)
LZMACall(lzma_index_hash_append, 384)
LZMACall(lzma_index_hash_decode, 388)
LZMACall(lzma_index_hash_size, 392)
LZMACall(lzma_mf_is_supported, 396)
LZMACall(lzma_mode_is_supported, 400)
LZMACall(lzma_lzma_preset, 404)
LZMACall(lzma_stream_header_encode, 408)
LZMACall(lzma_stream_footer_encode, 412)
LZMACall(lzma_stream_header_decode, 416)
LZMACall(lzma_stream_footer_decode, 420)
LZMACall(lzma_stream_flags_compare, 424)
LZMACall(lzma_version_number, 428)
LZMACall(lzma_version_string, 432)
LZMACall(lzma_vli_encode, 436)
LZMACall(lzma_vli_decode, 440)
LZMACall(lzma_vli_size, 444)
LZMACall(lzma_get_progress, 448)

