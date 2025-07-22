#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

WiFiClient client;
unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER;
const char * myWriteAPIKey = "YOUR_WRITE_API_KEY";

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define MQ_PIN A0 
#define BUZZER_PIN D5
int GAS_THRESHOLD = 400; 

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  WiFi.begin(ssid, password);
  displayText("Connecting WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  displayText("WiFi Connected");
  ThingSpeak.begin(client);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int gasValue = analogRead(MQ_PIN);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Methane Monitor");
  display.print("T:");
  display.print(temp);
  display.print("C H:");
  display.print(hum);
  display.println("%");
  display.print("Gas: ");
  display.println(gasValue);
  display.display();

  if (gasValue > GAS_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);
    ThingSpeak.setStatus("ALERT: Gas Levels Critical!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    ThingSpeak.setStatus("Normal");
  }

  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, hum);
  ThingSpeak.setField(3, gasValue);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  delay(20000); 
}

void displayText(String text) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(text);
  display.display();
}
