#include <ThreeWire.h>
#include <RtcDS1302.h> 
ThreeWire myWire(4,5,2); // IO, SCLK, CE 
RtcDS1302<ThreeWire> Rtc(myWire); 

void printDateTime(const RtcDateTime& dt){ 
// Serial.print(dt.Year(), DEC); 
// Serial.print('/'); 
// Serial.print(dt.Month(), DEC); 
// Serial.print('/'); 
// Serial.print(dt.Day(), DEC); 
// Serial.print(' '); 
// Serial.print(dt.Hour(), DEC); 
// Serial.print(':'); 
// Serial.print(dt.Minute(), DEC); 
// Serial.print(':'); 
// Serial.print(dt.Second(), DEC); 
// Serial.println(); 
// Serial.print("Total Seconds since 1/1/2000 : "); 
 Serial.print(dt.TotalSeconds()); 
 Serial.println();
}


RtcDateTime start; 

void setup() { 
 pinMode(9, HIGH);
  pinMode(8, HIGH);
  digitalWrite(8, LOW);
  
 Serial.begin(9600); 
 Rtc.Begin(); 
 RtcDateTime setting_time(2020,2,2,23,31,10); 
 // year, month, dayOfMonth, hour, minute, second 
 printDateTime(setting_time); 
 //Try to comment This line 
 Rtc.SetDateTime(setting_time); 

 
 start = Rtc.GetDateTime().TotalSeconds();
 Serial.print("Ready...");
 Serial.print("Start");
 Serial.println();
} 

void loop() { 
 RtcDateTime now = Rtc.GetDateTime(); 

 auto current = now.TotalSeconds();
 
 if(current - start <= (60*2)) {
  printDateTime(now);

  digitalWrite(9, current % 2);
 }
 else {
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  Serial.print("Stop");
 }
 
 delay(500); 
}
