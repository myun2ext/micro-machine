#include <stdio.h>

/*  Machine structure */
struct machine
{
	const char* script;
	const char* script_current;
	int registers[1024];
	char stack[2048];
	char* top_ptr;
};

int proc_byte(struct machine* m, char c)
{
	if ( c == '\0' )
		return 1;

	putchar(c);
	return 0;
}

int run(struct machine* m, const char* readed_buffer)
{
	const char* p = readed_buffer;
	int ret = 0;
	while(!(ret = proc_byte(m, *(p++))));
	return ret;
}
