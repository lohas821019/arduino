void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  if xValue < 400
    x_command

  elif xValue >800

  else :
  // dont move

  if yValue  < 400
    y_command

  elif yValue  >800

  else :
  // dont move

  if (xcommand & COMMAND_LEFT) {
    Serial.println("COMMAND LEFT");
    // TODO: add your task here
    digitalwrite
    delay(xValue)
  }

  if (xcommand & COMMAND_RIGHT) {
    Serial.println("COMMAND RIGHT");
    // TODO: add your task here
  }

  if (ycommand & COMMAND_UP) {
    Serial.println("COMMAND UP");
    // TODO: add your task here
  }

  if (ycommand & COMMAND_DOWN) {
    Serial.println("COMMAND DOWN");
    // TODO: add your task here
  
}
