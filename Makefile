TOPDIR			:=$(dir $(abspath $(firstword $(MAKEFILE_LIST))))
NPROC			:=$(shell nproc)
CMAKE 			:=cmake
SOURCE_DIR		:=$(TOPDIR)
BUILD_DIR		:=build
OUTPUT_DIR		:=output
TOOLCHAIN_FILE 	:=scripts/cmake/soc/corex-a53.cmake

# 0: Silent | 1: Verbose
V				?=1
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

.PHONY: $(phony)
