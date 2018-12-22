#pragma once
enum piece_type
{
	// I capitalized the enums to differentiate between them and the classes
	// TODO: There has to be a better way
	Pawn   = 'P',
	Rook   = 'R',
	Knight = 'N',
	Bishop = 'B',
	Queen  = 'Q',
	King   = 'K',
	None   = '-'
};

enum player
{
	white,
	black
};