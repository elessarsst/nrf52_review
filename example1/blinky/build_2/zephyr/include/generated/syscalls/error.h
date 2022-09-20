/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_ERROR_H
#define Z_INCLUDE_SYSCALLS_ERROR_H


#include <tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#include <linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern void z_impl_user_fault(unsigned int reason);

__pinned_func
static inline void user_fault(unsigned int reason)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; unsigned int val; } parm0 = { .val = reason };
		(void) arch_syscall_invoke1(parm0.x, K_SYSCALL_USER_FAULT);
		return;
	}
#endif
	compiler_barrier();
	z_impl_user_fault(reason);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define user_fault(reason) do { 	sys_port_trace_syscall_enter(K_SYSCALL_USER_FAULT, user_fault, reason); 	user_fault(reason); 	sys_port_trace_syscall_exit(K_SYSCALL_USER_FAULT, user_fault, reason); } while(false)
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */
