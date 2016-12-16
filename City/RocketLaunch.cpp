/**
 * \file RocketLaunch.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "RocketLaunch.h"
#include "TileRocket.h"


CRocketLaunch::CRocketLaunch()
{
}


CRocketLaunch::~CRocketLaunch()
{
}


/** Visit a CTileRocket object
* \param rocket Rocket we are visiting */
void CRocketLaunch::VisitRocket(CTileRocket *rocket)
{
	rocket->RocketLaunch();
}