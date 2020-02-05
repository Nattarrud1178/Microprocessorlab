int button;
int clk_pin = 13; //SHCP
int latch_pin = 10; //STCP
int data_pin = 11; //DS
void setup(){
 pinMode(clk_pin,OUTPUT);
 pinMode(latch_pin,OUTPUT);
 pinMode(data_pin,OUTPUT);
 pinMode(A0,INPUT);
  Serial.begin(9600);
}
void loop(){
  button = analogRead(A0);
  Serial.println(button);
  for(int i = 0 ; i < 16 ; i++){
    digitalWrite(latch_pin,LOW);
    if(button <= 1000){
    digitalWrite(data_pin,HIGH);
    }
  }
}
