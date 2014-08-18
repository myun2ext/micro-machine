#include <stdio.h>

mm_data_t mm_open(mm_machine_t* m, const char* file)
{
}

void mm_close(mm_machine_t* m, mm_data_t pipe_id)
{
}

void mm_write(mm_data_t pipe_id, int c)
{
  fputc(c, (FILE*)pipe_id);
}
