/* Author : Vaibhav Bansal
   Description : ESP8266 MQTT Library for  RTOS SDK 1.4.0
                 Based on eclipse PAHO
   License : BSD
*/
#include "MQTTESP8266.h"

int TimerLeftMS(Timer* timer)
{
	xTaskCheckForTimeOut(&timer->xTimeOut, &timer->xTicksToWait); /* updates xTicksToWait to the number left */
	return (timer->xTicksToWait < 0) ? 0 : (timer->xTicksToWait * portTICK_PERIOD_MS);
}

char TimerIsExpired(Timer *timer)
{
  return xTaskCheckForTimeOut(&timer->xTimeOut, &timer->xTicksToWait) == pdTRUE;
}
