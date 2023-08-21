#include <unistd.h>
#include "main.h"

void handle_char(char c, char *buffer, int *buff_ind, int *count) {
    if (*buff_ind == BUFFER_SIZE - 1) {
        *count = _write_buffer(buffer, buff_ind, count);
    }
    
    buffer[*buff_ind] = c;
    (*buff_ind)++;
}
