/*
 * lm20.h
 *
 * Created: 11/21/2016 2:07:16 AM
 *  Author: max
 */ 


#ifndef LM20_H_
#define LM20_H_

void LM20_Init();
int LM20_GetTemperature();
int celsiusToKelvin(int celsius);
int celsiusToFarenheit(int celsius);

#endif /* LM20_H_ */