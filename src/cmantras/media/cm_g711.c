#include "cm_g711.h"

#define ALAW_MAX  0xFFF
#define MULAW_MAX 0x1FFF
#define MULAW_BIAS 33

int8_t cm_g711_mu_law_encode(int16_t number)
{
    uint16_t mask = 0x1000;
    uint8_t sign = 0;
    uint8_t position = 12, lsb = 0;
    if (number < 0)
    {
        number = -number;
        sign = 0x80;
    }
    number += MULAW_BIAS;
    if (number > MULAW_MAX)
    {
        number = MULAW_MAX;
    }
    for (; ((number & mask) != mask && position >= 5); mask >>= 1, position--);
    lsb = (number >> (position - 4)) & 0x0f;
    return (~(sign | ((position - 5) << 4) | lsb));
}

int16_t cm_g711_mu_law_decode(int8_t number)
{
    uint8_t sign = 0, position = 0;
    int16_t decoded = 0;
    number = ~number;
    if (number & 0x80)
    {
        number &= ~(1 << 7);
        sign = -1;
    }
    position = ((number & 0xF0) >> 4) + 5;
    decoded = ((1 << position) | ((number & 0x0F) << (position - 4))
            | (1 << (position - 5))) - MULAW_BIAS;
    return (sign == 0) ? (decoded) : (-(decoded));
}

int8_t cm_g711_a_law_encode(int16_t number)
{
    uint16_t mask = 0x800;
    uint8_t sign = 0;
    uint8_t position = 11, lsb = 0;
    if (number < 0)
    {
        number = -number;
        sign = 0x80;
    }
    if (number > ALAW_MAX)
    {
        number = ALAW_MAX;
    }
    for (; ((number & mask) != mask && position >= 5); mask >>= 1, position--);
    lsb = (number >> ((position == 4) ? (1) : (position - 4))) & 0x0f;
    return (sign | ((position - 4) << 4) | lsb) ^ 0x55;
}

int16_t cm_g711_a_law_decode(int8_t number)
{
    uint8_t sign = 0x00, position = 0;
    int16_t decoded = 0;
    number ^= 0x55;
    if (number & 0x80)
    {
        number &= ~(1 << 7);
        sign = -1;
    }
    position = ((number & 0xF0) >> 4) + 4;
    if (position != 4)
    {
        decoded = ((1 << position) | ((number & 0x0F) << (position - 4))
                | (1 << (position - 5)));
    }
    else
    {
        decoded = (number << 1) | 1;
    }
    return (sign == 0) ? (decoded) : (-decoded);
}
