#include <SoftwareSerial.h>



#define trigPin 9


#define echoPin 10


#define piezoPin 8


SoftwareSerial mySerial(2, 3); 


int normalDistance;


boolean triggered = false;


long duration, distance;


void setup()


{


mySerial.begin(9600); //serial monitor


Serial.begin (9600);


delay(100);


pinMode(trigPin, OUTPUT);


pinMode(echoPin, INPUT);


pinMode(piezoPin, OUTPUT);


digitalWrite(piezoPin, HIGH);


long duration, distance;


while (millis() < 5000)


{


digitalWrite(piezoPin, HIGH);


digitalWrite(trigPin, LOW);


delayMicroseconds(20);


digitalWrite(trigPin, HIGH);


delayMicroseconds(100);


digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;


normalDistance = distance;


Serial.print("Distance: ");


Serial.println(distance);


digitalWrite(piezoPin, LOW);


} }


void loop()


{


digitalWrite(trigPin, LOW);


delayMicroseconds(2);


digitalWrite(trigPin, HIGH);


delayMicroseconds(10);


digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;


Serial.print("Distance: ");


Serial.println(distance);


if (distance < normalDistance+5)


{


triggered = true;


}


else


{


triggered = false;


}


if (triggered)


{


tone(piezoPin, 635);


delay(500);


tone(piezoPin, 912);


delay(250);


mySerial.println("AT+CMGF=1");




delay(1000);


mySerial.println("AT+CMGS=\"+919994521347\"\r"); 




delay(1000);


mySerial.println("alert!!!!"); 



delay(100);


mySerial.println((char)26);



delay(1000);

}}
