1. Operating environment

1.1 Hardware environment
a) Processor: 11th Gen Intel(R) Core(TM) i7-1165G7 operating frequency 2.80GHz;
b) Memory: 16G memory;
c) Camera: Hikvision MV-CE series USB3.0 camera;
d) Lighthouse laser equipment: two lighthouse laser equipment, tracker;

1.2 Software Environment
a) Operating system: Win10 64-bit;
b) Development tools: Visual Studio 2019, OpenCV 3.2, Python 2021, Matlab2019Rb;

1.3 System Configuration
Minimum configuration: 256 memory, 300 MB or more available disk.
Suggestion: 512 memory and more than 400 MHZ available disk space.

2. Design scheme

2.1 Overall design scheme
    All experimental data were processed in Windows 10 64bits system. Visual positioning part of the software environment is Visual Studio 2019, with OPENCV library and ARUCO library. Part of the software environment of lighthouse laser positioning is Python 2020, with steam for signal detection, and finally data processing and output through Python scripts. Through simulating the movement of small scenes, data acquisition and solution, the data fusion processing is finally carried out based on the improved extended Kalman filter, and the motion trajectory is restored by Matlab.
OpenCV: is a cross-platform computer vision and machine learning software library, which contains a variety of language development interface, and provides a lot of functions, these functions can be very efficient to achieve object detection, tracking and other computer vision algorithms, widely used in the field of image processing. In this paper, the camera is used to capture the target image, and the camera calibration, image processing and visualization are carried out with the help of the library.
    ArUco is a miniature computer vision library that can be seen as an open source extension to the OpenCV library for augmented reality. It contains some simple apis, which can quickly detect and track specific QR codes in the captured images, and realize the function of attitude estimation and target tracking. The library is a popular library developed by RafaelMunoz and Sergio Garrido for the detection of square benchmark marks. In this paper, ArUco marker code is used to recognize, detect and solve the location of the target.
The tracking process of the whole system can be divided into three parts: target tracker solution and filtering data fusion prediction:
    The first part is to calibrate the relevant parameters of the input device, establish the solution model, and extract the feature point information of the target by using the specified target.
    The second part is two sets of solution experiments, single sensor target location solution, initial error analysis and data fusion strategy.
The third part is fusion test, which determines the sampling time range, carries out multi-dimensional fusion filtering, and outputs the final estimated result.

2.2 Visual part positioning
    In each frame image captured within a certain period of time, the marker code is used as the position of the target in the current frame. The steps for solving its spatial position relative to the camera coordinate system are as follows:
1). Object recognition and detection based on ArUco coding: automatic adaptive threshold processing (mean smoothing of image matrix, difference between original image matrix and smoothing result, threshold segmentation); The pixel search and contour search were carried out on the above processing results. Bits of ArUco flags in the contour were extracted according to the preset dictionary scale, and then the unique identity id of the entered symbols was determined by searching the dictionary sequence in ArUco library according to the detection algorithm. The file jiance. If the identification id is displayed in the image processing result, the ArUco flag code is successfully detected.
2). Marking corner point detection.
3). The pixel coordinates of at least three corner points are taken as input values, and the rotation matrix and target coding coordinates are solved according to the constraints of the solution model PNP algorithm.Py1 file program is an image processing process.
4). main.cpp program output target three-dimensional coordinates TXT file.

2.3 laser positioning sectionThe beacon laser positioning device used by the institute includes two base stations (scanning tower) and a tracking device (trackeruser). There are led lights and two vertical motors inside the tower, with a lens on the machine, and a laser beam into a fan, one of which is a horizontal laser laser, and a vertical laser surface in the vertical direction. When the motor drives the laser beam to scan and fuse the signal, the motor will start to scan and fuse the wireless signal, from the receiver, when the signal begins to be timed, when the light is scanned, a small interval of light pulse, which will be left a small interval of the light pulse, and then the time parameter of the pulse midpoint, and the speed of the motor, will eventually be able to calculate the Angle of the surface of the scanning plane to the benchmark plane.
The tracker_test.py program outputs the TXT file of the six freedom information of the tracker.

2.4 Fusion experiment
    The main idea of the fusion positioning data processing scheme is to carry out data fusion processing when the lighthouse positioning solution obviously exceeds a certain threshold value of unstable data and the detection signal disappears. The fusion scheme designed by the project is actually to correct and update the abnormal data by combining the iterative predicted value of the lighthouse laser positioning data and the monocular camera positioning solution through the improved fusion algorithm. Specifically, the initial lighthouse laser positioning data is iterated according to the time stamp. If the abnormal data exceeds a certain fluctuation threshold, the optimal estimate of the current time is obtained by fusion processing of the positioning data computed by the camera and the lighthouse positioning data of the previous time. Then the original lighthouse laser positioning data is updated with the fusion estimate, and the final output is more stable and the error converges to the expected real-time positioning signal and attitude information.
Specifically, by importing the data of the two groups of TXT files after preprocessing into Matlab, filter - data fusion is carried out.
