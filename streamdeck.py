import serial
import keyboard
import time


arduino = serial.Serial("COM3", 9600, timeout=1)

time.sleep(2) 

print("Waiting for shortcut type...")

while True:
    if arduino.in_waiting:
        command = arduino.readline().decode().strip()

        print("Received:", command)

        if command == "PAUSE":
            keyboard.press_and_release("play/pause media")

        elif command == "SKIP":
            keyboard.press_and_release("next track")

        elif command == "PREVIOUS":
            keyboard.press_and_release("previous track")
    
        elif command == "HEADPHONES":
            keyboard.press_and_release("windows+ctrl+v")
            time.sleep(1)
            keyboard.press_and_release("up")
            keyboard.press_and_release("enter")
            keyboard.press_and_release("esc")

        elif command == "SPEAKERS":
            keyboard.press_and_release("windows+ctrl+v")
            time.sleep(1)
            keyboard.press_and_release("down")
            keyboard.press_and_release("enter")
            keyboard.press_and_release("esc")

        elif command == "SCREENSHOT":
            keyboard.press("alt")
            keyboard.press_and_release("print screen")
            keyboard.release("alt")

        elif command == "SNIP":
            keyboard.press_and_release("windows+shift+s")

        elif command == "WIN+D":
            keyboard.press_and_release("windows+d")

