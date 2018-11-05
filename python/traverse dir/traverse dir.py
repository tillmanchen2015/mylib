import os
from shutil import copyfile

index = 0
path, dirs, files = next(os.walk(r"D:\project\ocean\audio pieces"))
#for dir, subdir, files in os.walk(r"D:\project\ocean\audio pieces"):
        #path = os.path.join(dir, f)
       # name = str(index) + ".mp4"
        #dest = os.path.join(r"D:\project\ocean\audio pieces", name)

        #os.rename(path, dest)
        #index = index + 1

print(files)


