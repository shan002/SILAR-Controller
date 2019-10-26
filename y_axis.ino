void y_axis(int n)
{
  int count = 0;
  if(n>0){
    digitalWrite(dir_y, HIGH);
  }
  else
    digitalWrite(dir_y, LOW);
  n = abs(n);
  for(count=0; count<n; count++){
    digitalWrite(puls_y, HIGH);
    delayMicroseconds(10);
    digitalWrite(puls_y, LOW);
    delayMicroseconds(600);
  }
}
