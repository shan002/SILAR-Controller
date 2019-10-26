void settings(void)   // Change the value of 'num_of_settings_opt' definition in the top side of this program for any kind of addition of one or more settings option
{
  char ch;
  Serial.println("Dip Speed: ");
  Serial.println("Dip Time: ");
  Serial.println("Dip Order: ");
  Serial.println("Repetition: ");
  lcd.setCursor(0,0);
  lcd.print("Dip Speed: ");
  lcd.setCursor(0,1);
  lcd.print("Dip Time: ");
  lcd.setCursor(0,2);
  lcd.print("Dip Order: ");
  lcd.setCursor(0,3);
  lcd.print("Repetition: ");
  lcd.setCursor(19,index-1);
  lcd.write(3);
  do{
    ch = KEY;
    if(ch == 'C')
      return;
    if(ch == 'A' || ch == 'B'){
      if(ch == 'A'){
        if(index>1)
          index--;
      }
      if(ch == 'B'){
        if(index<4)
          index++;
      }
//    lcd.write('\0');
      lcd.setCursor(19,pre_index-1);
      lcd.print(' ');
      lcd.setCursor(19,index-1);
      lcd.write(3);
      pre_index = index;
    }
  }while(ch != 'D');
//  Serial.println(index);
  if(index == 1){
    // take input dip speed as an array ?
    // store this dip speed in the 'total_settings' 2D array
  }
  else if(index == 2){
    // take input dip time as an array ?
    // store this dip time in the 'total_settings' 2D array
  }
  else if(index == 3){
    dis_inp(2, 11, 14);
    strcpy(total_settings[0], inp_ara);
    settings();
  }
  else if(index == 4){
    dis_inp(3, 12, 17);
    strcpy(total_settings[1], inp_ara);
    settings();
  }
}
