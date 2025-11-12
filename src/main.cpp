#include <Arduino.h>
#include <WebServer.h>

WebServer myServer(80, "NSA Wiretap", "wwntmq49aigjgv2", true);

void setup()
{
	Serial.begin(9600);
	myServer.setup();
}

void loop()
{
	myServer.loop();
}
