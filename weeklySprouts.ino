/*
  Project:     weeklySprouts
  Source:      http://github.com/pa3hcm/weeklySprouts
  Authors:     Ernest Neijenhuis
  Copyright:   (c) 2020 Ernest Neijenhuis PA3HCM
*/


/////////////////////////////////////////////////////////////////////////
// Constants

// Pin labels
const int P_PUMP   = 12; // Connected to relay module to activate pump
const int P_LED    = 13; // LED flashes to show it's still running

// Settings
const int INTERVAL = 6; // Pump interval time [hours]
const int RUNTIME  = 3; // Pump run time [seconds]


/////////////////////////////////////////////////////////////////////////
// setup() routine

void setup() {
  pinMode(P_PUMP, OUTPUT);
  pinMode(P_LED, OUTPUT);
  digitalWrite(P_PUMP, LOW);
  digitalWrite(P_LED, LOW);
}


/////////////////////////////////////////////////////////////////////////
// Libraries

// N/A


/////////////////////////////////////////////////////////////////////////
// Main loop() routine

void loop() {
  // Run the pump
  digitalWrite(P_PUMP, HIGH);
  delay(RUNTIME * 1000);
  digitalWrite(P_PUMP, LOW);
  // Wait for 6 hours
  int minutes = INTERVAL * 60;
  for(int minute=1; minute<=minutes; minute++) {
    for(int second=1; second<=60; second++) {
      if (second==10) {
        digitalWrite(P_LED, HIGH);
        delay(950);
        digitalWrite(P_LED, LOW);
        delay(50);
      } else {
        digitalWrite(P_LED, HIGH);
        delay(50);
        digitalWrite(P_LED, LOW);
        delay(950);
      }
    }
  }
}
