export GNUMAKEFLAGS=--no-print-directory
TOPDIR			:=$(dir $(abspath $(firstword $(MAKEFILE_LIST))))
NPROC			?=$(shell nproc)
CMAKE			:=cmake
SOURCE_DIR		:=$(TOPDIR)
BUILD_DIR		:=build
OUTPUT_DIR		:=output

PLATFORM		:=qemu-aarch64
TOOLCHAIN_FILE	:=scripts/cmake/platform/$(PLATFORM).cmake

QEMU			:=qemu-system-aarch64
QEMU_MACHINE	:=virt
QEMU_GIC_VER	:=2
QEMU_VIRT		:=off
QEMU_SECURE		:=on
QEMU_CPU		:=cortex-a53
QEMU_SMP		:=1
QEMU_RAM		:=512M
QEMU_IMG		:=output/bin/simple-boot-aarch64
QEMU_FLAGS		:=-d unimp -semihosting-config enable=on -nographic

# 0: Silent | 1: Verbose
V				?=0
ifeq ($(V),1)
    VERBOSE=-v
else
    VERBOSE=
endif

# Debug | MinSizeRel | Release | RelWithDebInfo 
BUILD_TYPE		?=Debug

all: build

phony+=config
config:
	$(CMAKE) -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN_FILE) -DCMAKE_BUILD_TYPE:STRING=$(BUILD_TYPE) -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S$(SOURCE_DIR) -B$(BUILD_DIR)

phony+=build
build: config
	$(CMAKE) --build $(BUILD_DIR) -j $(NPROC) $(VERBOSE)

phony+=clean
clean:
	$(CMAKE) --build $(BUILD_DIR) --target clean $(VERBOSE)

phony+=distclean
distclean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OUTPUT_DIR)

phony+=run_qemu
run_qemu:
	$(QEMU) -M $(QEMU_MACHINE),gic-version=$(QEMU_GIC_VER),virtualization=$(QEMU_VIRT),secure=$(QEMU_SECURE) -cpu $(QEMU_CPU) -smp $(QEMU_SMP) -m $(QEMU_RAM) -kernel $(QEMU_IMG) $(QEMU_FLAGS)

phony+=debug_qemu
debug_qemu:
	$(QEMU) -M $(QEMU_MACHINE),gic-version=$(QEMU_GIC_VER),virtualization=$(QEMU_VIRT),secure=$(QEMU_SECURE) -cpu $(QEMU_CPU) -smp $(QEMU_SMP) -m $(QEMU_RAM) -kernel $(QEMU_IMG) $(QEMU_FLAGS) -S -s

.PHONY: $(phony)
