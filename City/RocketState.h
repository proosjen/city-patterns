/**
 * \file RocketState.h
 *
 * \author Jenn Proos
 *
 * A class that implements the state of a Rocket
 */

#include "TileVisitor.h"

#pragma once


/**
 * Class that describes the state of a rocket
 */
class CRocketState : public CTileVisitor
{
public:
	CRocketState();
	virtual ~CRocketState();

	void VisitRocket(CTileRocket *rocket);

	/** Get the number of rockets in the empty state
	* \returns Number of empty states */
	int EmptyNum() const { return mEmptyState; }

	/** Get the number of rockets in the load state
	* \returns Number of loaded states */
	int LoadedNum() const { return mLoadState; }

private:
	/// Rockets in empty state count
	int mEmptyState = 0;

	/// Rockets in loaded state count
	int mLoadState = 0;
};

