#ifndef __MYUN2_GITHUB__MICRO_MACHINE__MACHINE_H__
#define __MYUN2_GITHUB__MICRO_MACHINE__MACHINE_H__

typedef int 			mm_data_t;
typedef unsigned int 	mm_size_t;
typedef mm_data_t 		mm_stack_entry_t, mm_stack_data_t;
typedef mm_data_t 		mm_register_t;

#define MM_DEFAULT_STACK_SIZE	128
#define REGISTER_SIZE			2048

typedef struct {
  /* Stacks */
  mm_stack_entry_t	*stack;
  mm_size_t			stack_size;
  mm_size_t			stack_used;

  /* Registers */
  mm_register_t		registers[REGISTER_SIZE];
} mm_machine, mm_machine_t;

void mm_init_machine(mm_machine_t* m);

#endif//__MYUN2_GITHUB__MICRO_MACHINE__MACHINE_H__
