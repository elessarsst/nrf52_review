/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_WATCHDOG_H
#define Z_INCLUDE_SYSCALLS_WATCHDOG_H


#include <tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#include <linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_wdt_setup(const struct device * dev, uint8_t options);

__pinned_func
static inline int wdt_setup(const struct device * dev, uint8_t options)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; uint8_t val; } parm1 = { .val = options };
		return (int) arch_syscall_invoke2(parm0.x, parm1.x, K_SYSCALL_WDT_SETUP);
	}
#endif
	compiler_barrier();
	return z_impl_wdt_setup(dev, options);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define wdt_setup(dev, options) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_WDT_SETUP, wdt_setup, dev, options); 	retval = wdt_setup(dev, options); 	sys_port_trace_syscall_exit(K_SYSCALL_WDT_SETUP, wdt_setup, dev, options, retval); 	retval; })
#endif
#endif


extern int z_impl_wdt_disable(const struct device * dev);

__pinned_func
static inline int wdt_disable(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		return (int) arch_syscall_invoke1(parm0.x, K_SYSCALL_WDT_DISABLE);
	}
#endif
	compiler_barrier();
	return z_impl_wdt_disable(dev);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define wdt_disable(dev) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_WDT_DISABLE, wdt_disable, dev); 	retval = wdt_disable(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_WDT_DISABLE, wdt_disable, dev, retval); 	retval; })
#endif
#endif


extern int z_impl_wdt_feed(const struct device * dev, int channel_id);

__pinned_func
static inline int wdt_feed(const struct device * dev, int channel_id)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; int val; } parm1 = { .val = channel_id };
		return (int) arch_syscall_invoke2(parm0.x, parm1.x, K_SYSCALL_WDT_FEED);
	}
#endif
	compiler_barrier();
	return z_impl_wdt_feed(dev, channel_id);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define wdt_feed(dev, channel_id) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_WDT_FEED, wdt_feed, dev, channel_id); 	retval = wdt_feed(dev, channel_id); 	sys_port_trace_syscall_exit(K_SYSCALL_WDT_FEED, wdt_feed, dev, channel_id, retval); 	retval; })
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */
