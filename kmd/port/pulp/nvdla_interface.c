/* 
 * Authors:
 *  - Luka Macan <luka.macan@fer.hr>
 *  - Mihael Kovac <mihael.kovac@fer.hr>
 *
 */

#include <pulp.h>
#include <stdio.h>
#include <stdarg.h>
#include <nvdla_interface.h>

#define NVDLA_ADDR_BASE ARCHI_FC_HWPE_ADDR

#if defined(__riscv__) && !defined(RV_ISA_RV32)
#define NVDLA_WRITE(value, offset) __builtin_pulp_OffsetedWrite(value, (int *)NVDLA_ADDR_BASE, offset)
#define NVDLA_READ(offset) __builtin_pulp_OffsetedRead((int *)NVDLA_ADDR_BASE, offset)
#else
#define NVDLA_WRITE(value, offset) pulp_write32(NVDLA_ADDR_BASE + (offset), value)
#define NVDLA_READ(offset) pulp_read32(NVDLA_ADDR_BASE + (offset))
#endif

#define DLA_LOG_LVL_DEBUG 0
#define DLA_LOG_LVL_INFO 1
#define DLA_LOG_LVL_WARN 2
#define DLA_LOG_LVL_ERROR 3

#ifndef DLA_LOG_LVL
	#define DLA_LOG_LVL 0
#endif

extern int vfprintf(FILE* F, const char* format, va_list vargs);

#define _FPRINTF_VARGS_HELPER(_s, _stream)  \
	do                                      \
    {										\
		va_list _args;		  		  		\
		va_start(_args, _s);    	  		\
		vfprintf(_stream, _s, _args); 		\
		va_end(_args);				  		\
	} while(0)						  		\


uint32_t dla_reg_read(void* driver_context, uint32_t addr)
{
	return NVDLA_READ(addr);
}

void dla_reg_write(void* driver_context, uint32_t addr, uint32_t val)
{
	NVDLA_WRITE(val, addr);
}

int32_t dla_data_read(void* driver_context, void* task_data,
				uint64_t src, void* dst,
				uint32_t size, uint64_t offset)
{
	return 0;
}

int32_t dla_data_write(void* driver_context, void* task_data,
				void* src, uint64_t dst,
				uint32_t size, uint64_t offset)
{
	return 0;
}

int32_t dla_get_dma_address(void* driver_context, void* task_data,
					int16_t index, void* dst_ptr,
					uint32_t destination)
{
	return 0;
}

int64_t dla_get_time_us()
{
	return 0;
}

void dla_debug(const char* str, ...)
{
#if DLA_LOG_LVL <= DLA_LOG_LVL_DEBUG
	_FPRINTF_VARGS_HELPER(str, stdout);
#endif
}

void dla_info(const char* str, ...)
{
#if DLA_LOG_LVL <= DLA_LOG_LVL_INFO
	_FPRINTF_VARGS_HELPER(str, stdout);
#endif
}

void dla_warn(const char* str, ...)
{
#if DLA_LOG_LVL <= DLA_LOG_LVL_WARN
	_FPRINTF_VARGS_HELPER(str, stderr);
#endif
}

void dla_error(const char* str, ...)
{
	_FPRINTF_VARGS_HELPER(str, stderr);
}

void* dla_memset(void* src, int ch, uint64_t len)
{
	return memset(src, ch, len);
}

void* dla_memcpy(void* dest, const void* src, uint64_t len)
{
	return memcpy(dest, src, len);
}
