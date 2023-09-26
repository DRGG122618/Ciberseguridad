#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal.h>

int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
int numero = 0;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

const int PinDataDQ = 10;
OneWire OneWireObjeto(PinDataDQ);
DallasTemperature sensorDS18B20(&OneWireObjeto);

void setup() {
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  sensorDS18B20.begin();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("PH: ");

  float voltage_ph = 5 / 1024.0 * analogRead(A0);
  float ph = 7 + ((2.5 - voltage_ph) / 0.18);
  lcd.print(ph);

  lcd.setCursor(0, 1);
  sensorDS18B20.requestTemperatures();
  lcd.print("Temp: ");
  lcd.print(sensorDS18B20.getTempCByIndex(0));
  lcd.print("C");
  delay(500);
}