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
	int val = analogRead(A0);

	client.sendPost(SERVER_IP, String(val));
	delay(5000);
}
