#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>

#include <BlynkSimpleEsp8266.h>
#include  "ThingSpeak.h"

#define IP "184.106.153.149" 

char auth[] = //Authentication Code
char ssid[] = //Wi-Fi name;
char pass[] = //Wi-Fi password;

unsigned long channelID = //Channel ID
unsigned  int field_no= //Field Number
const char* writeAPIKey = //ThingSpeak Write API Key
const char* readAPIKey  = //ThingSpeak Read API Key
String twitterAPIKey = //ThingSpeak Twitter API Key;

int sicaklikSensor = // Censor
float sicaklikDegeri;
float olculenDeger;

WiFiClient  client;

void  wifiSetup (){
    delay (10);
    Serial.println(); Serial.println(ssid);
    Serial.println(F("Kablosuz  Agina Baglaniyor"));
    WiFi.begin(ssid, pass);

    while (WiFi.status()  !=  WL_CONNECTED) 
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println();
    Serial.print(ssid);
    Serial.println("Kablosuz  Aga Baglandi");
    Serial.println("IP  adresi: "); 
    Serial.println(WiFi.localIP());
}

void  setup() 
{
    Serial.begin(9600);
    wifiSetup();
    ThingSpeak.begin(client);
    Blynk.begin(auth, ssid, pass);

    pinMode (A0,INPUT);
    pinMode(D0,OUTPUT);
    pinMode(D1,OUTPUT);
    pinMode(D2,OUTPUT);
    pinMode(D3,INPUT);

    digitalWrite(D3,LOW);
    Serial.println(F("Kurulum Hazır"));
}

void  loop()  {
    delay(500);
    Blynk.run();

    if(digitalRead(D3)==HIGH)
    {
      sicaklik(); 
    }

    else
    {
        analogWrite(D0,0);
        analogWrite(D1,0);
        analogWrite(D2,0);
    }      
}

void  sicaklik ()
{

    float olculenDeger  = analogRead  (sicaklikSensor); 
    olculenDeger  = (olculenDeger/1024)*5000;    
    sicaklikDegeri  = olculenDeger  /12,0;
    sicaklikDegeri  = sicaklikDegeri-10;

    String tweet = (String(sicaklikDegeri) + " °C");

      if (client.connect("184.106.153.149", 80))
      {
        client.print("GET /apps/thingtweet/1/statuses/update?key=" + twitterAPIKey + "&status=" + tweet + " HTTP/1.1\r\n");
        client.print("Host: api.thingspeak.com\r\n");
        client.print("Accept: */*\r\n");
        client.print("User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n");
        client.print("\r\n");
      }

    if(sicaklikDegeri < 25)
    {
      analogWrite(D0,2);
      analogWrite(D1,2);
      analogWrite(D2,212);
    }

    else if(sicaklikDegeri >=25 && sicaklikDegeri< 30)
    {
      analogWrite(D0,255);
      analogWrite(D1,255);
      analogWrite(D2,88);
    }

    else
    {
      analogWrite(D0,212);
      analogWrite(D1,2);
      analogWrite(D2,2);
    }

    Serial.print("Sıcaklık: "); 
    Serial.println(String(sicaklikDegeri) +" °C");

    ThingSpeak.writeField (channelID, field_no, sicaklikDegeri, writeAPIKey); 
    Serial.println("\n");
 
    delay(10000);
}
