#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main() {
    Mat getimg = imread(R"(D:\Kuliah\cvtest2\ss ksm.png)"), c;
    QRCodeDetector *qrDet = new QRCodeDetector();
    bool exist = qrDet->detect(getimg, c);
    if(exist) cout << "QR Code found!\n";
    else return 0;
    Mat points, rectimg;
    string data = qrDet->detectAndDecode(getimg, points, rectimg);
    if (data.length())  cout << "Decoded data: " << data << '\n';
    else cout << "QR Code found but no data?!\n";
}