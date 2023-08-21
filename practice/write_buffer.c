#include "main.h"
#include <unistd.h>

int _write_buffer(char *buffer, int *buff_ind, int *count) {
    if (*buff_ind > 0)
    {
        *count += write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
    return *count;
}