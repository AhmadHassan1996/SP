import sys, psutil
from datetime import datetime

if len(sys.argv)==1:
	print "No arguments given. Exiting..."
	exit(0)

for i in range(1, len(sys.argv)):
	try:
		p=psutil.Process(int(sys.argv[i]))
		print "Process ID : ",p.pid
		print "Process Name : ",p.name()
		print "Process Status : ",p.status()
		print "Process Parent ID : ",p.ppid()
		print "Process Parent Name : ",psutil.Process(p.ppid()).name()
		date=datetime.fromtimestamp(p.create_time()).strftime("%B %d, %Y %H:%M:%S")
		day=datetime.strptime(date,"%B %d, %Y %H:%M:%S").strftime("%a")
		print "Process Creation Time : ",day,date
		print "Files opened by the process info : ",p.open_files()
		print "Memory Info (in Bytes) : ",p.memory_info()
	except psutil.NoSuchProcess:
		pass

