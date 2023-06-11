#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>

using namespace std;  //to use data type like strings
using namespace cv;   //to use cv functions or data types


/* display a picture
void main()
{
	string path = "myphoto.jpg";
	Mat img = imread(path);  //Mat is an opencv data type
	imshow("Picture",img); //imshow("Label",object of type mat)
	waitKey(0);
} */

void main()
{
	VideoCapture my_video(0); //object for video capture
	Mat img; //matrix object to capture the image

	CascadeClassifier my_facedetect;   //creating CC object to load xml file
	my_facedetect.load("haarcascade_frontalface_default.xml");    //loading the haar cascade xml file



	while (true)
	{
		my_video.read(img);
		// in python img=my_video.imread()

		vector<Rect> my_faces;  //a vector of rectangles 

		my_facedetect.detectMultiScale(img, my_faces, 1.3, 5); //detecting faces

		for (int i = 0; i < my_faces.size(); i++)
		{
			rectangle(img, my_faces[i].tl(), my_faces[i].br(), Scalar(0, 0, 255), 3);  //draw rectangle around faces
			Point p1 = my_faces[i].tl();  //top left corner co-ordinates
			Point p4 = my_faces[i].br();  //bottom right corner co-ordinates
			int p2x = my_faces[i].x + my_faces[i].width; //x co-ordinate of top right corner
			int p2y = my_faces[i].y; //y co-ordinate of top right corner
			int p3x = my_faces[i].x;
			int p3y = my_faces[i].y + my_faces[i].height; //y co-ordinate of bottom left corner
			
			

			putText(img,to_string(p1.x)+","+to_string(p1.y), my_faces[i].tl() + Point(-60,-20), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 0, 0), 1);   //display co-ordinates
			putText(img,to_string(p4.x) + "," + to_string(p4.y), my_faces[i].br() + Point(-20,20), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 0, 0), 1); //display co-ordinates
			putText(img, to_string(p2x) + "," + to_string(p2y), my_faces[i].tl()+Point(my_faces[i].width,0)+Point(-20,-20), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 0, 0), 1);   //display co-ordinates
			putText(img, to_string(p3x) + "," + to_string(p3y), my_faces[i].br() - Point(my_faces[i].width,0)+Point(-60,20), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 0, 0), 1);   //display co-ordinates
		}
		
		//display number of facesbr
		putText(img, to_string(my_faces.size()) + "Face(s) Found", Point(10, 40), FONT_HERSHEY_COMPLEX_SMALL, 2, Scalar(0, 0, 0), 2);


		imshow("Camera 1", img);
		waitKey(1);  //increaing the argument makes  the video slower as the time between frames increases

	}
}