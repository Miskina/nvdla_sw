#ifndef __NVDLA_PULP_H__
#define __NVDLA_PULP_H__

#include <stdint.h>

/**
 * @brief			Task information submitted from user space
 *
 * num_addresses		Number of addresses in address list
 * address_list			Address list
 * nvdla_dev			Pointer to NVDLA device
 * file				DRM file instance
 */
struct nvdla_task {
	uint32_t num_addresses;
	struct nvdla_mem_handle *address_list;
	struct nvdla_device *nvdla_dev;
};

/**
 * @brief			Configuration parameters supported by the engine
 *
 * atom_size			Memory smallest access size
 * bdma_enable			Defines whether bdma is supported
 * rubik_enable			Defines whether rubik is supported
 * weight_compress_support	Defines whether weight data compression is supported
 */
struct nvdla_config
{
	uint32_t atom_size;
	bool bdma_enable;
	bool rubik_enable;
	bool weight_compress_support;
};

/**
 * @brief			NVDLA device
 *
 * irq				Interrupt number associated with this device
 * base				IO mapped base address for device
 * nvdla_lock			Spinlock used for synchronization
 * drm				DRM device instance
 * task				Pointer to task in execution
 * config_data			Pointer to the configuration data
 * pdev				Pointer to NVDLA platform device
 * event_notifier		Completion object used to wait for events from HW
 * engine_context		Private data passed from engine in dla_engine_init
 */
struct nvdla_device {
	int32_t irq;
	// void __iomem *base;
	// spinlock_t nvdla_lock;
	struct nvdla_task *task;
	struct nvdla_config *config_data;
	// struct platform_device *pdev;
	// struct completion event_notifier;

	void *engine_context;
};

/**
 * @brief			Submit task
 *
 * This function submits task to NVDLA engine.
 *
 * @param nvdla_dev		Pointer to NVDLA device
 * @param task			Pointer to task
 * @return			0 on success and negative on error
 *
 */
int32_t nvdla_task_submit(struct nvdla_device *nvdla_dev, struct nvdla_task *task);


#endif
