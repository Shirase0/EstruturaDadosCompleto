

# imports
import pandas as pd
import schedule
import re
import time
import urllib.request
import os
import requests
from PIL import Image
from io import BytesIO
import json
from time import sleep, strftime, gmtime
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import TimeoutException
from datetime import datetime, timedelta
from selenium.webdriver.chrome.options import Options
# -------------------------------------------------------------------------------
# My Libraries
import temporizer

# Chromedriver options setup
# -------------------------------------------------------------------------------
options = Options()
chromeOptions = webdriver.ChromeOptions()
chromeOptions.add_argument("--start-maximized")
chromeOptions.add_experimental_option("useAutomationExtension", False)
driver = webdriver.Chrome(executable_path=r"/home/ats/PycharmProjects/CursoPOOPyQt/Appconection/chromedriver", chrome_options=chromeOptions)

options.add_experimental_option('useAutomationExtension', False)
options.add_argument('--ignore-certificate-errors-spki-list')
options.add_argument('--ignore-certificate-errors')  # Adicionando argumento para ignorar erro de certificado
options.add_argument('--ignore-ssl-errors')  # Adicionando argumento para ignorar erro de ssl

url = "https://web.whatsapp.com/"
driver.get(url)
WebDriverWait(driver, 30)

#contact_list = ['//span[@title = "+55 19 99939-2197"]', '//span[@title = "Lucas Otavavio"]', '//span[@title = "Marina Victória Comp 020"]', '//span[@title = "André checker 019"]', '//span[@title = "Daniele"]']
contact_list = ['//span[@title = "MariVic"]', '//span[@title = "Daniele"]', '//span[@title = "André checker 019"]']
name_list = ["Lucas Otatavio", "MariVic", "Daniele", "André checker 019"]
count = 1
input('Enter anything after scanning QR code')

# Welcome msg structure and variable
# -------------------------------------------------------------------------------
#user = driver.find_element_by_xpath('//span[@title = "+55 19 99939-2197"]')
#user = driver.find_element_by_xpath('//span[@title = "Lucas Henrique"]'.format(name))
#user.click()

# Estrutura para envio da msg
# driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').click()
# driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').send_keys(i)
# driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[3]/button').click()


# Abre o arquivo que contem a legenda, insira o caminho onde salvou o arquivo
with open(r'White.Chicks.DVDRip.XViD-DvP.txt', 'r') as h:
    sub = h.readlines()

re_pattern = r'[0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3} -->'
regex = re.compile(re_pattern)
# Get start times
start_times = list(filter(regex.search, sub))
start_times = [time.split(' ')[0] for time in start_times]
# Get lines
lines = [[]]
# for sentence in sub:
#     if re.match(re_pattern, sentence):
#         lines[-1].pop()
#         lines.append([])
#     else:
#         lines[-1].append(sentence)
# lines = lines[1:]

message = "Eae pessoal!\nLembrando que temos reunião hoje ás 18h!\nEssa mensagem é teste do meu bot de lembretes hahaha\nhttps://meet.google.com/vnw-tmqg-qxw"
# print(lines)
# df = pd.DataFrame(lines)
df = pd.DataFrame()

while (not temporizer.alarm(14, 12, 0)):
    pass


for name in name_list:
    print(time.localtime())
    contact = f'//span[@title = "{name}"]'

    driver.find_element_by_xpath('//*[@id="side"]/div[1]/div/label/div/div[2]').clear()
    #driver.find_element_by_xpath('//*[@id="side"]/div[1]/div/label/div/div[2]').click()
    driver.find_element_by_xpath('//*[@id="side"]/div[1]/div/label/div/div[2]').send_keys(name)
    time.sleep(10)
    print(contact)
    user = driver.find_element_by_xpath(contact)
    user.click()

    try:

        driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').click()
        time.sleep(1)

        driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]').send_keys(message)
        time.sleep(1)

        driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[3]/button/span').click()
        time.sleep(1)
    except:
        print('erro')