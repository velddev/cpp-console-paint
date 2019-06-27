#pragma once
#include "BrushPacket.h"

#define EXISTS_(...) 0
#define EXISTS_GET(type, name, ...) 1

#define CAT(a, b, ...) a ## CAT(b, __VA_ARGS__)

#define IF_1 true
#define IF_0 0
#define IF(value) IF_ ## value

#define DEF_PROP_ATTR(type, name)  
#define DEF_PROP_ATTR(type, name, prop, ...) \
	CAT(CREATE_, prop(type, name)) (type, name, __VA_ARGS__) \

#define PROPERTY(type, name, ...) \
	private: type CAT(_, name;)\
	DEF_PROP_ATTR(type, name, __VA_ARGS__)

class Brush
{
public:
	Brush();
	Brush(char symbol, int size);

	virtual ~Brush();

	virtual BrushPacket DoPaint() = 0;

	PROPERTY(char, symbol, GET);

	int GetSize() { return size; }

	void SetSize(int size);
	void SetSymbol(char newSymbol);

private:
	//char symbol;
	int size;
};

