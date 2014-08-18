#ifndef __MYUN2_GITHUB__MICRO_MACHINE__MACHINE_H__
#define __MYUN2_GITHUB__MICRO_MACHINE__MACHINE_H__

typedef int 			mm_data_t;
typedef unsigned int 	mm_size_t;
typedef mm_data_t 		mm_stack_entry_t;

typedef struct {
	mm_stack_entry_t	*stack;
	mm_size_t			stack_size;
	mm_size_t			stack_used;
} mm_machine;

#endif//__MYUN2_GITHUB__MICRO_MACHINE__MACHINE_H__
