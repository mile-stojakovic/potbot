#include <Arduino.h>
#include <WebClient.h>
#include <WiFiCredentials.h>

WebClient client(WIFI_SSID, WIFI_PASS, true);

void setup()
{
	Serial.begin(9600);
	client.setup();
}

void loop()
{
	client.sendPost(SERVER_IP, "bruh");
	delay(5000);
}
