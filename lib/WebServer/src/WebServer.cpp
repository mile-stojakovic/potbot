#include "WebServer.h"

WebServer::WebServer(int port, char* ssid, const char* password, bool debug) : _server(port), _ssid(ssid), _password(password), _debug(debug) {}

void WebServer::setup()
{
	WiFi.begin(_ssid, _password);

	if (_debug)
	{
		Serial.print("Connecting to ");
		Serial.println(_ssid);
	}

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
	}

	if (_debug)
	{
		Serial.println("");
		Serial.print("Connected. IP Address: ");
		Serial.println(WiFi.localIP());
	}

	_server.begin();
}
