/**
 * \file BuildingCounter.h
 *
 * \author Jenn Proos
 *
 * A class that records the number of buildings in our city
 */

#include "TileVisitor.h"

#pragma once


/**
 * Class that records the number of buildings in our city
 */
class CBuildingCounter : public CTileVisitor
{
public:
	CBuildingCounter();
	virtual ~CBuildingCounter();

	/** Get the number of buildings
	* \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }

	void VisitBuilding(CTileBuilding *building);

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

