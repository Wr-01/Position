#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <opencv2/core/eigen.hpp>
#include <fstream>
#include <string>

using namespace std;
using namespace cv;

int main() {
    ifstream in("D:/vs2021/Test/22.txt");
    ofstream out("D:/vs2021/Test/222.txt");
    string filename;
    string line;
    double fx, fy, cx, cy, k1, k2, k3, p1, p2;
    fx = 3232.764993543924;
    fy = 3234.050427967608;
    cx = 633.8920683289018;
    cy = 509.9106120525426;
    k1 = 0.4139005281566393;
    k2 = -29.24380274728365;
    k3 = 501.4655206665803;
    p1 = -0.003868945218703841;
    p2 = 0.0001054842760128855;
    //marker码实际长度
    double markerlength = 0.042;
    //double markerlength = 0.019;
    //内参矩阵
    cv::Mat cameraMatrix = (cv::Mat_<float>(3, 3) <<
        fx, 0.0, cx,
        0.0, fy, cy,
        0.0, 0.0, 1.0);
    //畸变矩阵
    cv::Mat distCoeffs = (cv::Mat_<float>(5, 1) << k1, k2, p1, p2, k3);

    //字典读取
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

    if (in) // 有该文件
    {
        while (getline(in, line)) // line中不包括每行的换行符
        {
            cout << line << endl;
            cv::Mat m_image = imread(line);
            cv::Mat  imageCopy;
            m_image.copyTo(imageCopy);

            std::vector<int> ids;
            std::vector<std::vector<cv::Point2f>> corners;
            if (m_image.empty())
            {
                cout << "m_image  is empty" << endl;
                return 0;
            }
            cv::aruco::detectMarkers(m_image, dictionary, corners, ids);//检测靶标
            // if at least one marker detected
            if (ids.size() > 0) {
                cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);//绘制检测到的靶标的框
                std::vector<cv::Vec3d> rvecs, tvecs;
                cv::aruco::estimatePoseSingleMarkers(corners, markerlength, cameraMatrix, distCoeffs, rvecs, tvecs);//求解旋转矩阵rvecs和平移矩阵tvecs
                for (unsigned int i = 0; i < ids.size(); i++)
                {
                    cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], (float)0.1);
                    //3.rotaion vector to eulerAngles
                    cv::Mat rmat;
                    Rodrigues(rvecs[i], rmat);
                    Eigen::Matrix3d rotation_matrix3d;
                    cv2eigen(rmat, rotation_matrix3d);
                    Eigen::Vector3d eulerAngle = rotation_matrix3d.eulerAngles(0, 1, 2);//(0,1,2)表示分别绕XYZ轴顺序，即 顺序，逆时针为正
                    /*cout << "pitch " << eulerAngle.x() << "yaw " << eulerAngle.y() << "roll" << eulerAngle.z() << endl;
                    cout << "x= " << tvecs[i][0] << "y=" << tvecs[i][1] << "z=" << tvecs[i][2] << endl;*/
                    //String angle = "pitch:"+to_string(eulerAngle.x())+ "; yaw:" + to_string(eulerAngle.y())+ "; roll:" + to_string(eulerAngle.z());
                    //String xyz =  to_string(tvecs[i][0]) + "," + to_string(tvecs[i][1]) + "," + to_string(tvecs[i][2]);
                    //cout << "x= " << tvecs[i][0] << "y=" << tvecs[i][1] << "z=" << tvecs[i][2] << endl;
                    out << tvecs[i][0] << "," << tvecs[i][1] << "," << tvecs[i][2] << endl;
                }
            }
        }
        out.close();
    }
    cv::waitKey();
    return 0;
}
//
//
//
//
//
////#include <opencv2/opencv.hpp>
////#include <opencv2/aruco.hpp>
////#include <opencv2/calib3d/calib3d.hpp>
////#include "opencv2/core/core.hpp"
////#include <opencv2/highgui/highgui.hpp>
////#include <opencv2/imgproc/imgproc.hpp>
////#include <iostream>
////#include <Eigen/Core>
////#include <Eigen/Geometry>
////#include <opencv2/core/eigen.hpp>
////
////using namespace std;
////using namespace cv;
////
////int main()
////{
////    cv::Mat m_image = imread("D:\\vs2021\\tesT\\Image_20220616201249355.jpg");
////    if (m_image.empty())
////    {
////        cout << "m_image  is empty" << endl;
////        return 0;
////    }
////    cv::Mat  imageCopy;
////    m_image.copyTo(imageCopy);
////    double fx, fy, cx, cy, k1, k2, k3, p1, p2;
////    fx = 3694.322;
////    fy = 3596.387;
////    cx = 660.281;
////    cy = 129.486;
////    k1 = 0.885;
////    k2 = -20.168;
////    k3 = 159.195;
////    p1 = -0.032;
////    p2 = 0.03;
////    //marker码实际长度
////    double markerlength = 0.42;
////    //内参矩阵
////    cv::Mat cameraMatrix = (cv::Mat_<float>(3, 3) <<
////        fx, 0.0, cx,
////        0.0, fy, cy,
////        0.0, 0.0, 1.0);
////    //畸变矩阵
////    cv::Mat distCoeffs = (cv::Mat_<float>(5, 1) << k1, k2, p1, p2, k3);
////
////    //字典读取
////    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
////    ////read para
////     //double markerlength = 0.42;
////     //cv::Mat intrinsics = (Mat_<double>(3, 3) <<
////     //    3694.322, 0, 660.281,
////     //0, 3596.387, 129.486,
////     //0, 0, 1);
////
////     //cv::Mat distCoeffs = (cv::Mat_<double>(5, 1) << 0.885, -20.168, -0.032, 0.03, 159.195);
////     //cv::Mat  imageCopy;
////     //m_image.copyTo(imageCopy);
////     //cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
////
////    std::vector<int> ids;
////    std::vector<std::vector<cv::Point2f>> corners;
////    cv::aruco::detectMarkers(m_image, dictionary, corners, ids);//检测靶标
////    // if at least one marker detected
////    if (ids.size() > 0) {
////        cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);//绘制检测到的靶标的框
////        std::vector<cv::Vec3d> rvecs, tvecs;
////        cv::aruco::estimatePoseSingleMarkers(corners, markerlength, cameraMatrix, distCoeffs, rvecs, tvecs);//求解旋转矩阵rvecs和平移矩阵tvecs
////        for (unsigned int i = 0; i < ids.size(); i++)
////        {
////            cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], (float)0.1);
////            //3.rotaion vector to eulerAngles
////            cv::Mat rmat;
////            Rodrigues(rvecs[i], rmat);
////            Eigen::Matrix3d rotation_matrix3d;
////            cv2eigen(rmat, rotation_matrix3d);
////            Eigen::Vector3d eulerAngle = rotation_matrix3d.eulerAngles(0, 1, 2);//(0,1,2)表示分别绕XYZ轴顺序，即 顺序，逆时针为正
////            cout << "pitch " << eulerAngle.x() << "yaw " << eulerAngle.y() << "roll" << eulerAngle.z() << endl;
////            cout << "x= " << tvecs[i][0] << "y=" << tvecs[i][1] << "z=" << tvecs[i][2] << endl;
////        }
////    }
////    cv::imshow("out", imageCopy);
////    cv::waitKey();
////
////    return 0;
////}