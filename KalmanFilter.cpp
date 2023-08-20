//#include <iostream>
//#include <fstream>
//using namespace std;
//
//double p_last = 1;
//double x_last = 0;
//int kalmanfilter(int z_mensure)
//{
//	double p_mid, p_now, Q = 0.002, kg, R = 0.104, Sm;
//
//	double x_mid;
//	p_mid = p_last;
//	kg = p_mid / (p_mid + R);
//	x_mid = x_last;
//	Sm = (int)x_mid + kg * (z_mensure - x_mid);
//	p_now = (1 - kg) * p_mid + Q;
//	p_last = p_now;
//
//	x_last = Sm;
//
//	return Sm;
//
//}
//double kalmanfilter(double z_mensure)
//{
//	double p_mid, p_now, Q = 0.002, kg, R = 0.104, Sm;
//
//	double x_mid;
//	p_mid = p_last;
//	kg = p_mid / (p_mid + R);
//	x_mid = x_last;
//	Sm = (double)x_mid + kg * (z_mensure - x_mid);
//	p_now = (1 - kg) * p_mid + Q;
//	p_last = p_now;
//
//	x_last = Sm;
//
//	return Sm;
//
//}
//ifstream ifs;
//ofstream ofs;
//int main()
//{
//	double time;
//	int pkt;
//	ifs.open("C:/Users/19261/Desktop/11.txt", ios::in);
//	ofs.open("C:/Users/19261/Desktop/111.txt", ios::out);
//
//	/*while (ifs >> time >> pkt)
//	{
//		int ret = kalmanfilter(pkt);
//		cout << time << " " << ret << endl;
//		ofs << time << " " <<  ret << endl;
//	}*/
//	while (ifs >> time)
//	{
//		double ret = kalmanfilter(time);
//		//cout << time  << endl;
//		ofs << ret << endl;
//	}
//	system("pause");
//	return 0;
//}