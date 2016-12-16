/**
* \file RocketLoad.h
*
* \author Jenn Proos
*
* A class that implements a Rocket Load
*/

#include "TileVisitor.h"

#pragma once


/**
 * Class that describes a rocket load
 */
class CRocketLoad : public CTileVisitor
{
public:
	CRocketLoad();
	virtual ~CRocketLoad();

	void VisitRocket(CTileRocket *rocket);

};

