int forward,backward;
void setup()
{
  DDRD=0b11111111;
  pinMode(A1,INPUT);
//  Serial.begin(9600);
}

void loop()
{
//  Serial.println(analogRead(A1));
  forward =0;
  backward = 0;
  while(forward<8){
    PORTD=0b00000001<<forward;
    if(analogRead(A1)==1023){
    delay(500);
    forward++;
    }
  }
  while(backward<8){
    PORTD=0b10000000>>backward;
    if(analogRead(A1)==1023){
    delay(500);
    backward++;
    } 
  }
  
}
