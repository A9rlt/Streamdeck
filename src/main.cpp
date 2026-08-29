#include <Arduino.h>


//          Relative Pins
const int buttonPins[] = {13, 12, 11, 10, 9};
const int ledPins[] = {2, 3, 4, 5, 6};

//          Buttons States
bool lastButtonState[] = {HIGH, HIGH, HIGH, HIGH, HIGH};

//          Buttons 1 2 Multi-click
bool state[] = {digitalRead(buttonPins[0]),
                digitalRead(buttonPins[1]) };


const char* buttonActions[] = {
  "SCREENSHOT",
  "SNIP",
  "WIN+D"
};


int clickCount[] = {0, 0, 0, 0, 0};
unsigned long lastClickTime[] = {0, 0, 0, 0, 0};
const unsigned long clickDelay = 400;


void setup()
{
    Serial.begin(9600);

    for (int i = 0; i < 5; i++)
    {
        pinMode(buttonPins[i], INPUT_PULLUP);
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop()
{
    //          Handles for button 0 and 1 multi-clicks
    for (int i = 0; i < 2; i++)
    {
        if (lastButtonState[i] == HIGH && state[i] == LOW)
        {
            digitalWrite(ledPins[i], HIGH);

            if (millis() - lastClickTime[i] <= clickDelay)
                clickCount[i]++;
            else
                clickCount[i] = 1;

            lastClickTime[i] = millis();
        }

        if (lastButtonState[i] == LOW && state[i] == HIGH)
        {
            digitalWrite(ledPins[i], LOW);
        }

        lastButtonState[i] = state[i];

        // Send command once the click window has expired
        if (clickCount[i] > 0 && millis() - lastClickTime[i] > clickDelay)
        {
            switch (clickCount[i])
            {
                case 1:
                    Serial.println(i == 0 ? "PAUSE" : "HEADPHONES");
                    break;

                case 2:
                    Serial.println(i == 0 ? "SKIP" : "SPEAKERS");
                    break;

                case 3:
                    Serial.println(i == 0 ? "PREVIOUS" : "N/A");
                    break;
            }

            clickCount[i] = 0;
        }
    }

    //          Buttons 2-4
    for (int i = 2; i < 5; i++)
    {
        bool state = digitalRead(buttonPins[i]);

        if (lastButtonState[i] == HIGH && state == LOW)
        {
            digitalWrite(ledPins[i], HIGH);
            Serial.println(buttonActions[i]);
        }

        if (lastButtonState[i] == LOW && state == HIGH)
        {
            digitalWrite(ledPins[i], LOW);
        }

        lastButtonState[i] = state;
    }
}