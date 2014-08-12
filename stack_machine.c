#include <stdio.h>

/*  Machine structure */
struct machine
{
	const char* script;
	const char* script_current;
	int registers[1024];

	char buffer[2048];
	char* top_ptr;
};
__thread char script[1024 * 16];

const char* read_script(/*char* buffer, unsigned int buffer_size,*/ const char* filename)
{
	FILE *fp = fopen(filename, "r");
	if ( fp == NULL )
		return NULL;

	fread(script, sizeof(script), 1, fp);
	return script;
}

int run(struct machine*, const char* readed_buffer);

/*  Stack Machine IO Main Function  */
int main(int argc, const char *argv[])
{
	/*  Variables */
	const char* script_filename = argv[1];
	char read_buffer[256];
	struct machine m = {};
	int ret = 0;

	/*  Init machine */
	m.script = script;
	m.script_current = m.script;
	m.top_ptr = m.buffer;

	/*  Read Script */
	read_script(script_filename);

	/*  Running... */
	while(fgets(read_buffer, sizeof(read_buffer), stdin) != 0) {
		ret = run(&m, read_buffer);
	}
	return ret;
}
