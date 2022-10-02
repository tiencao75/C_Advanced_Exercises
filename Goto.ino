
int button1 = A1;
int button2 = A2;
int led[] = {0,1,2};
typedef enum{BTN_LINKLED,
             BTN_SANGDUOI,
             BTN_TAT}Nut_Nhan;

void setup() {
  for (int i=0; i < (sizeof(led)); i++){
  pinMode(led[i], OUTPUT); 
  }
  pinMode(button1,INPUT);
  pinMode(button2,INPUT); 
}

void Blinkled() {
  for (int i=0; i < i < (sizeof(led)); i++){
  digitalWrite(led[i], HIGH); 
  }
  Delay10ms_Check(500);
  for (int i=0; i < (sizeof(led)); i++){
  digitalWrite(led[i], LOW); 
  }
}
//------------------------
void Sangduoi() {

  for (int i=0; i < (sizeof(led)); i++){
  digitalWrite(led[i], HIGH); 
  Delay10ms_Check(500);
  digitalWrite(led[i], LOW); 
  }
}
//------------------------
Nut_Nhan ButtonSangduoi(){
  if ( digitalRead(button2) == 1)
  {
    return BTN_SANGDUOI;
  }
}
//------------------------
Nut_Nhan ButtonBlinkled(){
  if ( digitalRead(button1) == 1)
  {
    return BTN_LINKLED;
  }
}
//------------------------
void Tat(){
for (int i=0; i < (sizeof(led)); i++){
  digitalWrite(led[i], LOW); 
  }
}
//------------------------
int Delay10ms_Check(int adelay){
  int mdelay = adelay/10;
  for( int i = 0; i < mdelay; i++){
   Nut_Nhan btn;
   btn = ButtonSangduoi();
   btn = ButtonBlinkled();
    switch (btn)
    {
      case BTN_LINKLED:
      Blinkled();
      break ;
      case BTN_SANGDUOI:
      Sangduoi();
      break ;
      case BTN_TAT:
      Tat();
      break ;
    }
     delay(10);
  }
}
//------------------------

void loop() {   
  Delay10ms_Check(100);  
}
