#include <Arduino.h>
#include <WebClient.h>
#include <WiFiCredentials.h>

constexpr int PHOTO_PIN = 36;
constexpr int MOIST_PIN = 39;
constexpr int DELAY_TIME = 5000;
constexpr int VDIV_RES = 4700;

WebClient client(WIFI_SSID, WIFI_PASS, true);

void setup()
{
	Serial.begin(9600);
	client.setup();
}

void loop()
{
	int pval = analogRead(PHOTO_PIN);
	int mval = analogRead(MOIST_PIN);

	/*
	float pvoltage = pval * (3.3f / 4096.0f);
	float pres = VDIV_RES * (3.3f / pvoltage - 1);
	float plux = 
	*/

	String payload = String(pval) + "," + String(mval);

	Serial.print("Payload: ");
	Serial.println(payload);

	client.sendPost(SERVER_IP, payload);
	delay(DELAY_TIME);
}
