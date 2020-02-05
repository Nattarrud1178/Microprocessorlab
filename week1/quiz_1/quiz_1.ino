int forward,backward;
void setup()
{
  DDRD=0b11111111;
}

void loop()
{
  PORTD=0b00000001;
  forward =0;
  backward = 0;
  while(forward<8){
    PORTD=0b00000001<<forward;
    forward++;
    delay(500);
  }
  while(backward<8){
    PORTD=0b10000000>>backward;
    backward++;
    delay(500);
  }
  
}
