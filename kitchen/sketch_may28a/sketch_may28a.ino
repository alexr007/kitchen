#define PORT_LED    LED_BUILTIN
#define PORT_SENSOR 2 // Input for HC-S501
#define SENSOR_DELAY 4000;
bool state;
int sensor;
int outcome;
unsigned long time;

// reads the PIR sensor value to variable sensor
void read_sensor() {
  sensor = digitalRead(PORT_SENSOR);
}

// sets LED according to variable outcome
void set_led() {
  digitalWrite(PORT_LED, outcome);
}

bool busy() {
  return millis()-time<SENSOR_DELAY;
}

void set_timer() {
  time=millis();
}

// makes decision based on sensor,timer, and state and sets the value for variable outcome 
void decision() {
  if (sensor==HIGH) { // we analyze only ON event
    set_timer();
    state = !state;
    outcome = state ? HIGH : LOW;
  }
}

void setup() {
  pinMode(PORT_LED, OUTPUT);
  pinMode(PORT_SENSOR, INPUT);
  digitalWrite(PORT_LED, LOW);
  time = millis();
  state = false;
}

void loop() {
    if (!busy()) {
        read_sensor();
        decision();
        set_led();
    }
}
