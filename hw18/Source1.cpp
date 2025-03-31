#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // �������� �����������
    cv::Mat image = cv::imread("D:/CV/Tue1/test.jpg");
    if (image.empty()) {
        std::cerr << "������: �� ������� ��������� �����������!" << std::endl;
        return -1;
    }

    int width = image.cols;
    int height = image.rows;
    int halfWidth = width / 2;
    int halfHeight = height / 2;

    // ������� ����� 
    cv::Mat topLeft = image(cv::Rect(0, 0, halfWidth, halfHeight)).clone();
    cv::Mat topRight = image(cv::Rect(halfWidth, 0, halfWidth, halfHeight)).clone();
    cv::Mat bottomLeft = image(cv::Rect(0, halfHeight, halfWidth, halfHeight)).clone();
    cv::Mat bottomRight = image(cv::Rect(halfWidth, halfHeight, halfWidth, halfHeight)).clone();


    //������� ����� ����� - �������������� ������
    cv::Mat invertedTopLeft;
    cv::bitwise_not(topLeft, invertedTopLeft);

    //������� ������ ����� - ������� ������
    cv::Mat grayTopRight;
    cv::cvtColor(topRight, grayTopRight, cv::COLOR_BGR2GRAY);
    cv::cvtColor(grayTopRight, grayTopRight, cv::COLOR_GRAY2BGR);  // ��� �����������

    //������ ����� ����� - ������� ������
    cv::Mat grayBottomLeft;
    cv::cvtColor(bottomLeft, grayBottomLeft, cv::COLOR_BGR2GRAY);
    cv::cvtColor(grayBottomLeft, grayBottomLeft, cv::COLOR_GRAY2BGR);

    //������ ������ ����� - �������������� ������
    cv::Mat invertedBottomRight;
    cv::bitwise_not(bottomRight, invertedBottomRight);

    // ����������� ������
    cv::Mat topRow, bottomRow, combinedImage;
    cv::hconcat(invertedTopLeft, grayTopRight, topRow);
    cv::hconcat(grayBottomLeft, invertedBottomRight, bottomRow);
    cv::vconcat(topRow, bottomRow, combinedImage);

    // ����������� �����������
    cv::imshow("��������", image);
    cv::imshow("������������ �����������", combinedImage);

    cv::waitKey(0);
    return 0;
}
