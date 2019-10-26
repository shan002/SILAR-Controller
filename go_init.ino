void go_init(void)
{
//  digitalWrite(dir_y, LOW);
//  while(1){
//    digitalWrite(puls_y, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(puls_y, LOW);
//    delayMicroseconds(700);
//
//    u_state = digitalRead(limit_u);
//    if(u_state){
//      delay(2);
//      u_state = digitalRead(limit_u);
//      if(u_state)
//        break;
//    }
//  }
//  y_axis(total_ydis-y_ref);
  
  digitalWrite(dir_x, LOW);
  while(1){
    digitalWrite(puls_x, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_x, LOW);
    delayMicroseconds(700);

    b_state = digitalRead(limit_b);
    if(b_state){
      delay(2);
      b_state = digitalRead(limit_b);
      if(b_state)
        break;
    }
  }
  
  delay(1000);
}
