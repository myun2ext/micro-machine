/*  Machine structure */
struct machine
{
	const char* script;
	const char* script_current;
	int registers[1024];
	char stack[2048];
	char* top_ptr;
};

int run(struct machine* m, const char* readed_buffer)
{
	const char* p = readed_buffer;
	while(*p != '\0') {
		p++;
	}
	return 0;
}
