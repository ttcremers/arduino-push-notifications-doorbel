
const int LEDPIN = 13; // Visual confirmation
const int BELLPIN = 8; // Pull-up!

// Setup pin's
void setup() {
  // Set a nice baud rate
  Serial.begin(9600);
  
  // We can keep things really simple by 
  // using the internal pull-up resistor 
  // of the ATmega. I didn't so this is 
  // commented
  // pinMode(13, INPUT_PULLUP);
  
  pinMode(LEDPIN, OUTPUT);
  pinMode(BELLPIN, INPUT);
  digitalWrite(LEDPIN, LOW);
}

boolean inbel = false; 
void loop() {
  
  // We're using a pull up resistor so we're waiting for low on the pin
  if (digitalRead(BELLPIN) == LOW) {
    
    // Most radio doorbells switch for seconds on end 
    // to prevent another notification when we enter 
    // the loop again we track with `inbel` if the board
    // circuit is still low. (Incidently this will prevent
    // multiple messages for people with ichy trigger fingers)
    if ( !inbel ) {
      inbel = true;
      Serial.println(1); // DING DONG write `1` on serial 
    }
    digitalWrite(LEDPIN, HIGH); // Visual confirmation
    
  } else {
    // Check if we're going back high from a previous 
    // doorbell cycle.
    if ( inbel ) {
      inbel = false; 
    }
    digitalWrite(LEDPIN, LOW);
  }
  
  delay(5); // Play nice
}
