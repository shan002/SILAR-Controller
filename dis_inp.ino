void dis_inp(int row, int col1, int col2)
{
  char ch, i, j, temp;
  lcd.setCursor(col1, row);
  for(i=col1; i<=col2; i++)
    lcd.print(' ');
  
  lcd.setCursor(col1, row);
  i = 0;
  j = col1;
  do{
    do{
      ch = KEY;
    }while(!ch);
    if(ch != 'D'){
      if(ch == 'C'){
        if(i > 0)
          i--;
        if(j > col1)
          j--;
        lcd.setCursor(j, row);
        lcd.print(' ');
        lcd.setCursor(j, row);
      }
      else{
        if(j<=col2){
          inp_ara[i++] = ch;
          lcd.print(ch);
          j++;
        }
      }
    }
  }while(ch != 'D');
  
  inp_ara[i] = '\0';

//  Serial.print("In the ara: ");
//  Serial.println(inp_ara);
//  while(1);
}
