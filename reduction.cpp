#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#define TARGET_WIDTH 640;
#define TARGET_HEIGHT 480;

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // We'll start by loading an image from the drive
    Mat image = imread("prueba.jpg", IMREAD_COLOR);

    // We check that our image has been correctly loaded
    if(image.empty()) {
        cout << "Error: the image has been incorrectly loaded." << endl;
        return 0;
    }
    // Accesssing val
    cout << "each row have " << image.rows<< endl;
    cout << "each column have " << image.cols<< endl;

    // this to store the original image by its RGB components
    u_char OriginalImageBlue[][] = new u_char [image.rows][image.cols]; 
    u_char OriginalImageGreen[][] = new u_char [image.rows][image.cols]; 
    u_char OriginalImageRed[][] = new u_char [image.rows][image.cols];

    // destination image matrix by its RGB components
    u_char DestinationImageBlue[][] = new u_char [TARGET_HEIGHT][TARGET_WIDTH]; 
    u_char DestinationImageGreen[][] = new u_char [TARGET_HEIGHT][TARGET_WIDTH]; 
    u_char DestinationImageRed[][] = new u_char [TARGET_HEIGHT][TARGET_WIDTH];
    // Loads the 3 RGB Matrix
    for(int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel;
            pixel = image.at<Vec3b>(Point(i, j)); // B[0], G[1], R[2] => u_char
            OriginalImageBlue[i][j] = pixel[0];
            OriginalImageGreen[i][j] = pixel[1];
            OriginalImageRed[i][j] = pixel[2];
        }
        cout << endl;
    }
    // Then we create a window to display our image
    //namedWindow("My first OpenCV window");

    // Finally, we display our image and ask the program to wait for a key to be pressed
    //imshow("My first OpenCV window", image);
    //waitKey(0);

    return 0;
}