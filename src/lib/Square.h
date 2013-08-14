#ifndef SQUARE_H
#define SQUARE_H

namespace disandria
{
	struct Square
	{
		double tl;
		double tr;
		double bl;
		double br;
		static Square createSquare(double topl, double width, double height)
		{
			Square squ;
			squ.tl = topl;
			squ.tr = topl + width;
			squ.bl = topl + height;
			squ.br = topl + width + height;
			return squ;
		}
		static Square createSquare(double points[])
		{
			Square squ;
			squ.tl = points[0];
			squ.tr = points[1];
			squ.bl = points[2];
			squ.br = points[3];
			return squ;
		}
		static Square createSquare(Square& squr)
		{
			Square squ;
			squ.tl = squr.tl;
			squ.tr = squr.tr;
			squ.bl = squr.bl;
			squ.br = squr.br;
			return squ;
		}
		private:
			Square();
	};
};

#endif // SQUARE_H
