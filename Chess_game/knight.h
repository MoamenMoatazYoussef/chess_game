#pragma once
#include "piece.h"

class knight : public piece
{
public:
	knight()
	{
		_type = piece_type::Knight;
	}

	knight(player _p)
	{
		_type = piece_type::Knight;
		_player = _p;
	}

	bool check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();

		short Xsquared  = (r2 - r) ^ 2;
		short Ysquared  = (c2 - c) ^ 2;
		bool circle_eqn = ((Xsquared + Ysquared) == 5);
		return circle_eqn;
			//This is the algorithm I'm proud of the most!! <3
			//------------------------------------------------
			//The knight moves (1,2) or (2,1) or (2,-1) or (1,-2) or (-1,-2) or (-2,-1) or (-2,1) or (-1,2)
			//So if we imagine the position of the knight as an origin point for x and y axis
			//We can say that the knight only moves to points which satisfy the circle that passes
			//through these 8 points
			//Using any 3 of them we can get the equation of that circle as X^2 + Y^2 = 5
			//Where center is (0,0) -current position of knight-, and radius = sqrt(5)
	}
};
