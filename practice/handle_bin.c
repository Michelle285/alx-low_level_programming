#include <unistd.h>
#include "main.h"

void handle_binary(unsigned int num, char *buffer, int *buff_ind, int *count) {
    char temp_buffer[32];
    int temp_ind = 0;

    do {
        temp_buffer[temp_ind++] = num % 2 + '0';
        num /= 2;
    } while (num > 0);

    while (temp_ind > 0) {
        if (*buff_ind == BUFFER_SIZE - 1) {
            *count = _write_buffer(buffer, buff_ind, count);
        }
        buffer[*buff_ind] = temp_buffer[--temp_ind];
        (*buff_ind)++;
    }
}
