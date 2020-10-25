#include <Adafruit_Sensor.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A1 
#define DHTTYPE DHT11

// 1) pino 1 do sensor (esquerda) ao +5V
// 2) pino 2 do sensor ao pino de dados definido em seu Arduino
// 3) pino 4 do sensor ao GND
// 4) o resistor de 10K entre pin 2 (dados) 
// 5) ao pino 1 (VCC) do sensor

DHT dht(DHTPIN, DHTTYPE);
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("DHT");
    dht.begin();
}
 
void loop() 
{
    
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    if (isnan(t) || isnan(h)) 
    {
        Serial.println("Failed to read from DHT");
    } 
    else 
    {
        Serial.print("Umidade: ");
        Serial.print(h);
        Serial.print(" %t");
        Serial.print("Temperatura: ");
        Serial.print(t);
        Serial.println(" *C");
    }
}