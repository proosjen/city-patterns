/**
 * \file RocketLoad.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "RocketLoad.h"
#include "TileRocket.h"


CRocketLoad::CRocketLoad()
{
}


CRocketLoad::~CRocketLoad()
{
}

/** Visit a CTileRocket object
* \param rocket Rocket we are visiting */
void CRocketLoad::VisitRocket(CTileRocket *rocket)
{
	rocket->RocketLoad();
}