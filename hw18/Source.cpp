#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // ��������� ������ OpenCV
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    // ��������� �����������
    cv::Mat image = cv::imread("D:\\CV\\Tue1\\test.jpg");
    if (image.empty()) {
        std::cerr << "������: �� ������� ��������� �����������!" << std::endl;
        return -1;
    }

    // ���������� ����������� � ����
    cv::imshow("�������� OpenCV", image);

    // ���� ������� ����� �������
    cv::waitKey(0);

    return 0;
}
