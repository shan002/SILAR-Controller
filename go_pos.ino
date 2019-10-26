void go_pos(char *order, char *times)
{
  int new_pos, old_pos=0, step_no,m;
  long int t=0, mul=0;
  for(int i=0; times[i]; i++){
    t = t*10+times[i]-'0';
    mul++;
  }
  Serial.println("Now Printing");
  Serial.print(total_settings[0]);
  Serial.print("\t");
  Serial.println(total_settings[1]);
//  Serial.println(total_settings[0]);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Operation in process");
  lcd.setCursor(4,2);
  lcd.print("Initializing...");
  go_init();
  lcd.setCursor(4,2);
  lcd.print("             ");
  lcd.setCursor(0,1);
  lcd.print("Sequence: ");
  lcd.print(order);
  time1 = micros();
  

  for(int j=0; j<t; j++){
    for(int i=0; order[i]; i++){
//    Serial.print(order[i]);
//    Serial.print("\t");
      new_pos = order[i] - '0';
      step_no = new_pos - old_pos;
//    Serial.println(step_no);
      x_axis(step_no * pos_dis);
      lcd.setCursor(0,2);
      lcd.print("Current Position: ");
      lcd.print(new_pos);
      delay(500); /// dip_time
      y_bottom(-1);
      delay(1000);
      y_axis(-y_ref);
      old_pos = new_pos;
      delay(500); /// retrieval time
    }
  }
  time2 = micros();
}
