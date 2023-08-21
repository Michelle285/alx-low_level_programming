#include <unistd.h>
#include "main.h"

void handle_unsigned(unsigned int num, char *buffer, int *buff_ind, int *count) {
    char temp_buffer[20];
    int temp_ind = 0;

    do {
        temp_buffer[temp_ind++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    while (temp_ind > 0) {
        if (*buff_ind == BUFFER_SIZE - 1) {
            *count = _write_buffer(buffer, buff_ind, count);
        }
        buffer[*buff_ind] = temp_buffer[--temp_ind];
        (*buff_ind)++;
    }
}
