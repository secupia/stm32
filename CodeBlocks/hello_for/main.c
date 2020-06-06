#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main()
{
#if 0
    int j = 0;

    for(int i=0; i<10; i++)
    {
        printf("i value = %2d \n", i);
        j++;
    }
    printf("Hello world!\n");
#endif // 0

#if 1
    uint8_t eeprom[] = "Hello EEPROM";

    printf("STRING = %s\n", &eeprom[0]);
    //printf("String length = %2d \n", strlen(eeprom));
    printf("String length = %2d \n", (uint8_t)strlen("STM32 I2C"));

    for(int i=0; i<(int)strlen(eeprom); i++)
    {
        printf("%c", eeprom[i]);
    }
    printf("\n");
#endif // 1
    return 0;
}
