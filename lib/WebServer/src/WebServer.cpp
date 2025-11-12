#include "WebServer.h"

#define SERVER_TIMEOUT 2000

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
		if (_debug)
			Serial.print(".");

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

void WebServer::loop()
{
	WiFiClient client = _server.available();

	if (client)
	{
		_currentTime = millis();
		_prevTime = _currentTime;
		String currentLine = ""; // holds client data

		if (_debug)
			Serial.println("New client connected");

		while (client.connected() && _currentTime - _prevTime <= SERVER_TIMEOUT)
		{
			_currentTime = millis();

			if (client.available())
			{
				// HTTP request from client
				char c = client.read();

				if (_debug)
					Serial.write(c);
				
				_header += c;

				if (c == '\n')
				{
					// If client doesn't input anything, load server HTTP response
					if (currentLine.length() == 0)
					{
						client.println("HTTP/1.1 200 OK");
						client.println("Content-type:text/html");
						client.println("Connection: close");
						client.println();

						// TODO: load an actual file
						client.println("<!DOCTYPE HTML><html>");
						client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>");
						client.println("<body>Hello World!</body></html>");
						client.println();
						break;
					}
					else
					{
						currentLine = "";
					}
				}
				else if (c != '\r')
				{
					currentLine += c;
				}
			}
		}

		_header = "";

		client.stop();

		if (_debug)
			Serial.println("Client disconnected.");
	}
}
