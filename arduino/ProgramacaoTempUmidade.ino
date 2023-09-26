#include "DHT.h"
#define dht_type DHT11
int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  dht_1.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  float umidade = dht_1.readHumidity();
  float temperatura = dht_1.readTemperatura();
  if (isnan(temperatura) or isnan(umidade))
  {
    Serial.println("Erro ao ler o DHT")
  }
  else{
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %");
    Serial.print(" Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");
  }
  delay(500);
}
