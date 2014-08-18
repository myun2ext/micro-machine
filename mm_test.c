#include <stdio.h>
#include "header/machine.h"

int g_test_total = 0;
int g_test_successfully = 0;

void expect_int(const char* context, int result, int expected)
{
  g_test_total++;

  if ( expected != result )
	printf("\n\nFailed %s. (expected %d, but result is %d)\n",
		context, expected, result);
  else {
	putchar('.');
	g_test_successfully++;
  }
}

/*****************************************/

mm_machine machine;

void init_machine_test()
{
  mm_init_machine(&machine);

  expect_int("mm_init_machine: registers zero init", machine.registers[0], 0);
  expect_int("mm_init_machine: stack zero init", machine.stack[0], 0);
  expect_int("mm_init_machine: stack size", machine.stack_size, MM_DEFAULT_STACK_SIZE);
  expect_int("mm_init_machine: stack used", machine.stack_used, 0);
}

void mm_stack_test()
{
  mm_stack_push(&machine, 3);
  expect_int("mm_stack_push (a)", machine.stack[0], 3);
  expect_int("mm_stack_push (a): stack used", machine.stack_used, 1);

  mm_stack_push(&machine, 0x12345678);
  expect_int("mm_stack_push (b)", machine.stack[1], 0x12345678);
  expect_int("mm_stack_push (b): stack used", machine.stack_used, 2);

  expect_int("mm_stack_pop (b)", mm_stack_pop(&machine), 0x12345678);
  expect_int("mm_stack_pop (b): stack used", machine.stack_used, 1);

  expect_int("mm_stack_pop (a)", mm_stack_pop(&machine), 3);
  expect_int("mm_stack_pop (a): stack used", machine.stack_used, 0);
}

int main()
{
  init_machine_test();
  mm_stack_test();

  printf ("\n\nFinally\n");
  printf ("  Total: %d, Successfully: %d, Error: %d\n\n",
	  g_test_total, g_test_successfully, g_test_total - g_test_successfully);

  return 0;
}
