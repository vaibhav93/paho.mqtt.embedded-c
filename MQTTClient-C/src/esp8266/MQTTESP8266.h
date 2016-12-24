#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void TimerInit(Timer*);
int TimerLeftMS(Timer*);
char TimerIsExpired(Timer*);
void TimerCountdownMS(Timer*, unsigned int);
void TimerCountdown(Timer*, unsigned int);
int ESP8266_read(Network*, unsigned char*, int, int);
int ESP8266_write(Network*, unsigned char*, int, int);
