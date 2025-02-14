#define led A2

int shelf=0;
int a;

void setup() {
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {

  digitalWrite(led, LOW);
  pinMode(led,INPUT);

  a=readData()-shelf;
  pinMode(led,OUTPUT);

  if (a>220) {
    digitalWrite(led,LOW);
    shelf=0;
  } else{
    digitalWrite(led,HIGH);
    shelf=180;
  }

  delay(2000);
  }
int readData() {
  int sum=0;

  for (int i=0;i<5;i++) analogRead(led);

  for (int i=0;i<10;i++) {
    sum+=analogRead(led);
    delay(10);
}
}