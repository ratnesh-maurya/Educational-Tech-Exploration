import pyperclip, pyautogui
import time

sleeptime = time.sleep(5)

for i in pyperclip.paste().split("\n"):
    for j in i:
        pyautogui.write(j)
        if j in ["[","\"","\'","("]:
            pyautogui.press("delete")
    pyautogui.press(["enter","home"])