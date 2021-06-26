/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/


#include <stdio.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int oneWireBus = 4;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  //display.setCursor(0,0);
  // Display static text
 // display.println("T=50");
 // display.setCursor(65,0);
  // Display static text
  //display.println("Ta=50");
 // display.setCursor(0,18);
  // Display static text
 // display.println("D=20");
 // display.setCursor(65,18);
  // Display static text
//  display.println("Da=20");
//display.display(); 
}
int x;
int y[126];
int cont = 0;
char buffer[126];
void loop() {
  display.clearDisplay();
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  sprintf (buffer, "%.2f", temperatureC);
  Serial.print(temperatureC);
  Serial.println("ºC");
  display.setCursor(20,13);
  display.print(buffer);
  display.print(" ");
  display.cp437(true);
  display.write(167);
  display.println("C");
  display.display(); 
  

  delay(100);
}
