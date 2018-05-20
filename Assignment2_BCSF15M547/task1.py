import requests, os, urllib
from bs4 import BeautifulSoup
from datetime import datetime

def mergeFiles(qari_name):
	os.chdir("./"+qari_name)
	os.system("mp3wrap second_half.mp3 *.mp3")
	os.chdir("../")

def downloadFile(File_URL):
	filename=File_URL.split('/')[-1]
	qariname=File_URL.split('/')[-2]
	urllib.urlretrieve(File_URL,qariname+"/"+filename)

def getFile(Name_URL):
	if Name_URL!="":
		try:
			status=requests.get(Name_URL)
			fd=open("LOG.txt","a")

			if status.status_code==200:
				count=0
				parser_object=BeautifulSoup(status.content,"html.parser")
				a_tags=parser_object.find_all('a')

				for a in reversed(a_tags):
					if count==26:
						break
					if a.text=="../":
						continue
					fd.write(datetime.today().strftime("%Y-%m-%d %H:%M:%S")+" Qari_"+Name_URL.split('/')[-2]+" "+a.text+" START\n")
					downloadFile(Name_URL+a['href'])
					fd.write(datetime.today().strftime("%Y-%m-%d %H:%M:%S")+" Qari_"+Name_URL.split('/')[-2]+" "+a.text+" END\n")
					count+=1
			fd.close()
		except requests.ConnectionError:
			print "Error! Connection could not be established."

def getQariNames(URL):
	if URL!="":
		try:
			count=1
			status=requests.get(URL)
			fd=open("LOG.txt","a")

			if status.status_code==200:
				parser_object=BeautifulSoup(status.content,"html.parser")
				a_tags=parser_object.find_all('a')
				fd.write(datetime.today().strftime("%Y-%m-%d %H:%M:%S")+" TOTAL QARI "+str(len(a_tags)-2)+"\n")

				for a in a_tags:
					if a.text=="../" or a.text=="iza3a.zip":
						continue

					fd.write(datetime.today().strftime("%Y-%m-%d %H:%M:%S")+" Start Processing "+str(count)+" out of "+str(len(a_tags)-2)+"\n")
					count+=1

					if not os.path.exists(a.text):
						os.mkdir(a.text)

					fd.write(datetime.today().strftime("%Y-%m-%d %H:%M:%S")+" Qari_"+a.text[:-1]+"\n")
					fd.close()
					getFile(URL+a['href'])
					fd=open("LOG.txt","a")

					fd.write(datetime.today().strftime("%Y-%m-%d %H:%M:%S")+" Merging the Files of Qari_"+a.text[:-1]+" START\n")
					mergeFiles(a.text)
					fd.write(datetime.today().strftime("%Y-%m-%d %H:%M:%S")+" Merging the Files of Qari_"+a.text[:-1]+" END\n")

			fd.close()
		except requests.ConnectionError:
			print "Error! Connection could not be established."

def main():
	URL="https://download.quranicaudio.com/quran/"
	getQariNames(URL)

if __name__ == "__main__":
	main()
