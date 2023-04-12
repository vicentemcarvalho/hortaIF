#include "Arduino.h"
#include <MyRealTimeClock.h>

MyRealTimeClock relogioRTC(8, 7, 6); // Assign Digital Pins
#define TAMANHO 5
int hora[]={
		0,
		4,
		10,
		15,
		18}; //hora de inicio

int min[]={
		0,
		0,
		0,
		0,
		0};  //minuto de inicio

boolean regar[]={
		false,
		false,
		false,
		false,
		false},
		regando=false;
float duracao[]={
		1.0,
		1.0,
		1.0,
		1.0,
		1.0}; //duracao (hora ou fracao)

float instante[TAMANHO];
byte pinRele = 9;

void setup() {
	Serial.begin(9600);
	pinMode(pinRele, OUTPUT);
	digitalWrite(pinRele, LOW);

	int i=0;
	for(i=0;i<TAMANHO;i++){
		instante[i]=hora[i]+(float)min[i]/60;
	}
	delay(100);

/* To set the current time and date in specific format
| Second 00 | Minute 59 | Hour 10 | Day 12 |  Month 07 | Year 2015 |
*/
	relogioRTC.updateTime();
	if(relogioRTC.year<2017)
		relogioRTC.setDS1302Time(00, 00, 30, 10 , 06, 05, 2017);
	//relogioRTC.setDS1302Time(20, 35, 14, 02 , 8, 05, 2017);
}

void loop() {
// Allow the update of variables for time / accessing the individual element.
	relogioRTC.updateTime();
	Serial.print(regando);
	Serial.print("\nRelogio:\t");
	Serial.print(relogioRTC.hours); // Element 4
	Serial.print(":");
	Serial.print(relogioRTC.minutes); // Element 5
	Serial.print(":");
	Serial.print(relogioRTC.seconds); // Element 6
	Serial.print("\t\tData:\t");
	Serial.print(relogioRTC.year);
	Serial.print(relogioRTC.month);
	Serial.println(relogioRTC.dayofmonth);

	float agora = relogioRTC.hours+(float)relogioRTC.minutes/60;
	Serial.print("Agora:\t\t");
	Serial.println(agora);

	int i=0;
	for(i=0;i<TAMANHO;i++){

		Serial.print("Inicial");
		Serial.print(i);
		Serial.print(":  ");
		Serial.print(instante[i]);


		Serial.print("\t\tfinal:\t\t");
		Serial.print(instante[i]+duracao[i]);

		regar[i] = (agora>=instante[i] && agora<=instante[i]+duracao[i]);
		Serial.print("\t\tRega");
		Serial.print(i);
		Serial.print(": \t\t");
		Serial.println(regar[i]);

		regando = regando || regar[i];
	}
	if(regando!=0) {
		digitalWrite(pinRele, LOW);
		Serial.println("HIGH");
		regando = false;
	}
	else {
		digitalWrite(pinRele, HIGH);
		Serial.println("LOW");
	}
	delay(9500);
}
