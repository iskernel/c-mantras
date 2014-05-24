#ifndef CM_G711_H_
#define CM_G711_H_

#include<stdint.h>

//A-Law Companding
int8_t cm_g711_a_law_encode(int16_t number);
int16_t cm_g711_a_law_decode(int8_t number);
//Mu-Law Companding
int8_t cm_g711_mu_law_encode(int16_t number);
int16_t cm_g711_mu_law_decode(int8_t number);

#endif
