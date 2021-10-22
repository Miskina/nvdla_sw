obj-m += opendla.o

ccflags-y += -I$(src)/include
ccflags-y += -I$(src)/../../include
ccflags-y += -Werror

PULPRT_TARGET=pulpissimo

# PULPRT_HOME in environment variable
include $(src)/../../firmware/Makefile
include $(PULPRT_HOME)/rules/pulp.mk

opendla-y += nvdla_interface.c