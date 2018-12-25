TARGET  = lzma.library
VERSION = 53

CC     = ppc-amigaos-gcc
STRIP  = ppc-amigaos-strip
AR     = ppc-amigaos-ar
RANLIB = ppc-amigaos-ranlib

V ?= /V

XZDIR = xz-5.2.4

CFLAGS  = -O3 -fomit-frame-pointer -funroll-loops -g \
          -I$(V)/include -I. -I./include -I$(XZDIR)/liblzma/api \
          -Wall -Wwrite-strings -Werror
LDFLAGS = -static
LIBS    = 

STRIPFLAGS = -R.comment --strip-unneeded-rel-relocs

main_SRCS = $(wildcard main/*.c)
main_OBJS = $(main_SRCS:.c=.o)

SRCS = init.c malloc.c $(main_SRCS)
OBJS = $(SRCS:.c=.o)

LZMA_CFLAGS = -std=gnu99 -DHAVE_CONFIG_H -I$(XZDIR) \
	-I$(XZDIR)/common -I$(XZDIR)/liblzma/check \
	-I$(XZDIR)/liblzma/common -I$(XZDIR)/liblzma/delta \
	-I$(XZDIR)/liblzma/lz -I$(XZDIR)/liblzma/lzma \
	-I$(XZDIR)/liblzma/rangecoder -I$(XZDIR)/liblzma/simple

LZMA_OBJS = \
	$(XZDIR)/common/tuklib_exit.o \
	$(XZDIR)/common/tuklib_physmem.o \
	$(XZDIR)/common/tuklib_progname.o \
	$(XZDIR)/liblzma/check/check.o \
	$(XZDIR)/liblzma/check/crc32_fast.o \
	$(XZDIR)/liblzma/check/crc32_table.o \
	$(XZDIR)/liblzma/check/crc64_fast.o \
	$(XZDIR)/liblzma/check/crc64_table.o \
	$(XZDIR)/liblzma/check/sha256.o \
	$(XZDIR)/liblzma/common/alone_decoder.o \
	$(XZDIR)/liblzma/common/alone_encoder.o \
	$(XZDIR)/liblzma/common/auto_decoder.o \
	$(XZDIR)/liblzma/common/block_buffer_decoder.o \
	$(XZDIR)/liblzma/common/block_buffer_encoder.o \
	$(XZDIR)/liblzma/common/block_decoder.o \
	$(XZDIR)/liblzma/common/block_encoder.o \
	$(XZDIR)/liblzma/common/block_header_decoder.o \
	$(XZDIR)/liblzma/common/block_header_encoder.o \
	$(XZDIR)/liblzma/common/block_util.o \
	$(XZDIR)/liblzma/common/common.o \
	$(XZDIR)/liblzma/common/easy_buffer_encoder.o \
	$(XZDIR)/liblzma/common/easy_decoder_memusage.o \
	$(XZDIR)/liblzma/common/easy_encoder.o \
	$(XZDIR)/liblzma/common/easy_encoder_memusage.o \
	$(XZDIR)/liblzma/common/easy_preset.o \
	$(XZDIR)/liblzma/common/filter_buffer_decoder.o \
	$(XZDIR)/liblzma/common/filter_buffer_encoder.o \
	$(XZDIR)/liblzma/common/filter_common.o \
	$(XZDIR)/liblzma/common/filter_decoder.o \
	$(XZDIR)/liblzma/common/filter_encoder.o \
	$(XZDIR)/liblzma/common/filter_flags_decoder.o \
	$(XZDIR)/liblzma/common/filter_flags_encoder.o \
	$(XZDIR)/liblzma/common/hardware_physmem.o \
	$(XZDIR)/liblzma/common/index.o \
	$(XZDIR)/liblzma/common/index_decoder.o \
	$(XZDIR)/liblzma/common/index_encoder.o \
	$(XZDIR)/liblzma/common/index_hash.o \
	$(XZDIR)/liblzma/common/stream_buffer_decoder.o \
	$(XZDIR)/liblzma/common/stream_buffer_encoder.o \
	$(XZDIR)/liblzma/common/stream_decoder.o \
	$(XZDIR)/liblzma/common/stream_encoder.o \
	$(XZDIR)/liblzma/common/stream_flags_common.o \
	$(XZDIR)/liblzma/common/stream_flags_decoder.o \
	$(XZDIR)/liblzma/common/stream_flags_encoder.o \
	$(XZDIR)/liblzma/common/vli_decoder.o \
	$(XZDIR)/liblzma/common/vli_encoder.o \
	$(XZDIR)/liblzma/common/vli_size.o \
	$(XZDIR)/liblzma/delta/delta_common.o \
	$(XZDIR)/liblzma/delta/delta_decoder.o \
	$(XZDIR)/liblzma/delta/delta_encoder.o \
	$(XZDIR)/liblzma/lz/lz_decoder.o \
	$(XZDIR)/liblzma/lz/lz_encoder.o \
	$(XZDIR)/liblzma/lz/lz_encoder_mf.o \
	$(XZDIR)/liblzma/lzma/fastpos_table.o \
	$(XZDIR)/liblzma/lzma/lzma_decoder.o \
	$(XZDIR)/liblzma/lzma/lzma_encoder.o \
	$(XZDIR)/liblzma/lzma/lzma_encoder_optimum_fast.o \
	$(XZDIR)/liblzma/lzma/lzma_encoder_optimum_normal.o \
	$(XZDIR)/liblzma/lzma/lzma_encoder_presets.o \
	$(XZDIR)/liblzma/lzma/lzma2_decoder.o \
	$(XZDIR)/liblzma/lzma/lzma2_encoder.o \
	$(XZDIR)/liblzma/rangecoder/price_table.o \
	$(XZDIR)/liblzma/simple/arm.o \
	$(XZDIR)/liblzma/simple/armthumb.o \
	$(XZDIR)/liblzma/simple/ia64.o \
	$(XZDIR)/liblzma/simple/powerpc.o \
	$(XZDIR)/liblzma/simple/simple_coder.o \
	$(XZDIR)/liblzma/simple/simple_decoder.o \
	$(XZDIR)/liblzma/simple/simple_encoder.o \
	$(XZDIR)/liblzma/simple/sparc.o \
	$(XZDIR)/liblzma/simple/x86.o

STATIC_SRCS = static/autoinit_lzma_base.c static/autoinit_lzma_main.c static/stubs.c
STATIC_OBJS = $(STATIC_SRCS:.c=.o)

.PHONY: all
all: $(TARGET) liblzma.a xzdec lzmadec

init.o: $(TARGET)_rev.h lzma_vectors.c
$(main_OBJS): lzma_vectors.h

$(LZMA_OBJS): CFLAGS += $(LZMA_CFLAGS)

$(XZDIR)/liblzma-static.a: $(LZMA_OBJS)
	$(AR) -crv $@ $^
	$(RANLIB) $@

$(TARGET): $(OBJS) $(XZDIR)/liblzma-static.a
	$(CC) $(LDFLAGS) -nostartfiles -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

liblzma.a: $(STATIC_OBJS)
	$(AR) -crv $@ $^
	$(RANLIB) $@

xzdec.o: $(XZDIR)/xzdec/xzdec.c
	$(CC) $(CFLAGS) $(LZMA_CFLAGS) -c -o $@ $<

xzdec: xzdec.o liblzma.a $(XZDIR)/liblzma-static.a
	$(CC) $(LDFLAGS) -o $@.debug $^ -lunix
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

lzmadec.o: $(XZDIR)/xzdec/xzdec.c
	$(CC) $(CFLAGS) $(LZMA_CFLAGS) -DLZMADEC -c -o $@ $<

lzmadec: lzmadec.o liblzma.a $(XZDIR)/liblzma-static.a
	$(CC) $(LDFLAGS) -o $@.debug $^ -lunix
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

.PHONY: clean
clean:
	rm -f $(TARGET) $(TARGET).debug *.o main/*.o
	rm -f $(XZDIR)/liblzma-static.a $(XZDIR)/common/*.o $(XZDIR)/liblzma/check/*.o
	rm -f $(XZDIR)/liblzma/common/*.o $(XZDIR)/liblzma/delta/*.o $(XZDIR)/liblzma/lz/*.o
	rm -f $(XZDIR)/liblzma/lzma/*.o $(XZDIR)/liblzma/rangecoder/*.o $(XZDIR)/liblzma/simple/*.o
	rm -f xzdec xzdec.debug lzmadec lzmadec.debug

.PHONY: revision
revision:
	bumprev $(VERSION) $(TARGET)

.PHONY: install
install:
	copy clone $(TARGET) SYS:Libs/

