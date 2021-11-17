
include $(NVDLA_SW_HOME)/kmd/firmware/firmware.mk

PULP_CFLAGS += -I$(NVDLA_SW_HOME)/kmd/port/pulp/include -I$(NVDLA_SW_HOME)/kmd/include -I$(FIRMWARE_INCLUDE_DIR) -O3 -g # -c

PULP_APP_SRCS += $(NVDLA_SW_HOME)/kmd/port/pulp/nvdla_interface.c $(FIRMWARE_SRCS)
