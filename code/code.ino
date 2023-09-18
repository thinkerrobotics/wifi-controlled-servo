#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "your_template_id_here"
#define BLYNK_DEVICE_NAME "your_device_name_here"
#define BLYNK_AUTH_TOKEN "your_auth_token_here"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "your_wifi_ssid_here";
char pass[] = "your_wifi_password_here";

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
BlynkTimer timer; 

BLYNK_WRITE(V1)
{   
  int value = param.asInt(); // Get value as integer
  myservo.write(value);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  myservo.attach(2); // Attach the servo to pin 2
}

void loop()
{
  Blynk.run();
  timer.run();
}
