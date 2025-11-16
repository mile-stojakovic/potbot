#ifndef CLIENT_H
#define CLIENT_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

class WebClient
{
	private:
		char* _ssid;
		const char* _password;
		bool _debug;
		WiFiClient _client;
	public:
		WebClient(char* ssid, const char* password, bool debug = false);

		void setup();
		int sendPost(String url, String requestData);
};

#endif
