#include <WebClient.h>

WebClient::WebClient(char* ssid, const char* password, bool debug) : _ssid(ssid), _password(password), _debug(debug) {}

void WebClient::setup()
{
	WiFi.begin(_ssid, _password);
	
	if (_debug)
		Serial.println("Connecting to WiFi network");

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(100);

		if (_debug)
			Serial.print(".");
	}

	if (_debug)
	{
		Serial.println("Connected to WiFi.");
		Serial.print("Device IP Address: ");
		Serial.println(WiFi.localIP());
	}
}

int WebClient::sendPost(String url, String requestData)
{
	if (WiFi.status() != WL_CONNECTED)
		return -1;

	HTTPClient http;

	http.begin(_client, url.c_str());
	http.addHeader("Content-Type", "text/plain");

	int response = http.POST(requestData);

	if (_debug)
	{
		Serial.print("HTTP Response: ");
		Serial.println(response);
	}

	http.end();

	return 0;
}
