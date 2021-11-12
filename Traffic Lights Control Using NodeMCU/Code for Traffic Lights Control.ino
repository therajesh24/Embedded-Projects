#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = " hOVu7oCbOOewZy24G_50vP1WtIIBRxws";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "rajesh";
char pass[] = "rajesh143";
int rn=D8;
int re=3;
int rs=9;
int rw=10;
int gn=D4;
int ge=D5;
int gs=D6;
int gw=D7;
int n=D0;
int e=D1;
int s=D2;
int w=D3;
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
pinMode(rn,OUTPUT);
pinMode(re,OUTPUT);
pinMode(rs,OUTPUT);
pinMode(rw,OUTPUT);
pinMode(gn,OUTPUT);
pinMode(ge,OUTPUT);
pinMode(gs,OUTPUT);
pinMode(gw,OUTPUT);
pinMode(n,INPUT_PULLUP);
pinMode(e,INPUT_PULLUP);
pinMode(s,INPUT_PULLUP);
pinMode(w,INPUT_PULLUP);
digitalWrite(rn,HIGH);
digitalWrite(re,HIGH);
digitalWrite(rs,HIGH);
digitalWrite(rw,HIGH);
digitalWrite(gn,HIGH);
digitalWrite(ge,HIGH);
digitalWrite(gs,HIGH);
digitalWrite(gw,HIGH);
}

void loop() {
  
  if((digitalRead(n) == LOW) && (digitalRead(e) == LOW) && (digitalRead(s) == LOW) && (digitalRead(w) == LOW))// put your main code here, to run repeatedly:
{
  digitalWrite(rn,HIGH);
digitalWrite(re,LOW);
digitalWrite(rs,LOW);
digitalWrite(rw,LOW);
digitalWrite(gn,LOW);   // NORTH
digitalWrite(ge,HIGH);
digitalWrite(gs,HIGH);
digitalWrite(gw,HIGH);
Serial.println("NORTH");
delay(3000);
digitalWrite(rn,LOW);
digitalWrite(re,HIGH);
digitalWrite(rs,LOW);
digitalWrite(rw,LOW);
digitalWrite(gn,HIGH);  //EAST
digitalWrite(ge,LOW);
digitalWrite(gs,HIGH);
digitalWrite(gw,HIGH);
Serial.println("EAST");
delay(3000);
digitalWrite(rn,LOW);
digitalWrite(re,LOW);
digitalWrite(rs,HIGH);
digitalWrite(rw,LOW);
digitalWrite(gn,HIGH);   //SOUTH
digitalWrite(ge,HIGH);
digitalWrite(gs,LOW);
digitalWrite(gw,HIGH);
Serial.println("SOUTH");
delay(3000);
digitalWrite(rn,LOW);
digitalWrite(re,LOW);
digitalWrite(rs,LOW);
digitalWrite(rw,HIGH);
digitalWrite(gn,HIGH);
digitalWrite(ge,HIGH);   //WEST
digitalWrite(gs,HIGH);
digitalWrite(gw,LOW);
Serial.println("WEST");
delay(3000);
}
if((digitalRead(n) == HIGH) && (digitalRead(e) == LOW) && (digitalRead(s) == LOW) && (digitalRead(w) == LOW))
{
  digitalWrite(rn,HIGH);
digitalWrite(re,LOW);
digitalWrite(rs,LOW);
digitalWrite(rw,LOW);
digitalWrite(gn,LOW);   // NORTH
digitalWrite(ge,HIGH);
digitalWrite(gs,HIGH);
digitalWrite(gw,HIGH);
Serial.println("NORTH");
delay(3000);
}
if((digitalRead(n) == LOW) && (digitalRead(e) == HIGH) && (digitalRead(s) == LOW) && (digitalRead(w) == LOW))
{
  digitalWrite(rn,LOW);
digitalWrite(re,HIGH);
digitalWrite(rs,LOW);
digitalWrite(rw,LOW);
digitalWrite(gn,HIGH);  //EAST
digitalWrite(ge,LOW);
digitalWrite(gs,HIGH);
digitalWrite(gw,HIGH);
Serial.println("EAST");
delay(3000);
}
if((digitalRead(n) == LOW) && (digitalRead(e) == LOW) && (digitalRead(s) == HIGH) && (digitalRead(w) == LOW))
{
  digitalWrite(rn,LOW);
digitalWrite(re,LOW);
digitalWrite(rs,HIGH);
digitalWrite(rw,LOW);
digitalWrite(gn,HIGH);   //SOUTH
digitalWrite(ge,HIGH);
digitalWrite(gs,LOW);
digitalWrite(gw,HIGH);
Serial.println("SOUTH");
delay(3000);
}
if((digitalRead(n) == LOW) && (digitalRead(e) == LOW) && (digitalRead(s) == LOW) && (digitalRead(w) == HIGH))
{
  digitalWrite(rn,LOW);
digitalWrite(re,LOW);
digitalWrite(rs,LOW);
digitalWrite(rw,HIGH);
digitalWrite(gn,HIGH);
digitalWrite(ge,HIGH);   //WEST
digitalWrite(gs,HIGH);
digitalWrite(gw,LOW);
Serial.println("WEST");
delay(3000);
}
Blynk.run();
}
