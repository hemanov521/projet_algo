#include<ESP8266WiFi.h>

const char* ssid = "Pedro"; //your WiFi Name
const char* password = "Azerty1*";  //Your Wifi Password

int relay1Pin = 4; //jaune
int relay2Pin = 0; //orange
int relay3Pin = 5; //vert
int relay4Pin = 16; //bleu
int value1 = HIGH;
int value2 = HIGH;
int value3 = HIGH;
int value4 = HIGH;
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);
  digitalWrite(relay3Pin, HIGH);
  digitalWrite(relay4Pin, HIGH);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  if (request.indexOf("/RELAY1=ON") != -1)  {
    digitalWrite(relay1Pin, LOW);
    value1 = LOW;
    Serial.println("RELAY1=ON");
  }
  if (request.indexOf("/RELAY1=OFF") != -1)  {
    digitalWrite(relay1Pin, HIGH);
    value1 = HIGH;
     Serial.println("RELAY1=OFF");
  }
  if (request.indexOf("/RELAY2=ON") != -1)  {
    digitalWrite(relay2Pin, LOW);
    value2 = LOW;
     Serial.println("RELAY2=ON");
  }
  if (request.indexOf("/RELAY2=OFF") != -1)  {
    digitalWrite(relay2Pin, HIGH);
    value2 = HIGH;
     Serial.println("RELAY2=OFF");
  }
  if (request.indexOf("/RELAY3=ON") != -1)  {
    digitalWrite(relay3Pin, LOW);
    value3 = LOW;
     Serial.println("RELAY3=ON");
  }
  if (request.indexOf("/RELAY3=OFF") != -1)  {
    digitalWrite(relay3Pin, HIGH);
    value3 = HIGH;
     Serial.println("RELAY3=OFF");
  }
  if (request.indexOf("/RELAY4=ON") != -1)  {
    digitalWrite(relay4Pin, LOW);
    value4 = LOW;
     Serial.println("RELAY4=ON");
  }
  if (request.indexOf("/RELAY4=OFF") != -1)  {
    digitalWrite(relay4Pin, HIGH);
    value4 = HIGH;
     Serial.println("RELAY4=OFF");
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("");
  client.println("");
  client.print("Relai 1 is : ");
  if (value1 == HIGH) {
    client.print("OFF  ");
  } else {
    client.print("ON   ");
  }  client.println("");
  client.println("<a href=""/RELAY1=ON"">ON</a>");
  client.println("<a href=""/RELAY1=OFF"">OFF</a>");
  client.println("<br />");
  client.print("Relai 2 is : ");
  if (value2 == HIGH) {
    client.print("OFF  ");
  } else {
    client.print("ON   ");
  }  client.println("");
  client.println("<a href=""/RELAY2=ON"">ON</a>");
  client.println("<a href=""/RELAY2=OFF"">OFF</a>");
  client.println("<br />");
  client.print("Relai 3 is : ");
  if (value3 == HIGH) {
    client.print("OFF  ");
  } else {
    client.print("ON   ");
  }  client.println("");
  client.println("<a href=""/RELAY3=ON"">ON</a>");
  client.println("<a href=""/RELAY3=OFF"">OFF</a>");
  client.println("<br />");
  client.print("Relai 4 is : ");
  if (value4 == HIGH) {
    client.print("OFF  ");
  } else {
    client.print("ON   ");
  }  client.println("");
  client.println("<a href=""/RELAY4=ON"">ON</a>");
  client.println("<a href=""/RELAY4=OFF"">OFF</a>");
  client.println("<br />");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
//code copied from link
//https://www.instructables.com/id/Getting-Started-With-ESP8266LiLon-NodeMCU-V3Flashi/
