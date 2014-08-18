#include "header/machine.h"
#include <stdlib.h>
#include <memory.h>

void mm_init_machine(mm_machine_t* m)
{
  memset(m, sizeof(mm_machine), 1);
  m->stack = (mm_stack_data_t*) calloc(MM_DEFAULT_STACK_SIZE, sizeof(mm_stack_data_t));
  m->stack_size = MM_DEFAULT_STACK_SIZE;
}

void mm_stack_push(mm_machine_t* m)
{
}

void mm_stack_pop(mm_machine_t* m)
{
}
