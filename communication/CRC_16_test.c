#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef unsigned short u16;
typedef unsigned char u8;

#define MD_CRC16_POLYNOMIAL 0xA001

u16 crc16_table[256];

void Make_CRC16_Table(void)
{
    int i = 0, j = 0;
    u16 crc = 0, u = 0;

    for (i = 0; i < 256; ++i) {
        crc = 0;
        u = i;

        for (j = 0; j < 8; ++j) {
            if ((crc ^ u) & 0x0001)
                crc = (crc >> 1) ^ MD_CRC16_POLYNOMIAL;
            else
                crc = crc >> 1;
            u >>= 1;
        }
        crc16_table[i] = crc;
    }
}

u16 Compute_CRC16(u8 *buf, int length)
{
    u16 crc = 0xFFFF;
    while (length-- > 0) {
        crc = (crc >> 8) ^ crc16_table[(crc ^ (u16)*buf++) & 0x00FF];
    }
    return crc;
}

int main(void)
{
    u8 send_data[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    u16 crc;

    Make_CRC16_Table();

    crc = Compute_CRC16((u8 *)send_data, 9);

    printf("0x%04X", crc);

    return 0;
}