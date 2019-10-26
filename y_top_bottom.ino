void y_top(int len)
{
  digitalWrite(dir_y, LOW);
  for(int i=0; i<len; i++){
    u_state = digitalRead(limit_u);
    if(u_state){
      delay(2);
      u_state = digitalRead(limit_u);
      if(u_state)
        break;
    }
    delayMicroseconds(5);
    digitalWrite(puls_y, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_y, LOW);
    delayMicroseconds(700);
  }
}




void y_bottom(int dip_len)
{
  digitalWrite(dir_y, HIGH);
  if(dip_len == -1){
    while(1){
      delayMicroseconds(5);
      digitalWrite(puls_y, HIGH);
      delayMicroseconds(10);
      digitalWrite(puls_y, LOW);
      delayMicroseconds(700);

      n_state = digitalRead(limit_n);
    if(n_state){
      delay(2);
      n_state = digitalRead(limit_n);
      if(n_state)
        break;
    }
    }
  }
  else{
  for(int i=0; i<dip_len; i++){
    n_state = digitalRead(limit_n);
    if(n_state){
      delay(2);
      n_state = digitalRead(limit_n);
      if(n_state)
        break;
    }
    delayMicroseconds(5);
    digitalWrite(puls_y, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_y, LOW);
    delayMicroseconds(700);
  }
  }
}
