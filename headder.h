#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <Arduino.h>

void bt_car_init(int f1, int b1, int f2, int b2);
void stop(void);
void forword(void);
void backword(void);
void fleft(void);
void fright(void);
void bleft(void);
void bright(void);
void car_auto(void);
void car_manual(void);

#endif
