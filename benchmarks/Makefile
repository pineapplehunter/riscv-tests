#=======================================================================
# UCB VLSI FLOW: Makefile for riscv-bmarks
#-----------------------------------------------------------------------
# Yunsup Lee (yunsup@cs.berkeley.edu)
#

XLEN ?= 64

default: all

src_dir = .

instname = riscv-bmarks
instbasedir = $(UCB_VLSI_HOME)/install

#--------------------------------------------------------------------
# Sources
#--------------------------------------------------------------------

bmarks = \
	median \
	# qsort \
	# rsort \
	# towers \
	# vvadd \
	# memcpy \
	# multiply \
	# mm \
	# dhrystone \
	# spmv \
	# mt-vvadd \
	# mt-matmul \
	# mt-memcpy \
	# pmp \
	# vec-memcpy \
	# vec-daxpy \
	# vec-sgemm \
	# vec-strcmp \

#--------------------------------------------------------------------
# Build rules
#--------------------------------------------------------------------

RISCV_PREFIX ?= riscv$(XLEN)-unknown-elf-
RISCV_GCC ?= $(RISCV_PREFIX)gcc
RISCV_GCC_OPTS ?= -DPREALLOCATE=1 -mcmodel=medany -static -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -fno-tree-loop-distribute-patterns -march=rv$(XLEN)iafdc_zicsr -mabi=lp64d
RISCV_LINK ?= $(RISCV_GCC) -T $(src_dir)/common/test.ld $(incs)
RISCV_LINK_OPTS ?= -static -nostdlib -nostartfiles -lm -lgcc -T $(src_dir)/common/test.ld
RISCV_OBJDUMP ?= $(RISCV_PREFIX)objdump --disassemble-all --disassemble-zeroes --section=.text --section=.text.startup --section=.text.init --section=.data
OBJDUMP_LLVM ?= llvm-objdump --disassemble-all --disassemble-zeroes --section=.text --section=.text.startup --section=.text.init --section=.data
RISCV_OBJCOPY ?= $(RISCV_PREFIX)objcopy
RISCV_SIM ?= spike --isa=rv$(XLEN)gcv

incs  += -I$(src_dir)/../env -I$(src_dir)/common $(addprefix -I$(src_dir)/, $(bmarks))
objs  :=

define compile_template
$(1).riscv: $(wildcard $(src_dir)/$(1)/*) $(wildcard $(src_dir)/common/*)
	$$(RISCV_GCC) $$(incs) $$(RISCV_GCC_OPTS) -o $$@ $(wildcard $(src_dir)/$(1)/*.c) $(wildcard $(src_dir)/$(1)/*.S) $(wildcard $(src_dir)/common/*.c) $(wildcard $(src_dir)/common/*.S) $$(RISCV_LINK_OPTS)
endef

$(foreach bmark,$(bmarks),$(eval $(call compile_template,$(bmark))))

#------------------------------------------------------------
# Build and run benchmarks on riscv simulator

bmarks_riscv_bin  = $(addsuffix .riscv,  $(bmarks))
bmarks_riscv_hex  = $(addsuffix .hex,  $(bmarks))
bmarks_riscv_hex64  = $(addsuffix .64.hex,  $(bmarks))
bmarks_riscv_binary  = $(addsuffix .binary,  $(bmarks))
bmarks_riscv_dump = $(addsuffix .riscv.dump, $(bmarks))
bmarks_riscv_dump_llvm = $(addsuffix .riscv.llvm.dump, $(bmarks))
bmarks_riscv_out  = $(addsuffix .riscv.out,  $(bmarks))

$(bmarks_riscv_dump): %.riscv.dump: %.riscv
	$(RISCV_OBJDUMP) $< > $@

$(bmarks_riscv_dump_llvm): %.riscv.llvm.dump: %.riscv
	$(OBJDUMP_LLVM) $< > $@

$(bmarks_riscv_out): %.riscv.out: %.riscv
	$(RISCV_SIM) $< > $@

%.binary: %.riscv
	$(RISCV_OBJCOPY) $< -O binary $@

%.hex: %.binary
	od -An -t x1 $< -w1 -v | tr -d " " > $@

%.64.hex: %.binary
	od -An -t x8 $< -w8 -v | tr -d " " > $@

riscv: $(bmarks_riscv_dump) $(bmarks_riscv_hex) $(bmarks_riscv_hex64) $(bmarks_riscv_dump_llvm)
run: $(bmarks_riscv_out)

junk += $(bmarks_riscv_bin) $(bmarks_riscv_dump) $(bmarks_riscv_hex) $(bmarks_riscv_hex64) $(bmarks_riscv_out)

#------------------------------------------------------------
# Default

all: riscv

#------------------------------------------------------------
# Install

date_suffix = $(shell date +%Y-%m-%d_%H-%M)
install_dir = $(instbasedir)/$(instname)-$(date_suffix)
latest_install = $(shell ls -1 -d $(instbasedir)/$(instname)* | tail -n 1)

install:
	mkdir $(install_dir)
	cp -r $(bmarks_riscv_bin) $(bmarks_riscv_dump) $(bmarks_riscv_hex) $(bmarks_riscv_hex64) $(install_dir)

install-link:
	rm -rf $(instbasedir)/$(instname)
	ln -s $(latest_install) $(instbasedir)/$(instname)

#------------------------------------------------------------
# Clean up

clean:
	rm -rf $(objs) $(junk)
