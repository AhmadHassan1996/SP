import os
from bs4 import BeautifulSoup

def getNames(file_name):
	male_names=[]
	female_names=[]
	fd=open("babynames/"+file_name,"r")
	parser_object=BeautifulSoup(fd, "lxml")
	table_list=parser_object.find_all("table",summary="Popularity for top 1000")
	
	for table in table_list:
		tr_list=table.find_all("tr")
		for index in range(1,len(tr_list)-1):
			td_list=tr_list[index].find_all("td")
			if len(td_list[1].text)>3:
				male_names.append(td_list[1].text)
			if len(td_list[2].text)>3:
				female_names.append(td_list[2].text)
	fd.close()
	return male_names, female_names

def main():
	file_names=os.listdir("babynames")
	for _file in file_names:
		male_names,female_names=getNames(_file)
		for name in male_names:
			print name
		for name in female_names:
			print name

if __name__ == "__main__":
	main()
