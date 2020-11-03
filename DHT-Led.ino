#include "DHT.h"
#define led1 D0
#define led2 D1
#define kakiDHT D3
#define tipeDHT DHT11

DHT ambil(kakiDHT,tipeDHT);
const char* ssid = "parashitteam";
const char* password = "12345678";


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  ambil.begin();
}

// the loop function runs over and over again forever
void loop() {
//  blink();
  ambilVariable();
}

void blink() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)                    // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)                     // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                  // wait for a second
}


void ambilVariable(){
  float suhu = ambil.readTemperature();
  Serial.print("SUHU = ");
  
  
  if(suhu) {
  Serial.println(suhu);
  Serial.println("LED PUTIH MENYALA");
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(2000);
  }

  float lembab = ambil.readHumidity();
  Serial.print("KELEMBABAN = ");
  
  
  if (lembab) {
  Serial.println(lembab);
  Serial.println("LED HIJAU MENYALA");
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  delay(2000);
  }
}
//void koneksi(){
//  Serial.println("Menyambungkan");
//  delay(1000);
//  Serial.println("Tersambung");
//  delay(2000);
//}
