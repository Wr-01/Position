import cv2

img = cv2.imread("H:\\left1.png", cv2.IMREAD_COLOR)
x = cv2.Sobel(img, cv2.CV_16S, 1, 0)
y = cv2.Sobel(img, cv2.CV_16S, 0, 1)

absx = cv2.convertScaleAbs(x)
absy = cv2.convertScaleAbs(y)
dist = cv2.addWeighted(absx, 0.5, absy, 0.5, 0)

cv2.imshow('original_img', img)
cv2.imshow('y', absy)
cv2.imshow('x', absx)
cv2.imshow('dsit', dist)

cv2.waitKey(0)
cv2.destroyAllWindows()
