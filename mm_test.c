#include <stdio.h>
#include "header/machine.h"

int g_test_total = 0;
int g_test_successfully = 0;

void expect_int(const char* context, int x, int result)
{
  g_test_total++;

  if ( x != result )
	printf("\n\nFailed %s. (expected %d, but result is %d)\n\n",
		context, x, result);
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
}

int main()
{
  init_machine_test();

  printf ("\n\nFinally\n");
  printf ("  Total: %d, Successfully: %d, Error: %d\n\n",
	  g_test_total, g_test_successfully, g_test_total - g_test_successfully);

  return 0;
}
