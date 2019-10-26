void callibrate()
{
  b_state = digitalRead(limit_b);
  d_state = digitalRead(limit_d);
  u_state = digitalRead(limit_u);
  n_state = digitalRead(limit_n);
  Serial.println("Start");
  
  count[0] = count[1] = 0;

  digitalWrite(dir_y, HIGH);
  while(1){
    digitalWrite(puls_y, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_y, LOW);
    delayMicroseconds(600);
    n_state = digitalRead(limit_n);
    if(n_state){
      delay(2);
      n_state = digitalRead(limit_n);
      if(n_state)
        break;
    }
//    Serial.println(n);
  }

//  while(1);
  
  digitalWrite(dir_y, LOW);
  while(1){
//    show_limit();
    digitalWrite(puls_y, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_y, LOW);
    delayMicroseconds(600);
    count[1]++;
    
    u_state = digitalRead(limit_u);
    if(u_state){
      delay(2);
      u_state = digitalRead(limit_u);
      if(u_state)
        break;
    }
  }

  delay(1000);

  digitalWrite(dir_x, HIGH);
  while(1){
//    show_limit();
    digitalWrite(puls_x, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_x, LOW);
    delayMicroseconds(700);

    d_state = digitalRead(limit_d);
    if(d_state){
      delay(2);
      d_state = digitalRead(limit_d);
      if(d_state)
        break;
    }
  }
  
  delay(1000);
  
  digitalWrite(dir_x, LOW);
  while(1){
//    show_limit();
    digitalWrite(puls_x, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_x, LOW);
    delayMicroseconds(700);
    count[0]++;

    b_state = digitalRead(limit_b);
    if(b_state){
      delay(2);
      b_state = digitalRead(limit_b);
      if(b_state)
        break;
    }
  }

  delay(1000);
  Serial.print(count[0]);
  Serial.print('\t');
  Serial.println(count[1]);
  Serial.println("Finish");
  EEPROM.write(0,count[0]);
  EEPROM.write(1,count[1]);

//  while(1);
}
