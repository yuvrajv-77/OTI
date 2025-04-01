// gas 
int LED = 13;
int BUZZ = 3;
int MQ2Pin = A0;
const int gas = 0;
void setup()
{
 pinMode(LED, OUTPUT);
Mohit Gohil FDMSCIT002A
 pinMode(BUZZ, OUTPUT);
}
void loop(){
 float sensorValue;
 sensorValue = analogRead(MQ2Pin);
 if(sensorValue >= 200){
 digitalWrite(LED, HIGH);
 digitalWrite(BUZZ, HIGH);
 }
 else {
 digitalWrite(LED, LOW);
 digitalWrite(BUZZ, LOW);
 }
 delay(500);
}




//ultrasonic
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
long duration;
int distance;
int safetyDistance;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledPin, OUTPUT);

Serial.begin(9600);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
safetyDistance = distance;
if (safetyDistance <= 5){
 digitalWrite(ledPin, HIGH);
}
else{
 digitalWrite(ledPin, LOW);
}
Serial.print("Distance: ");
Serial.println(distance);
}





//temp
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

const int buzzer = 2;
const int sensor = A0;
void setup()
{
 lcd.init();
 lcd.backlight();
 pinMode(buzzer, OUTPUT);
 pinMode(sensor, INPUT);
 Serial.begin(9600);
}
void loop()
{
 int sensorValue = analogRead(sensor);
 float voltage = sensorValue * (5.0 / 1023.0);
 float temperature = (voltage - 0.5) * 100;
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Temp: ");
 lcd.print(temperature);
 lcd.print(" C");
 if (temperature > 30.0) {
 tone(buzzer, 1000);
 } else {
 noTone(buzzer);
 }
 Serial.print("Temperature: ");
 Serial.print(temperature);
 Serial.println(" C");
 delay(1000)

 //moisture
 #include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int sensorPin = A0;
int ledPin = 13;
int buzzerPin = 8;
int motorPin = 9;
int sensorValue = 0;
int threshold = 300;
void setup() {
 lcd.init();
 lcd.backlight();
 pinMode(ledPin, OUTPUT);
 pinMode(buzzerPin, OUTPUT);
 pinMode(motorPin, OUTPUT);
}
void loop() {
 lcd.clear();
 sensorValue = analogRead(sensorPin);
 lcd.print("Moisture: ");
 lcd.print(sensorValue);
 if (sensorValue < threshold) {
 digitalWrite(ledPin, HIGH);
 tone(buzzerPin, 800);
 digitalWrite(motorPin, HIGH);
 } else {
 digitalWrite(ledPin, LOW);
 noTone(buzzerPin);
 digitalWrite(motorPin, LOW);
 }
 delay(1000);
}

//force
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
int sensor = 0;
String lastMessage = "";
void setup()
{
 lcd.init();
 lcd.backlight();
 pinMode(A0, INPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
 Serial.begin(9600);
}
void loop()
{
 sensor = analogRead(A0);
 String message = "";
 if (sensor > 300) {
    digitalWrite(8, HIGH);
    message = "LED 1";
    } else {
    digitalWrite(8, LOW);
    }
    if (sensor > 200 && sensor <= 300) {
    digitalWrite(9, HIGH);
    message = "LED 2";
    } else {
    digitalWrite(9, LOW);
    }
    if (sensor > 100 && sensor <= 200) {
    digitalWrite(10, HIGH);
    message = "LED 3";
    } else {
    digitalWrite(10, LOW);
    }
    if (sensor > 50 && sensor <= 100) {
    digitalWrite(11, HIGH);
    message = "LED 4";
    } else {
    digitalWrite(11, LOW);
    }
    if (message != lastMessage) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
    lastMessage = message;
    }
    Serial.print("sensor = ");
 Serial.println(sensor);
 delay(100);
}

//camera
From picamzero import Camera
import os
from time import sleep
home dir = os.environ['HOME']
camera = Camera()
camera.start_preview()
camera.take_photo(f"[home_dir}/Desktop/image1.jpeg)
