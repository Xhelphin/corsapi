// Set up blinkt strip
#include <Adafruit_DotStar.h>
#include <SPI.h>
#define NUMPIXELS  8
#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar blinkt = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BGR);

// Define constants
#define forpixels for (int i = 0; i <= 7; i++)
const int led = 13;

// Define colours
const int cred[3] = {255, 0, 0};
const int cgreen[3] = {0, 255, 0};
const int cblue[3] = {0, 0, 255};
const int cwhite[3] = {255, 255, 255};
const int cmagenta[3] = {255, 0, 255};
const int cyellow[3] = {255, 255, 0};
const int ccyan[3] = {0, 255, 255};
const int corange[3] = {255, 75, 0};
const int cpink[3] = {255, 50, 50};
const int cpurple[3] = {255, 0, 150};
const int cwhitehalfbrightness[3] = {128, 128, 128};
const int cclear[3] = {0, 0, 0};

// Define animations
const int apulse1[8] = {0,0,0,1, 1,0,0,0};
const int apulse2[8] = {0,0,1,1, 1,1,0,0};
const int apulse3[8] = {0,1,1,1, 1,1,1,0};
const int apulse4[8] = {1,1,1,1, 1,1,1,1};
const int apulse5[8] = {0,1,1,1, 1,1,1,0};
const int apulse6[8] = {0,0,1,1, 1,1,0,0};
const int apulse7[8] = {0,0,0,1, 1,0,0,0};
const int apulse8[8] = {0,0,0,0, 0,0,0,0};

// Define global variables
int currentFunction = 0;
int pastFunction = -1;
int brightness = 255;
int currentFrame = 0;
bool reversed = false;
int currentColour = 0;
bool firstRun = true;
bool ledState = false;

// Run at startup
void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1);
#endif

  blinkt.begin();
  blinkt.setBrightness(brightness);
  blinkt.show();

  forpixels {
    blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
  }
  blinkt.show();
  delay(500);
  blinkt.clear();
  blinkt.show();

  Serial.begin(9600);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

