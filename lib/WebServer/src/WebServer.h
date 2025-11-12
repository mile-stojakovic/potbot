#ifndef SERVER_H
#define SERVER_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

class WebServer
{
	private:
		WiFiServer _server;

		char* _ssid;
		const char* _password;
		bool _debug = false;

		unsigned long _currentTime = 0;
		unsigned long _prevTime = 0;

		String _header; // HTTP response header
	
	public:
		WebServer(int port, char* ssid, const char* password, bool debug = false);

		void setup();
		void loop();
};

#endif
