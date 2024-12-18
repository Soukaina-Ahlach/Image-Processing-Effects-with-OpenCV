
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/photo.hpp>

using namespace std;
using namespace cv;

// Function to apply Gaussian blur
void blur() 
{
    Mat img = imread("images/woman.jpg");

    Mat imgGray, Blur_img; 
    // Convert to grayscale and apply Gaussian blur
    cvtColor(img, imgGray,COLOR_BGR2GRAY); 
    GaussianBlur(img, Blur_img, Size(7, 7), 5,0); 

    imshow("Image", img); 
    imshow("Blurimg", Blur_img); 

    waitKey(0); 
 
 }
    
// Function to apply watercolor effect
 void WaterColor_effect()
 {
    Mat image = imread("images/cat.jpg");

    Mat grayImage;
    // Convert to grayscale and apply bilateral filter
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    Mat bilateralFiltered;
    bilateralFilter(grayImage, bilateralFiltered, 9, 75, 75);

    // Invert and apply median blur
    Mat inverted;
    bitwise_not(bilateralFiltered, inverted);
    Mat medianBlurred;
    medianBlur(inverted, medianBlurred, 13);

    // Combine to create watercolor effect
    Mat watercolorEffect;
    addWeighted(bilateralFiltered, 0.5, medianBlurred, 0.5, 0, watercolorEffect);

    
    imshow("Original Image", image); 
    imshow("Watercolor Effect", watercolorEffect); 
    waitKey(0);

  
     }

// Function for pencil sketch and stylization effects
void stylization_pencil_sketch() 
{
    Mat img = imread("images/cat.jpg");
    imshow("Original image", img);

    // Pencil sketch filter
    Mat imout_gray, imout;
    pencilSketch(img, imout_gray, imout);
    imshow("Pencil Sketch ", imout_gray);
    imshow("Pencil Sketch in color", imout);

    // Stylization filter
    Mat imout_stylized;
    stylization(img, imout_stylized);
    imshow("Stylization", imout_stylized);


    waitKey(0); 
}

// Function to apply a custom color filter and pencil sketch

void ColorFilter_sketch()
{
    Mat image = imread("images/woman.jpg");

    // Modify the blue channel to create a gradient effect
    std::vector<Mat> channels;
    split(image, channels);

    for (int row = 0; row < image.rows; row++)
    {
        for (int col = 0; col < image.cols; col++)
        {
            channels[0].at<uchar>(row, col) = (col * 255) / image.cols;
        }
    }

    Mat filteredImage;
    merge(channels, filteredImage);


    namedWindow("Filtered Image", WINDOW_NORMAL);
    imshow("Originl image", image);
    imshow("Color Filtered Image", filteredImage);
    // Apply pencil sketch filter
    Mat imout_gray, imout;
    pencilSketch(filteredImage, imout_gray, imout);
    
    imshow("Color filter sketch", imout);

    waitKey(0);
}
    int main()
    {
        //blur();
        //WaterColor_effect();
        //stylization_pencil_sketch();
        ColorFilter_sketch();

        return 0;
    }