import time
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By


driver = webdriver.Chrome(executable_path='path to chromedriver.exe')

driver.get("https://web.whatsapp.com/")
wait = WebDriverWait(driver, 600)

TARGET = '"contact name"'
SPAM_COUNT = 20
MESSAGE = "message here"

X_ARG = '//span[contains(@title,' + TARGET + ')]'
group_title = wait.until(EC.presence_of_element_located((
	By.XPATH, X_ARG)))
group_title.click()


message = driver.find_elements_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]')[0]

for i in range(SPAM_COUNT):
    message.send_keys(MESSAGE + Keys.ENTER)

time.sleep(2)
driver.close()
