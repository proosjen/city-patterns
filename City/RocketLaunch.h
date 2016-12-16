/**
 * \file RocketLaunch.h
 *
 * \author Jenn Proos
 *
 * A class that implements a Rocket Launch
 */

#include "TileVisitor.h"

#pragma once

/**
 * Class that describes a rocket launch
 */
class CRocketLaunch : public CTileVisitor
{
public:
	CRocketLaunch();
	virtual ~CRocketLaunch();

	void VisitRocket(CTileRocket *rocket);
};

