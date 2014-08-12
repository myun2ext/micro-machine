#include <stdio.h>

struct sm_stack
{
	char buffer[2048];
	char* top_ptr;
};
char script_buffer[1024 * 16];

const char* read_script(const char* filename)
{
	FILE *fp = fopen(filename, "r");
	if ( fp == NULL )
		return NULL;

	fread(script_buffer, sizeof(script_buffer), 1, fp);
	return script_buffer;
}

int run(struct sm_stack*, const char* readed_buffer, char* script_ptr);

int main(int argc, const char *argv[])
{
	/*  Variables */
	const char* script_filename = argv[1];
	char readed[256];
	struct sm_stack stack = { "", NULL };
	int ret = 0;
	const char* script_ptr = script_buffer;

	/*  Init stack */
	stack.top_ptr = stack.buffer;

	/*  Read Script */
	read_script(script_filename);

	/*  Running... */
	while(fgets(readed, sizeof(readed), stdin) != 0) {
		ret = run(&stack, readed, &script_ptr);
	}
	return ret;
}
