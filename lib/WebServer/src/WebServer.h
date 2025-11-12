#ifndef SERVER_H
#define SERVER_H

#include <Arduino.h>
#include <WiFi.h>

class WebServer
{
	private:
		WiFiServer _server;
		WiFiClient _client;

		char* _ssid;
		const char* _password;
		bool _debug = false;
	
	public:
		WebServer(int port, char* ssid, const char* password, bool debug = false);
		~WebServer();

		void setup();
};

#endif
