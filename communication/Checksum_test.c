#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

unsigned char Compute_Checksum_8bits(unsigned char *buf, int size)
{
    unsigned char check_sum = 0x00;

    while (size-- > 0) {
        check_sum += *buf++;
    }

    return ~check_sum + 1;
}

int main(void)
{
    char send_data[5] = {13, 25, -18, 2,};
    int n = 0, check_sum = 0;

    send_data[4] = Compute_Checksum_8bits((unsigned char*)send_data, 4);

    for (n = 0; n < 5; ++n)
        check_sum += send_data[n];
    
    if (check_sum == 0)
        printf("Okay!\n");
    else
        printf("Error!\n");

    return 0;
}
