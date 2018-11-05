import cv2
import numpy as np

# 读取名称为 opencvlogo.png的图片
img = cv2.imread("d:\\1.jpg",1)

# 将图片转换为格式 hsv
hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

# 定义蓝色的上下限
lower_blue =  np.array([100,50,50])
higher_blue = np.array([140,255,255])

#在图片中提取蓝色的部分
mask = cv2.inRange(hsv,lower_blue,higher_blue)

#和原图像求“与”操作，只保留蓝色
left_blue = cv2.bitwise_and(img,img,mask=mask)

# 显示hsv
cv2.imshow("P3-OpenCV logo",img)
# 显示Blue
cv2.imshow("P3-Blue",left_blue)


cv2.waitKey(0)
