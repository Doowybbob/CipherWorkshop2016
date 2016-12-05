int led = 0; // init led to 0
int level = 1; // init level to 1

void setup() {
  //Start up the serial connection
  Serial.begin(9600);

  // Set our LED pins as OUTPUTS
  // we're using pin 8 as the first LED ---- pin 12 as the 5th LED
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  // Make sure all of the LEDs are off
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  // Tell the player that they are starting on Level 1
  Serial.println("Level 1");
}

void loop() {
  // go through all 5 pins and turn one of them on
  for (int i = 8; i < 13; i++){
    if (i == led + 8) { // led is a number between 0 and 4 (the one to turn on)
      digitalWrite(i, HIGH);
    }
    else {
      digitalWrite(i, LOW); // all of the other ones should be off
    }
  }

  delay(1000 / level); //delay for some amount of time

  if (Serial.available()) { // see if the user sent something
    Serial.readString(); // get the string
    if (led == 2) { // if we got data while the middle LED was lit up, move onto the next level
      level++; // incrememnt the level counter
      Serial.print("Level ");
      Serial.println(level); // tell the user what level they are on
      led = -1; // start back at the first led (set to -1 because the led counter is incrememnted later

      // play the level up sequence
      delay(1000);
      digitalWrite(10, LOW);
      delay(200);
      digitalWrite(10, HIGH);
      delay(200);
      digitalWrite(10, LOW);
      delay(200);
      digitalWrite(10, HIGH);
      delay(200);
      digitalWrite(10, LOW);
      
    }
    else { // if not, go back to level 1
      level = 1;
      led = -1;
      Serial.println("Level 1");
    }
  }

  
  // move onto the next led
  led++; // turn on the next LED
  led = led % 5; // loop back around to the first LED if we are at the last one
  
}

/*
  
  
  





 
 */
