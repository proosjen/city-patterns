/**
 * \file ClickHistory.h
 *
 * \author Charles Owen
 *
 * Class that keeps track of the history of clicks on city tiles
 */

#pragma once
#include "Click.h"

/**
 * Class that keeps track of the history of clicks on city tiles
 */
class CClickHistory
{
public:
    CClickHistory();
    virtual ~CClickHistory();

    void Add(std::shared_ptr<CTile> tile, time_t time);
    bool Remove(std::shared_ptr<CTile> tile);
    void Clear();

protected:
    /**
     * Nexted class that actually stores the click history items
     */
    class Click : public CClick
    {
    public:
        Click(std::shared_ptr<CTile> tile, time_t time);
        virtual ~Click();

        /**
        * Get the tile we clicked on
        * \returns CTile object pointer
        */
        std::shared_ptr<CTile> GetTile() { return mTile; }

        /**
        * Get the time this click occurred
        * \returns Time as a long long value (seconds since 1970)
        */
        time_t GetTime() { return mTime; }

        /// Pointer to next click in linked list
        std::shared_ptr<Click> mNext;

        /// Pointer to a tile
        std::shared_ptr<CTile> mTile;

        /// Click time
        time_t mTime = 0;
    };

    /// Pointer to head of linked list of clicks
    std::shared_ptr<Click> mHead;

public:
	/* Iterator that iterates over the click history*/
	class Iter
	{
	public:
		/** Constructor
		* \param history The history we are iterating over 
		* \param pos The position in the collection */
		Iter(CClickHistory *history, std::shared_ptr<Click> pos) : mHistory(history), mPos(pos) {}

		/** Test for end of the iterator
		* \returns True if we this position equals not equal to the other position */
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** Get value at current position
		* \returns Value at mPos in the collection */
		std::shared_ptr<Click> operator *() { return mPos; }

		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++()
		{
			if (mPos != nullptr)
			{
				mPos = mPos->mNext;
			}
			return *this;
		}

	private:
		CClickHistory *mHistory;		///< History we are iterating over
		std::shared_ptr<Click> mPos;	///< Position in the collection
	};

	/** Get an iterator for the beginning of the collection
	* \returns Iter object at position 0 */
	Iter begin() { return Iter(this, mHead); }

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the end */
	Iter end() { return Iter(this, nullptr); }

};

