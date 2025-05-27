#define led 2
unsigned long int tempo_led=0;
bool flag1_led=true;
bool flag2_led=false;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  tempo_led=millis();
}

void loop(){
  
  if(tempo_led+1000<=millis()){    //BLINK
    tempo_led=millis();
    flag2_led=true;
    Serial.println("a");
  }
  if(flag2_led){
    Serial.println("b");
    if(flag1_led){
      flag1_led=false;
      digitalWrite(led, HIGH);
      flag2_led=false;
      Serial.println("c");
    }
    else{
      flag1_led=true;
      digitalWrite(led, LOW);
      flag2_led=false;
      Serial.println("d");
    }
  }
}
