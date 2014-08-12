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

int proc_script(struct machine* m, char c)
{
	if ( *(m->script_current) == 'p' )
		putchar(c);
	return 0;
}

int proc_byte(struct machine* m, char c)
{
	if ( c == '\0' )
		return 1;

	/*  Skip Return */
	while(*(m->script_current) == '\r' || *(m->script_current) == '\n' )
		m->script_current++;

	if ( *(m->script_current) == '\0' )
		m->script_current = m->script;
		//return 1;

	if ( *(m->script_current) == '[' ) {
		while(*(m->script_current++) != ']') {
			proc_script(m,c);
		}
	}
	else
		proc_script(m,c);

	m->script_current++;
	return 0;
}

int run(struct machine* m, const char* readed_buffer)
{
	const char* p = readed_buffer;
	int ret = 0;
	while(!(ret = proc_byte(m, *(p++))));
	return ret;
}
