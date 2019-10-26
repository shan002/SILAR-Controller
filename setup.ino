void setup(){
  
  lcd.createChar(3, heart);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

 //////////////////////////////////
  pinMode(limit_b,INPUT);
  pinMode(limit_d,INPUT);
  pinMode(limit_u,INPUT);
  pinMode(limit_n,INPUT);
 ////////////////////////////////
  pinMode(puls_x,OUTPUT);
  pinMode(dir_x, OUTPUT);
  pinMode(puls_y,OUTPUT);
  pinMode(dir_y, OUTPUT);
  pinMode(ENx,OUTPUT);
  pinMode(ENy,OUTPUT);
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC, HIGH);
  pinMode(VCCx, OUTPUT);
  digitalWrite(VCCx, HIGH);
  pinMode(VCCy, OUTPUT);
  digitalWrite(VCCy, HIGH);
  digitalWrite(ENx,HIGH);
  digitalWrite(ENy,HIGH);
  
//  digitalWrite(dir_y, HIGH);
//  callibrate();
//  total_xdis = EEPROM.read(0);              // number of steps along the total x_axis
//  total_ydis = EEPROM.read(1);              // number of steps along the total x_axis
  total_xdis = 5368;
  total_ydis = 17479;
  pos_dis = total_xdis / (num_of_pos+1);  // number of steps between each positions
  y_ref = total_ydis/6;
//  Serial.println(pos_dis);
//  Serial.println(total_ydis);

}
