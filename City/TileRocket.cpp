/**
 * \file TileRocket.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "TileRocket.h"

#include <string>

using namespace std;
using namespace Gdiplus;

/// How much we offset drawing the tile to the left of the center
const int OffsetLeft = 64;

/// How much we offset drawing the tile above the center
const int OffsetDown = 32;

/// Image for rocket launcher background 
const wstring RocketLauncherBackground = L"rocketB.png";

/// Image for rocket
const wstring Rocket = L"rocket.png";

/// Image for rocket launcher foreground
const wstring LauncherForeground = L"rocketF.png";

/// Speed Y constant for flight speed
const int SpeedY = 50;


/** Constructor
 * \param city The city this is a member of
 */
CTileRocket::CTileRocket(CCity *city) : CTile(city)
{
	SetImage(RocketLauncherBackground);
	
	LoadImage(mRocket, Rocket);
	LoadImage(mLauncherForeground, LauncherForeground);
}

/**
 * Destructor
 */
CTileRocket::~CTileRocket()
{
}


/**
 * Loads images
 * \param image The image we are loading
 * \param name The name of the image
 */
void CTileRocket::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileRocket::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CTile::XmlSave(node);

	itemNode->SetAttribute(L"type", L"rocket");
	itemNode->SetAttribute(L"file", GetFile());

	return itemNode;
}


/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileRocket::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	CTile::XmlLoad(node);
	SetImage(node->GetAttributeValue(L"file", L""));
}


/** Draw this item
 * \param graphics The graphics context to draw on
 */
void CTileRocket::Draw(Gdiplus::Graphics *graphics)
{
	CTile::Draw(graphics);

	if (mState == Loaded)
	{
		int widRocket = mRocket->GetWidth();
		int hitRocket = mRocket->GetHeight();

		graphics->DrawImage(mRocket.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hitRocket),
			widRocket, hitRocket);

		int widLauncher = mLauncherForeground->GetWidth();
		int hitLauncher = mLauncherForeground->GetHeight();

		graphics->DrawImage(mLauncherForeground.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hitLauncher),
			widLauncher, hitLauncher);
	}

	if (mState == Launching)
	{
		int widRocket = mRocket->GetWidth();
		int hitRocket = mRocket->GetHeight();

		graphics->DrawImage(mRocket.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hitRocket - mRocketY),
			widRocket, hitRocket);

		int widLauncher = mLauncherForeground->GetWidth();
		int hitLauncher = mLauncherForeground->GetHeight();

		graphics->DrawImage(mLauncherForeground.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hitLauncher),
			widLauncher, hitLauncher);

		if (GetY() - mRocketY < 0)
		{
			mState = Empty;
			mRocketY = 0;
		}
	}
}

/**
* Called before the image is drawn
* \param elapsed Time since last draw
*/
void CTileRocket::Update(double elapsed)
{
	CTile::Update(elapsed);

	if (mState == Launching) {

		// when the rocket is flying...
		// SpeedY is a constant pixels per second flight speed...
		mRocketY += SpeedY * elapsed;
	}
}


/**
 * Set rocket status to Loaded
 */
void CTileRocket::RocketLoad()
{
	mState = Loaded;
}


/**
 * Set rocket status to Launching
 */
void CTileRocket::RocketLaunch()
{
	mState = Launching;
}