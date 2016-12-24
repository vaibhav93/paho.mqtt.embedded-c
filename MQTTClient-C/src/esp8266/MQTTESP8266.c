/* Author : Vaibhav Bansal
   Description : ESP8266 MQTT Library for  RTOS SDK 1.4.0
                 Based on eclipse PAHO
   License : BSD
*/
#include "MQTTESP8266.h"

/*Initialize Timer*/
void TimerInit(Timer* timer)
{
	timer->xTicksToWait = 0;
	memset(&timer->xTimeOut, '\0', sizeof(timer->xTimeOut));
}

int TimerLeftMS(Timer* timer)
{
	xTaskCheckForTimeOut(&timer->xTimeOut, &timer->xTicksToWait); /* updates xTicksToWait to the number left */
	return (timer->xTicksToWait < 0) ? 0 : (timer->xTicksToWait * portTICK_PERIOD_MS);
}

char TimerIsExpired(Timer *timer)
{
  return xTaskCheckForTimeOut(&timer->xTimeOut, &timer->xTicksToWait) == pdTRUE;
}

void TimerCountdownMS(Timer* timer, unsigned int timeout_ms)
{
	timer->xTicksToWait = timeout_ms / portTICK_PERIOD_MS; /* convert milliseconds to ticks */
	vTaskSetTimeOutState(&timer->xTimeOut); /* Record the time at which this function was entered. */
}

void TimerCountdown(Timer* timer, unsigned int timeout)
{
	TimerCountdownMS(timer, timeout * 1000);
}

int ESP8266_read(Network* n, unsigned char* buffer, int len, int timeout_ms)
{
  int recvLen = 0;
  struct timeval tv;
  tv.tv_sec = timeout_ms/1000;
  tv.tv_usec = 0;
  fd_set readset;

  FD_ZERO(&readset);
  FD_SET(n->my_socket,&readset);

  if (lwip_select(n->my_socket + 1, &readset, NULL, NULL, &tv) > 0 && FD_ISSET(n->my_socket, &readset)) {
			rccvLen = lwip_recv(n->my_socket, buffer + recvLen, len - recvLen, 0);
	} else {
    return -1;
  }
  
	return recvLen;
}

int ESP8266_write(Network* n, unsigned char* buffer, int len, int timeout_ms)
{

}
