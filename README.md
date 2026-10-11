# Arduino Stream Deck

## Overview

This project is a custom-built Stream Deck using an **Arduino Uno**, five push buttons and five different colour LEDs. It allows users to execute common multi-button Windows shortcuts and media controls through physical button presses.

The Arduino communicates with a Python script running on the computer through serial communication. The Python script interprets the commands received and executes the corresponding keyboard shortcuts.

The project also supports **multi-click functionality**, allowing individual buttons to perform different actions depending on how many times they are pressed.

## Features

- Five programmable physical buttons.
- Five LEDs providing visual feedback when buttons are pressed.
- Single, double, and triple click functionality.
- Media playback controls.
- Audio output switching shortcuts.
- Screenshot and screen-snipping shortcuts.
- Windows desktop shortcut.
- Serial communication between Arduino and Python.

## Hardware Requirements

- Arduino Uno
- 5 × Push buttons
- 5 × LEDs
- 5 × resistors for LEDs
- Breadboard
- Jumper wires
- USB cable

## Pin Configuration

The Arduino uses the following digital pins:

| Button | Input Pin | LED Pin |
|---|---|---|
| Button 1 | D13 | D2 |
| Button 2 | D12 | D3 |
| Button 3 | D11 | D4 |
| Button 4 | D10 | D5 |
| Button 5 | D9 | D6 |

Buttons use `INPUT_PULLUP`, meaning they are normally HIGH and become LOW when pressed.

Each LED turns on when its corresponding button is pressed and turns off when released.

## Button Functions

### Button 1 — Media Controls

| Clicks | Action |
|---|---|
| Single click | Play / Pause |
| Double click | Skip track |
| Triple click | Previous track |

### Button 2 — Audio Output

| Clicks | Action |
|---|---|
| Single click | Headphones |
| Double click | Speakers |
| Triple click | No assigned action |

### Buttons 3–5 — Windows Shortcuts

| Button | Action | Shortcut |
|---|---|---|
| Button 3 | Screenshot | Alt + Print Screen |
| Button 4 | Snipping Tool | Win + Shift + S |
| Button 5 | Show Desktop | Win + D |

The exact keyboard shortcuts are handled by the accompanying Python script.

## How It Works

### 1. Button Detection

The Arduino continuously monitors the state of each button using digital input pins.

When a button changes from HIGH to LOW, the Arduino detects a button press and activates the corresponding LED.

### 2. Multi-Click Detection

The first two buttons support multiple actions through a click-counting system.

A **400 ms click window** is used to determine whether the user has performed a single, double, or triple click with the help of Button Debouncing.

Once this period expires, the Arduino sends the appropriate command through serial communication.

### 3. Serial Communication

The Arduino communicates with the computer at a baud rate of **9600**.

Depending on the button pressed, the Arduino sends one of the following commands:

```text
PAUSE
SKIP
PREVIOUS
HEADPHONES
SPEAKERS
SCREENSHOT
SNIP
WIN+D
```

### 4. Python Integration

A Python script running on the computer listens for incoming serial commands.

When a recognised command is received, the script executes the corresponding Windows keyboard shortcut.

This allows the Arduino to function as a physical shortcut controller without requiring additional keyboard hardware.

## Software Requirements

- Arduino IDE or PlatformIO
- Python 3
- PySerial library
- A Python keyboard automation library
- Windows operating system

## Setup

1. Connect the buttons and LEDs to the Arduino using the pin configuration above.
2. Upload the Arduino firmware using Arduino IDE or PlatformIO.
3. Install the required Python libraries.
4. Connect the Arduino to the computer using USB.
5. Configure the Python script to use the correct serial port.
6. Run the Python script.
7. Use the physical buttons to control Windows functions.

## Future Improvements

Potential improvements include:

- Adding more programmable buttons that connect to streaming services (OBS, StreamLabs, Twitch).
- Creating a graphical interface for configuring shortcuts.
- Adding support for custom applications and macros.
- Adding a display to show assigned button functions.

## Conclusion

The original idea behind this project was to create a simple device that could perform shortcuts, such as capturing clips while streaming, similar to a commercial <Elgato Stream Deck>[https://www.elgato.com/uk/en/p/stream-deck-scissor-keys]. The intended functionality would depend on the streaming platform being used mentioned above.

However, as a starting point, I decided to develop the project into a Windows based macro pad, allowing multiple OS functions and shortcuts to be done through individual physical buttons.

By combining physical buttons, LED feedback, serial communication, and Python automation, this project demonstrates how an Arduino can be used to create an inexpensive and customisable alternative to commercial macro pads and Stream Deck devices.

This project also provides a foundation for future improvements and upgrades, including integration with streaming software, additional programmable functions, and more advanced button configurations.