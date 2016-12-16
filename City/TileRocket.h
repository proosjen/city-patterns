/**
 * \file TileRocket.h
 *
 * \author Jenn Proos
 *
 * Class that implements a Rocket tile
 */

#pragma once

#include "Tile.h"


/**
 * A Rocket tile
 */
class CTileRocket : public CTile
{
public:
	CTileRocket(CCity *city);

	///  Default constructor (disabled)
	CTileRocket() = delete;

	void LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);

	///  Copy constructor (disabled)
	CTileRocket(const CTileRocket &) = delete;

	~CTileRocket();

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);

	void Draw(Gdiplus::Graphics *graphics);

	/// The possible rocket pad states
	enum States {Empty, Loaded, Launching};

	void Update(double elapsed); 
	
	void RocketLoad();

	void RocketLaunch();

	/** Get the status of the rocket
	* \returns Status of rocket */
	States CTileRocket::GetState() { return mState; };

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor *visitor) override { visitor->VisitRocket(this); }

private:
	/// The rocket itself
	std::unique_ptr<Gdiplus::Bitmap> mRocket;

	/// The rocket launcher foreground
	std::unique_ptr<Gdiplus::Bitmap> mLauncherForeground;

	/// The current rocket pad state
	States mState = Empty;

	/// The rockey's Y position
	double mRocketY = GetY();
};

