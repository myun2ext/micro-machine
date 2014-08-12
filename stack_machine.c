#include <stdio.h>

/*struct sm_stack
{
	char buffer[2048];
};*/

char script_buffer[1024 * 16];

const char* read_script(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if ( fp == NULL )
		return NULL;
	fread(script_buffer, sizeof(script_buffer), fp);
	return script_buffer;
}

int main(int argc, const char *argv[])
{
	const char* script_filename = argv[1];
	char buffer[256];
	char stack_buffer[2048];
	int ret = 0;
	while(fgets(buffer, sizeof(buffer), stdin) != 0) {
		//ret = run(stack_buffer, buffer, 
	}
	return ret;
}
