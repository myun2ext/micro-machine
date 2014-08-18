#include <stdio.h>

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

int main()
{
  expect_int("test1", 0, 0);
  expect_int("test2", 1, 0);

  printf ("Finally\n");
  printf ("  Total: %d, Successfully: %d, Error: %d\n\n",
	  g_test_total, g_test_successfully, g_test_total - g_test_successfully);

  return 0;
}
