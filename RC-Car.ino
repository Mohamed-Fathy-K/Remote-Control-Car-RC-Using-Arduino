#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define enA 5
#define enB 6

int motorSpeed = 200;

char command;

void forward();
void back();
void right();
void left();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)
  {
    command = Serial.read();
    stop();
    
    switch(command)
    {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        left();
        break;
      case 'I':
        right();
        break;
    }
  }

}

void right()
{
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void back()
{
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void forward()
{
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void left()
{
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void stop()
{
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
