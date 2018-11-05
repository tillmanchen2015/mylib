import os
import ftplib
import time

def uploadfile(ftp, remotepath, localpath):
    bufsize = 1024
    print('localpath:'+localpath)
    print('remotepath: '+ remotepath)
    fp = open(localpath, 'rb')
    ftp.storbinary('STOR ' + remotepath, fp, bufsize)
    fp.close()

host = '10.1.2.202'
username = 'webmaster'
password = 'facethink2016'
print('ftp host : %s, username : %s, password : %s'% (host, username, password))

dll_dir = r"D:\src\baqu_refactor\FaceThinkClassAnalysis\x64\Release\\"
file_list = ['TSClient.dll']


ftp = ftplib.FTP()
ftp.set_debuglevel(2)
ftp.connect(host, 21)
ftp.login(username, password)
print(ftp.getwelcome())

print('go to /home/disk3/ftp/mirror/chenaiqi/mirror/refactor')
ftp.cwd('/home/disk3/ftp/mirror/chenaiqi/mirror/refactor')
t = time.strftime("%m%d%H%M%S", time.localtime(time.time()))
if not os.path.exists(t):
    ftp.mkd(t)

for file in file_list:
    print('upload file: ', file)
    uploadfile(ftp, '/home/disk3/ftp/mirror/chenaiqi/mirror/refactor/'+t+'/'+file, dll_dir+file)







