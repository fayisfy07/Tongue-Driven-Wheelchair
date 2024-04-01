#include <VirtualWire.h>
//provides features to send short messages, without addressing over wireless using ASK
const int led_pin = 11;  //integer variable that is not allowed to change
const int transmit_pin = 12;   //

const int transmit_en_pin = 3;

 
char msg[7] = {'h'};
char msg1[7] = {'j'};
char msg2[7] = {'l'};
char msg3[7] = {'m'};
char msg8[7] = {'z'};


int sensor1 = A0; // staight
int sensor2 = A1; // right 

int sensor3 = A2; // left 
int sensor4 = A3; // stop

// variable for sensors

int sdata1 = 0; //sensor 1 data
int sdata2 = 0; 
int sdata3 = 0;
int sdata4 = 0; 




void setup()
{
  Serial.begin(9600);//initialize the communication between the arduino board and the device via a seiral port. baud rate of the serial communication to 9600
    //bits per sec, normal used baud rate   
    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);

    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
       pinMode(sensor3, INPUT);
    pinMode(sensor4, INPUT);
    vw_setup(2000);       // Bits per sec
    
}

byte count = 1;

void loop()
{

  sdata1 = analogRead(sensor1);
    sdata2 = analogRead(sensor2);
      sdata3 = analogRead(sensor3);
        sdata4 = analogRead(sensor4);
  Serial.println(sdata1);
   Serial.println(sdata2);
    Serial.println(sdata3);
     Serial.println(sdata4);
  
//delay(1000);
//Serial.println("************************************");
 // msg[6] = count;
 if(sdata1 < 500 )
 {
  
  vw_send((uint8_t *)msg, 1); //  sensor values, unsigned char
  vw_wait_tx(); // Wait until the whole message is gone
  Serial.println("sensor1: straight:");
  delay(1000);

 }
 
  if( sdata2 < 500 )
 {
  
  vw_send((uint8_t *)msg1, 1); 
  vw_wait_tx(); 
  Serial.println("sensor2: right:");
  delay(1000);
 
 }   if(sdata3 < 500 )
 {
  
  vw_send((uint8_t *)msg2, 1); //  sensor values, unsigned char
  vw_wait_tx(); 
  Serial.println("sensor3: left:");
  delay(1000);

 }   if(sdata4 < 500 )
 {
  
  vw_send((uint8_t *)msg8, 1); 
  vw_wait_tx(); 
  Serial.println("sensor4: stop:");
  delay(1000);

 }    
   else 
delay(200);
}