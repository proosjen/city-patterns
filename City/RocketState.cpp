/**
 * \file RocketState.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "TileRocket.h"
#include "RocketState.h"


CRocketState::CRocketState()
{
}


CRocketState::~CRocketState()
{
}


/**
 * Visits the rocket and adds to the relative state count
 * \param rocket The rocket we are visiting
 */
void CRocketState::VisitRocket(CTileRocket *rocket)
{
	if (rocket->GetState() == CTileRocket::Empty)
	{
		mEmptyState++;
	}
	else if (rocket->GetState() == CTileRocket::Loaded)
	{
		mLoadState++;
	}
}
