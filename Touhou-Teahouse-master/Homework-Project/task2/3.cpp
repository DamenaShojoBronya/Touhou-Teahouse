/*(Compute the volume of a cylinder)Write a program that reads in the radius and length of a cylinder and computes the area and volume.*/
#include<iostream>
using namespace std;
#define PI 3.141592653589
int main()
{
    float r=0,l=0;
	cout<<"Enter the radius and length of a cylinder:";
	cin>>r>>l;
	cout<<"The area is "<<PI*r*r<<endl;
	cout<<"The volume is"<<PI*r*r*l<<endl;
    return 0;
}
