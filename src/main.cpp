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
	int pval = analogRead(36);
	int mval = analogRead(39);

	String payload = String(pval) + "," + String(mval);

	Serial.print("Payload: ");
	Serial.println(payload);

	client.sendPost(SERVER_IP, payload);
	delay(5000);
}
