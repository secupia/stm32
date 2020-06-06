#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint8_t i;

    for(i=0; i<20; i++)
    {
        printf("Debugging message %03d \r\n", i);
    }
    printf("Hello world!\n");
    return 0;
}