// Loop forever
void loop() {
  // Toggle internal LED
  if (ledState) {
    digitalWrite(led, LOW);
    ledState = false;
  } else {
    digitalWrite(led, HIGH);
    ledState = true;
  }
  
  // Check for serial input
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    currentFunction = data.toInt();
  }

  // Check if function has changed and clear blinkt if it has
  if (currentFunction != pastFunction) {
    blinkt.clear();
    blinkt.show();
    pastFunction = currentFunction;
    currentFrame = 0;
    brightness = 255;
    blinkt.setBrightness(brightness);
    reversed = false;
    firstRun = true;
    currentColour = 0;
  }

  // Run through selected function
  /*
   * Functions (current and planned):
   * 0. Nothing - Done
   * 1. Red - Done
   * 2. Green - Done
   * 3. Blue - Done
   * 4. White - Done
   * 5. Magenta - Done
   * 6. Yellow - Done
   * 7. Cyan - Done
   * 8. Orange - Done
   * 9. Pink - Done
   * 10. Purple - Done
   * 11. White (50% brightness) - Done
   * 12. Flash colours - Done
   * 13. Rainbow gradient - Done
   * 14. Strobe - Done
   * 15. Strobe colours - Done
   * 16. Strobe red - Done
   * 17. Strobe green - Done
   * 18. Strobe blue - Done
   * 19. Strobe magenta - Done
   * 20. Strobe yellow - Done
   * 21. Strobe cyan - Done
   * 22. Strobe orange - Done
   * 23. Strobe pink - Done
   * 24. Strobe purple - Done
   * 25. Strobe white (50% brightness) - Done
   * 26. Hazard - Done
   * 27. Emergency - Done
   * 28. Pulse colours - Done
   * 29. Pulse white - Done
   * 30. Pulse red - Done
   * 31. Pulse green - Done
   * 32. Pulse blue - Done
   * 33. Pulse magenta - Done
   * 34. Pulse yellow - Done
   * 35. Pulse cyan - Done
   * 36. Pulse orange - Done
   * 37. Pulse pink - Done
   * 38. Pulse purple - Done
   * 39. Pulse white (50% brightness) - Done
   * 40. Fade colours - Done
   * 41. Fade white - Done
   * 42. Fade red - Done
   * 43. Fade green - Done
   * 44. Fade blue - Done
   * 45. Fade magenta - Done
   * 46. Fade yellow - Done
   * 47. Fade cyan - Done
   * 48. Fade orange - Done
   * 49. Fade pink - Done
   * 50. Fade purple - Done
   * 51. Fade white (50% brightness) - Done
   * 52. Run colours - Done
   * 53. Run white - Done
   * 54. Run red - Done
   * 55. Run green - Done
   * 56. Run blue - Done
   * 57. Run magenta - Done
   * 58. Run yellow - Done
   * 59. Run cyan - Done
   * 60. Run orange - Done
   * 61. Run pink - Done
   * 62. Run purple - Done
   * 63. Run white (50% brightness) - Done
   * 64. Scroll colours - Done
   */
  if (currentFunction == 0) {
    delay(100);
  } else if (currentFunction == 1) {
    forpixels {
      blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 2) {
    forpixels {
      blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 3) {
    forpixels {
      blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 4) {
    forpixels {
      blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 5) {
    forpixels {
      blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 6) {
    forpixels {
      blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 7) {
    forpixels {
      blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 8) {
    forpixels {
      blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 9) {
    forpixels {
      blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 10) {
    forpixels {
      blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 11) {
    forpixels {
      blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 12) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
      }
    } else if (currentFrame == 1) {
      forpixels {
        blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
      }
    } else if (currentFrame == 2) {
      forpixels {
        blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
      }
    } else if (currentFrame == 3) {
      forpixels {
        blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
      }
    }
    if (currentFrame == 3) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(500);
  } else if (currentFunction == 13) {
    if (currentColour == 0) {
      blinkt.setPixelColor(currentFrame, cred[0], cred[1], cred[2]);
    } else if (currentColour == 1) {
      blinkt.setPixelColor(currentFrame, cgreen[0], cgreen[1], cgreen[2]);
    } else if (currentColour == 2) {
      blinkt.setPixelColor(currentFrame, cblue[0], cblue[1], cblue[2]);
    }
    if (currentFrame == 7) {
      currentFrame = 0;
      if (currentColour == 2) {
        currentColour = 0;
      } else {
        currentColour++;
      }
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 14) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 15) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    } else if (currentFrame == 2) {
      forpixels {
        blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
      }
    } else if (currentFrame == 3) {
      blinkt.clear();
    } else if (currentFrame == 4) {
      forpixels {
        blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
      }
    } else if (currentFrame == 5) {
      blinkt.clear();
    } else if (currentFrame == 6) {
      forpixels {
        blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
      }
    } else if (currentFrame == 7) {
      blinkt.clear();
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 16) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 17) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 18) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 19) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 20) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 21) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 22) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 23) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 24) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 25) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    }
    if (currentFrame == 1) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 26) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 3) {
      blinkt.clear();
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 5) {
      blinkt.clear();
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 7) {
      blinkt.clear();
    } else if (currentFrame == 8) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 9) {
      blinkt.clear();
    } else if (currentFrame == 10) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 11) {
      blinkt.clear();
    } else if (currentFrame == 12) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 13) {
      blinkt.clear();
    } else if (currentFrame == 14) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    }
    if (currentFrame == 14) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  }  else if (currentFunction == 27) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 1) {
      blinkt.clear();
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 3) {
      blinkt.clear();
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 5) {
      blinkt.clear();
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 7) {
      blinkt.clear();
    } else if (currentFrame == 8) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 9) {
      blinkt.clear();
    } else if (currentFrame == 10) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 11) {
      blinkt.clear();
    } else if (currentFrame == 12) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 13) {
      blinkt.clear();
    } else if (currentFrame == 14) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    }
    if (currentFrame == 14) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 28) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 8) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 9) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 10) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 11) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 12) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 13) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 14) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 15) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 16) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 17) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 18) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 19) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 20) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 21) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 22) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 23) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 24) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 25) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 26) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 27) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 28) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 29) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 30) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 31) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    }
    if (currentFrame == 31) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 29) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 30) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 31) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 32) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 33) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 34) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 35) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 36) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 37) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 38) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 39) {
    if (currentFrame == 0) {
      forpixels {
        if (apulse1[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    } else if (currentFrame == 1) {
      forpixels {
        if (apulse2[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    } else if (currentFrame == 2) {
      forpixels {
        if (apulse3[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    } else if (currentFrame == 3) {
      forpixels {
        if (apulse4[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    } else if (currentFrame == 4) {
      forpixels {
        if (apulse5[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    } else if (currentFrame == 5) {
      forpixels {
        if (apulse6[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    } else if (currentFrame == 6) {
      forpixels {
        if (apulse7[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    } else if (currentFrame == 7) {
      forpixels {
        if (apulse8[i] == 0) {
          blinkt.setPixelColor(i, cclear[0], cclear[1], cclear[2]);
        } else {
          blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
        }
      }
    }
    if (currentFrame == 7) {
      currentFrame = 0;
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(100);
  } else if (currentFunction == 40) {
    if (currentFrame == 0) {
      forpixels {
        blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
      }
    } else if (currentFrame == 1) {
      forpixels {
        blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
      }
    } else if (currentFrame == 2) {
      forpixels {
        blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
      }
    } else if (currentFrame == 3) {
      forpixels {
        blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
      }
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
      if (currentFrame == 3) {
        currentFrame = 0;
      } else {
        currentFrame++;
      }
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 41) {
    forpixels {
      blinkt.setPixelColor(i, cwhite[0], cwhite[1], cwhite[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 42) {
    forpixels {
      blinkt.setPixelColor(i, cred[0], cred[1], cred[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 43) {
    forpixels {
      blinkt.setPixelColor(i, cgreen[0], cgreen[1], cgreen[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 44) {
    forpixels {
      blinkt.setPixelColor(i, cblue[0], cblue[1], cblue[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 45) {
    forpixels {
      blinkt.setPixelColor(i, cmagenta[0], cmagenta[1], cmagenta[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 46) {
    forpixels {
      blinkt.setPixelColor(i, cyellow[0], cyellow[1], cyellow[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 47) {
    forpixels {
      blinkt.setPixelColor(i, ccyan[0], ccyan[1], ccyan[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 48) {
    forpixels {
      blinkt.setPixelColor(i, corange[0], corange[1], corange[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 49) {
    forpixels {
      blinkt.setPixelColor(i, cpink[0], cpink[1], cpink[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 50) {
    forpixels {
      blinkt.setPixelColor(i, cpurple[0], cpurple[1], cpurple[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 51) {
    forpixels {
      blinkt.setPixelColor(i, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
    }
    if (brightness == 255) {
      reversed = true;
    } else if (brightness == 0) {
      reversed = false;
    }
    if (!reversed) {
      brightness+=5;
    } else {
      brightness+=-5;
    }
    blinkt.setBrightness(brightness);
    blinkt.show();
    delay(50);
  } else if (currentFunction == 52) {
    blinkt.clear();
    if (currentColour == 0) {
      blinkt.setPixelColor(currentFrame, cred[0], cred[1], cred[2]);
    } else if (currentColour == 1) {
      blinkt.setPixelColor(currentFrame, cgreen[0], cgreen[1], cgreen[2]);
    } else if (currentColour == 2) {
      blinkt.setPixelColor(currentFrame, cblue[0], cblue[1], cblue[2]);
    } else if (currentColour == 3) {
      blinkt.setPixelColor(currentFrame, cwhite[0], cwhite[1], cwhite[2]);
    }
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
      if (currentColour == 3) {
        currentColour = 0;
      } else {
        currentColour++;
      }
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 53) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cwhite[0], cwhite[1], cwhite[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 54) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cred[0], cred[1], cred[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 55) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cgreen[0], cgreen[1], cgreen[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 56) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cblue[0], cblue[1], cblue[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 57) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cmagenta[0], cmagenta[1], cmagenta[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 58) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cyellow[0], cyellow[1], cyellow[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 59) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, ccyan[0], ccyan[1], ccyan[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 60) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, corange[0], corange[1], corange[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 61) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cpink[0], cpink[1], cpink[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 62) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cpurple[0], cpurple[1], cpurple[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 63) {
    blinkt.clear();
    blinkt.setPixelColor(currentFrame, cwhitehalfbrightness[0], cwhitehalfbrightness[1], cwhitehalfbrightness[2]);
    if (currentFrame == 7) {
      reversed = true;
    } else if (currentFrame == 0) {
      reversed = false;
    }
    if (!reversed) {
      currentFrame++;
    } else {
      currentFrame--;
    }
    blinkt.show();
    delay(50);
  } else if (currentFunction == 64) {
    if (currentColour == 0) {
      blinkt.setPixelColor(currentFrame, cred[0], cred[1], cred[2]);
    } else if (currentColour == 1) {
      blinkt.setPixelColor(currentFrame, cgreen[0], cgreen[1], cgreen[2]);
    } else if (currentColour == 2) {
      blinkt.setPixelColor(currentFrame, cblue[0], cblue[1], cblue[2]);
    } else if (currentColour == 3) {
      blinkt.setPixelColor(currentFrame, cwhite[0], cwhite[1], cwhite[2]);
    }
    if (currentFrame == 7) {
      currentFrame = 0;
      if (currentColour == 3) {
        currentColour = 0;
      } else {
        currentColour++;
      }
    } else {
      currentFrame++;
    }
    blinkt.show();
    delay(50);
  } else {
    currentFunction = 0;
  }
}
