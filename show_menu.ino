char show_menu(void) // Change the value of 'num_of_menu_opt' definition in the top side of this program for any kind of addition of one or more menu option
{
  char ch;
  Serial.println("1. Manual");
  Serial.println("2. Auto");
  Serial.println("3. Except Dip");
  do{
    //ch = get_keypad(); ?
  }while(!(ch == '1' || ch == '2' || ch == '3'));

  return ch;
}
