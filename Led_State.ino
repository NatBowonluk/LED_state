#define _ledButton           2  //DO2 in PCB 
#define _connect            27  //Connect in PCB =>Active Low
#define _charge             14  //Charge in PCB  =>Active Low
#define _error              12  //Error in PCB   =>Active Low
#define _rgbR               33
#define _rgbG               25
#define _rgbB               26
#define pwm_frequency     5000
#define pwm_resolution       8   //Bit resolution 2^8 = 256
#define redChannel           0
#define greenChannel         1
#define blueChannel          2

void turquoise_stateA();
void yellow_stateB();
void blue_stateC();
void red_stateError();

void setup() {
  Serial.begin(115200);
  Serial.println("Start");

  //pinMode(_ledButton, OUTPUT);
  pinMode(_connect, OUTPUT);
  pinMode(_charge, OUTPUT);
  pinMode(_error, OUTPUT);

  pinMode(_rgbR, OUTPUT);
  pinMode(_rgbG, OUTPUT);
  pinMode(_rgbB, OUTPUT);

  //digitalWrite(_ledButton, HIGH);

  //PWM properties to the PWM channels
  ledcSetup(redChannel, pwm_frequency, pwm_resolution);
  ledcSetup(greenChannel, pwm_frequency, pwm_resolution);
  ledcSetup(blueChannel, pwm_frequency, pwm_resolution);

  //Attach the PWM channels to the corresponding GPIOs
  ledcAttachPin(_rgbR, redChannel);
  ledcAttachPin(_rgbG, greenChannel);
  ledcAttachPin(_rgbB, blueChannel);
}

void loop() {
  turquoise_stateA();
  delay(1000);
  yellow_stateB();
  delay(1000);
  blue_stateC();
  delay(1000);
  red_stateError();
  delay(1000);
}

void turquoise_stateA() {
  ledcWrite(redChannel, 9);
  ledcWrite(greenChannel, 235);
  ledcWrite(blueChannel, 238);
  digitalWrite(_connect, HIGH);
  digitalWrite(_charge, HIGH);
  digitalWrite(_error, HIGH);
}


void yellow_stateB() {
  ledcWrite(redChannel, 255);
  ledcWrite(greenChannel, 255);
  ledcWrite(blueChannel, 0);
  digitalWrite(_connect, LOW);
  digitalWrite(_charge, LOW);
  digitalWrite(_error, HIGH);

}

void blue_stateC() {
  ledcWrite(redChannel, 0);
  ledcWrite(greenChannel, 0);
  ledcWrite(blueChannel, 255);
  digitalWrite(_connect, HIGH);
  digitalWrite(_charge, LOW);
  digitalWrite(_error, HIGH);
}

void red_stateError() {
  ledcWrite(redChannel, 255);
  ledcWrite(greenChannel, 0);
  ledcWrite(blueChannel, 0);
  digitalWrite(_connect, HIGH);
  digitalWrite(_charge, HIGH);
  digitalWrite(_error, LOW);
}
