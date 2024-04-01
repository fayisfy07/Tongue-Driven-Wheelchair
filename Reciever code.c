#include <VirtualWire.h>

const int led_pin = 13;
int rightmotor1 = 2; // right side motor
int rightmotor2 = 3; // left side motor

int leftmotor1 = 7;
int leftmotor2 = 8;

const int receive_pin = 11;


void setup()
{
    delay(1000);
    Serial.begin(9600); // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR

    vw_set_rx_pin(receive_pin);

    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);  // Bits per sec

    vw_rx_start();       // Start the receiver PLL running

    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, LOW);
    

    pinMode(rightmotor1, OUTPUT);
    pinMode(rightmotor2, OUTPUT);
    pinMode(leftmotor1, OUTPUT);
    pinMode(leftmotor2, OUTPUT);
    
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
    int i;

     
    // Message with a good checksum received, dump it.
    Serial.print("Got: ");
    
    for (i = 0; i < buflen; i++)
    {
        char c = (buf[i]);
    if( c == 'z')
    {
    digitalWrite(led_pin , LOW);
    digitalWrite(rightmotor1 , LOW);
    digitalWrite(rightmotor2 , LOW);
    digitalWrite(leftmotor1 , LOW);
    digitalWrite(leftmotor2 , LOW);
            Serial.print(c);
        Serial.print(' ');
           
    } 
        if( c == 'j') // for right side
    {
       digitalWrite(rightmotor1 , LOW);
                digitalWrite(rightmotor2 , LOW);
            digitalWrite(led_pin, LOW);
                digitalWrite(leftmotor1 , HIGH);
                digitalWrite(leftmotor2 , LOW);
                             delay(200);
                digitalWrite(leftmotor1 , LOW);
                digitalWrite(leftmotor2 , LOW);
                delay(200);
              //  digitalWrite(leftmotor1 , HIGH);
              //  digitalWrite(leftmotor2 , LOW);
            Serial.print(c);
        Serial.print(' ');
           
    }

 if( c == 'h') // for straight
    {
      
            digitalWrite(led_pin, HIGH);
    digitalWrite(rightmotor1 , HIGH);
    digitalWrite(rightmotor2 , LOW);
       
    digitalWrite(leftmotor1 , HIGH);
    digitalWrite(leftmotor2 , LOW);
            Serial.print(c);
        Serial.print(' ');
           
    }  
     if( c == 'l') // for left
    {
                  digitalWrite(leftmotor1 , LOW);
                digitalWrite(leftmotor2 , LOW);
                 digitalWrite(rightmotor1 , HIGH);
                digitalWrite(rightmotor2 , LOW);
                delay(200);
                digitalWrite(rightmotor1 , LOW);
                digitalWrite(rightmotor2 , LOW);
                delay(200);
//                digitalWrite(leftmotor1 , LOW);
//                digitalWrite(leftmotor2 , HIGH);
            Serial.print(c);
        Serial.print(' ');
           
    }     
    if( c == 'm')
    {

            Serial.print(c);
        Serial.print(' ');
           
    } 

    }

    }
}