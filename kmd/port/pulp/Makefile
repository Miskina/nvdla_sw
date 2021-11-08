# CFLAGS += -I$(NVDLA_SW_HOME)/kmd/port/pulp/include
# CFLAGS += -I$(NVDLA_SW_HOME)/kmd/include
# CFLAGS += -I$(FIRMWARE_INCLUDE_DIR)
# CFLAGS += -I$(PULPRT_HOME)/include
# CFLAGS += -MMD
#


PULP_CFLAGS = -I$(NVDLA_SW_HOME)/kmd/port/pulp/include -I$(NVDLA_SW_HOME)/kmd/include -I$(FIRMWARE_INCLUDE_DIR) -O3 -g -c

PULP_APP = test
PULP_APP_SRCS := test.c nvdla_interface.c

include $(NVDLA_SW_HOME)/kmd/firmware/firmware.mk
include $(PULPRT_HOME)/rules/pulp.mk

DIR := ${CURDIR}
BUILD_DIR_PATH := $(DIR)/build

FIRMWARE_OBJS := $(patsubst %.c, %.o, $(FIRMWARE_SRCS))
FIRMWARE_OBJS := $(subst $(NVDLA_FIRMWARE_DIR),$(BUILD_DIR_PATH)/firmware,$(FIRMWARE_OBJS))

build/nvdla_interface.o: nvdla_interface.c
	mkdir -p build
	$(CC) $(PULP_CFLAGS) -c nvdla_interface.c -o $(BUILD_DIR_PATH)/nvdla_interface.o

$(FIRMWARE_OBJS): $(BUILD_DIR_PATH)/firmware/%.o: $(NVDLA_FIRMWARE_DIR)/%.c build/nvdla_interface.o

test.o: test.c $(FIRMWARE_OBJS)


