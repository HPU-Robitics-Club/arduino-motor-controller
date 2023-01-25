int pwm1 = 3;
int dir1 = 2;
int pwm2 = 5;
int dir2 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm1, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir2, OUTPUT);
  
  Serial.begin(115200);
  digitalWrite(pwm1, 0);
  digitalWrite(pwm2, 0);
} 

void loop() {
  // Wait until the new commands are available from serial
  while (!Serial.available());
  // Parses the serial command
  String command = Serial.readStringUntil('|');
  String leftMotorCommand = command.substring(0, 2);
  String leftCommandValue = command.substring(2, 5);
  String rightMotorCommand = command.substring(5, 7);
  String rightCommandValue = command.substring(7, 10);

  int leftMotor = leftCommandValue.toInt();
  int rightMotor = rightCommandValue.toInt();
  // Writes to left motors
  if (leftMotorCommand == "wf") {
    digitalWrite(dir1, HIGH);
  } else {
    digitalWrite(dir1, LOW);
  } 
  analogWrite(pwm1, leftMotor);

  // Writes to Right motors
  if (rightMotorCommand == "wf") {
    digitalWrite(dir2, HIGH);
  } else {
    digitalWrite(dir2, LOW);
  }
  analogWrite(pwm2, rightMotor);
}
