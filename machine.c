#include "header/machine.h"
#include <memory.h>

void mm_init_machine(mm_machine_t* m)
{
  memset(m, sizeof(mm_machine), 1);
}

void mm_stack_push(mm_machine_t* m)
{
}

void mm_stack_pop(mm_machine_t* m)
{
}
