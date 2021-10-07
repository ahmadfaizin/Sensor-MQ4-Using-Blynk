// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "M3Nz8NWs8OdStVnrMc4fcYsXuf_ldELA";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Pesma SDM IPTEK";
char pass[] = "benTen10";

int buserku = D1;
int Gasku = A0;

int EWSku = 430;

void setup()
{
  pinMode(buserku, OUTPUT);
  pinMode(Gasku, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  int SensorGas = analogRead(Gasku);
  Serial.println("data Gas : ");
  Serial.println(SensorGas);
  Blynk.run();  

  if (SensorGas > EWSku)
  {
    tone (buserku, 2000, 300);
    Blynk.notify("EWS-kondisi Gas Berbahaya");
  }
  else
  {
    noTone(buserku);
  }
  delay(1000);
}
