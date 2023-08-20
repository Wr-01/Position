//// aruco_code_detect.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//
//#include <iostream>  
//#include <opencv2/core/core.hpp>  
//#include<opencv2/highgui/highgui.hpp>  
//#include <opencv2/aruco/charuco.hpp>
//#include "opencv2/imgproc.hpp"
//
//using namespace cv;
//using namespace std;
//
////检测图片中aruco的marker码
//void maker_test(Mat image)
//{
//	cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
//
//
//	cv::Ptr<cv::aruco::DetectorParameters> params = aruco::DetectorParameters::create();
//	params->cornerRefinementMethod = cv::aruco::CORNER_REFINE_NONE;
//
//	cv::Mat imagecopy;
//
//	image.copyTo(imagecopy);
//	std::vector<int> ids;
//	std::vector<std::vector<cv::Point2f>> corners, rejected;
//	cv::aruco::detectMarkers(image, dictionary, corners, ids, params);
//
//
//	// if at least one marker detected
//	if (ids.size() > 0)
//	{
//		cv::aruco::drawDetectedMarkers(imagecopy, corners, ids);
//		cv::imshow("test", imagecopy);
//		imwrite("D:/vs2021/tesT/result111.jpg", imagecopy);
//		cv::waitKey();
//	}
//
//
//}
//int main()
//{
//	Mat img = cv::imread("D:/vs2021/tesT/111.jpg", 1);
//	maker_test(img);
//}
//
