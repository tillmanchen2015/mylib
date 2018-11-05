# coding by 刘云飞
# email: liuyunfei.1314@163.com
# date: 2018-4-17

import cv2
import numpy as np

# 读取名称为 p6.png的图片
img = cv2.imread("d:\\1.jpg",1)

# 高斯模糊
blur = cv2.GaussianBlur(img,(3,3),0)

# Canny提取边缘
processed = cv2.Canny(blur,10,20)

# 显示原图和处理后的图像
cv2.imshow("org",img)
cv2.imshow("processed",processed)

cv2.waitKey(0)
