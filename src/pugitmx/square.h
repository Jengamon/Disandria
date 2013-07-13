#ifndef __SQUARE_H_
#define __SQUARE_H_

namespace pugitmx
{
	struct Square
	{
		int x;
		int y;
		int width;
		int height;
		Square(int _x,int _y,int _w,int _h) : x(_x), y(_y), width(_w), height(_h) {};
	};
};

#endif // __SQUARE_H_
