#include <iostream>
#include <winbgim.h>
#include <time.h>
using namespace std;

struct k
{int x, y;} body[1000];

int main()
{
	initwindow(1200, 700);
	srand(time(0));
	
	int a=10, b=4, dx=1, dy=0;
	int mx=rand()%50+1, my=rand()%30+1;
	int leng=5;
	
	// thong so dau tien cua than con ran
	for (int i=leng;i<a+leng;i++)
	{
		body[i].x=i+1;
		body[i].y=3;
	}
	
	// ve thuc an dau tien
	setcolor(4); setfillstyle(1,14);
	rectangle(mx*18-18+1, my*18-18+1, mx*18-1, my*18-1);
	bar(mx*18-18+3, my*18-18+3, mx*18-3, my*18-3);
	
	rectangle(a*18-18+1,b*18-18+1,a*18-1,b*18-1);
	do
	{
		if (kbhit()) char key = getch();
		
		// xoa con ran
		setcolor(0);
		rectangle(a*18-18+1,b*18-18+1,a*18-1,b*18-1);
		for (int i=0;i<leng;i++) 
		rectangle(body[i].x*18-18+1,body[i].y*18-18+1,body[i].x*18-1,body[i].y*18-1);
		
		// dieu khien
		if (GetAsyncKeyState(VK_RIGHT) && dx!=-1) {dx=1; dy=0;}
		if (GetAsyncKeyState(VK_LEFT) && dx!=1) {dx=-1; dy=0;}
		if (GetAsyncKeyState(VK_UP) && dy!=1) {dy=-1; dx=0;}
		if (GetAsyncKeyState(VK_DOWN) && dy!=-1) {dy=1; dx=0;}
		
		// dau con ran di chuyen
		a+=dx; b+=dy;
		
		// dau con ran va cham than ran
		for (int i=1;i<leng;i++)
		if (a==body[i].x && b==body[i].y) {dx=-2;};
		
		// xu ly di chuyen cua than con ran
		for (int i=leng;i>0;i--) body[i]=body[i-1];
		body[0].x=a; body[0].y=b;
		
		// neu cham bien
		if (a>60) a=1; if (a<1) a=60;
		if (b>35) b=1; if (b<1) b=35;
		
		// neu ran an moi
		if (a==mx && b==my) 
		{
			// xoa thuc an cu
			setfillstyle(1,0);
			bar(mx*18-18, my*18-18, mx*18, my*18);
			
			// doi vi tri thuc an
			// tang kich thuoc ran
			mx=rand()%50+1, my=rand()%30+1; 
			leng++;
			
			// ve thuc an moi
			setcolor(rand()%14+1); setfillstyle(1, rand()%14+1);
			rectangle(mx*18-18+1, my*18-18+1, mx*18-1, my*18-1);
			bar(mx*18-18+3, my*18-18+3, mx*18-3, my*18-3);
		}
		
		// ve con ran
		setcolor(9);
		for (int i=0;i<leng;i++) 
		rectangle(body[i].x*18-18+1,body[i].y*18-18+1,body[i].x*18-1,body[i].y*18-1);
		setcolor(1);
		rectangle(a*18-18+1,b*18-18+1,a*18-1,b*18-1);
		
		
		Sleep(100);
		
		//nhan esc de thoat
	}while (GetAsyncKeyState(27)==0 && dx!=-2);
	cout<<"              "<<leng-5<<" diem!"<<endl;
	cout<<"                  GOOD BYE! "<<endl;
}
