void x_axis(int n)
{
  int count = 0;
  if(n>0){
    digitalWrite(dir_x, HIGH);
  }
  else
    digitalWrite(dir_x, LOW);
  n = abs(n);
  for(count=0; count<n; count++){
    digitalWrite(puls_x, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_x, LOW);
    delayMicroseconds(700);
  }
}
