#define EN_GATE 1
#define HAL_U 2
#define HAL_V 3
#define HAL_W 4
#define M_PWM 5
#define M_OC 6
#define OC_ADJ 7
#define IOUT_C A2
#define IOUT_B A3

int State = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  DDRB = B11111111; //Set Port B as OUTPUT
  pinMode(HAL_U, INPUT);
  pinMode(HAL_V, INPUT);
  pinMode(HAL_W, INPUT);
  pinMode(EN_GATE, OUTPUT);
  pinMode(M_PWM, OUTPUT);
  pinMode(M_OC, OUTPUT);
  pinMode(OC_ADJ, OUTPUT);
  pinMode(IOUT_C, INPUT);
  pinMode(IOUT_B, INPUT);
}

void loop() {
  digitalWrite(EN_GATE, HIGH);
  digitalWrite(M_PWM, LOW);
  digitalWrite(M_OC, HIGH); //OVC ON when LOW, OVC OFF when HIGH
  digitalWrite(OC_ADJ, HIGH);
  // put your main code here, to run repeatedly:
  int HAL_U_State = digitalRead(HAL_U);
  int HAL_V_State = digitalRead(HAL_V);
  int HAL_W_State = digitalRead(HAL_W);
  float IOUTC = analogRead(A2);
  float IOUTB = analogRead(A3);


//  Serial.print("U=");
//  Serial.println(HAL_U_State);
//  Serial.print("V=");
//  Serial.println(HAL_V_State);
//  Serial.print("W=");
//  Serial.println(HAL_W_State);
//  delay(1000);
  
  if(HAL_U_State == 1){
    if(HAL_V_State == 0){
      if(HAL_W_State == 0){
        PORTB = B00100010; // HB & LC (D9, D13)
//        Serial.print("State 4");
      }
    }
  }
  if(HAL_U_State == 1){
    if(HAL_V_State == 1){
      if(HAL_W_State == 0){
        PORTB = B00001010; // LA & HB (D11, D9)
//        Serial.print("State 6");
      }
    }
  }
  if(HAL_U_State == 0){
    if(HAL_V_State == 1){
      if(HAL_W_State == 0){
        PORTB = B00001100; // LA & HC (D11, D10)
//        Serial.print("State 2");
      }
    }
  }  
  if(HAL_U_State == 0){
    if(HAL_V_State == 1){
      if(HAL_W_State == 1){
        PORTB = B00010100; // LB & HC (D12, D10)
//        Serial.print("State 3");
      }
    }
  }
  if(HAL_U_State == 0){
    if(HAL_V_State == 0){
      if(HAL_W_State == 1){
        PORTB = B00010001; // HA & LB (D8, D12)
//        Serial.print("State 1");
      }
    }
  }
  if(HAL_U_State == 1){
    if(HAL_V_State == 0){
      if(HAL_W_State == 1){
        PORTB = B00100001; // HA & LC (D8, D13)
//        Serial.print("State 5");
      }
    }
  }
  Serial.print("Arus Fasa C =");
  Serial.print(IOUTC);
  Serial.print("Arus Fasa B =");
  Serial.print(IOUTB);

  


}
