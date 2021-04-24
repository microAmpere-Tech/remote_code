#include <LoRa_STM32.h>

#define SS PA4
#define RST PB0
#define DI0 PA1
#define TX_P 17
#define BAND 433E6
#define ENCRYPT 0x78
#define button1 PB6
#define button2 PB7
#define button3 PB8
#define button4 PB9
#define led1 PB1
#define led2 PB10
#define led3 PB11
#define led4 PC14
// changes to be made:
/* 1. When ir on white off
 * 2. When white on ir off
 * 3. When reset pressed all off
 * 4. Shifting led numbers
 * 5. Reset shows blink of a light  
 */

int counter = 0;
const unsigned long eventInterval = 1500;

#define res                     0
#define whiteDimFlashing        1
#define whiteBrightFlashing     2
#define whiteDimSteady          3
#define whiteBrightSteady       4
#define irDimFlashing           5
#define irBrightFlashing        6 
#define irDimSteady             7
#define irBrightSteady          8


void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  LoRa.setTxPower(TX_P);
  LoRa.setSyncWord(ENCRYPT);

  LoRa.setPins(SS, RST, DI0);
  if (!LoRa.begin(BAND))
  {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button1),state1,FALLING);
  attachInterrupt(digitalPinToInterrupt(button2),state2,FALLING);
  attachInterrupt(digitalPinToInterrupt(button3),state3,FALLING);
  attachInterrupt(digitalPinToInterrupt(button4),state4,FALLING);
  
  delay(500);
}

void loop() {

}
void state1() {
  //noInterrupts();
  //detachInterrupt(digitalPinToInterrupt(button1));
  LoRa.beginPacket();
  LoRa.print("hello 1");
  Serial.println("hello 1");
  LoRa.endPacket();
  digitalWrite(led1,digitalRead(led1)^1);
  delayMicroseconds(1000000);
  //attachInterrupt(digitalPinToInterrupt(button1),state1,FALLING);
  //interrupts();
}
void state2() {
  //noInterrupts();
  //detachInterrupt(digitalPinToInterrupt(button2));
  LoRa.beginPacket();
  LoRa.print("hello 2");
  Serial.println("hello 2");
  LoRa.endPacket();
  digitalWrite(led2,digitalRead(led2)^1);
  delayMicroseconds(1000000);
  //attachInterrupt(digitalPinToInterrupt(button2),state2,FALLING);
  //interrupts();
}
void state3() {
  //noInterrupts();
  //detachInterrupt(digitalPinToInterrupt(button3));
  LoRa.beginPacket();
  LoRa.print("hello 3");
  Serial.println("hello 3");
  LoRa.endPacket();
  digitalWrite(led3,digitalRead(led3)^1);
  delayMicroseconds(1000000);
  //attachInterrupt(digitalPinToInterrupt(button3),state3,FALLING);
  //interrupts();
}
void state4() {
  //noInterrupts();
  //detachInterrupt(digitalPinToInterrupt(button4));
  LoRa.beginPacket();
  LoRa.print("hello 4");
  Serial.println("hello 4");
  LoRa.endPacket();
  digitalWrite(led4,digitalRead(led4)^1);
  delayMicroseconds(1000000);
  //attachInterrupt(digitalPinToInterrupt(button4),state4,FALLING);
  //interrupts();
}
