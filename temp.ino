#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup(){
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, Salamat!");
}

void loop()
{
  
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  
  lcd.clear();
  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  lcd.print(DHT.temperature);
  
  lcd.setCursor(0,1);
  lcd.print("Humidity = ");
  lcd.print(DHT.humidity);

  delay(3000);
}

