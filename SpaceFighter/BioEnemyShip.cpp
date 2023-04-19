
#include "BioEnemyShip.h"


BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void BioEnemyShip::Update(const GameTime *pGameTime)
{
	//if the enemy ship is active
	if (IsActive())
	{
		//it does the sin of the GetTotalTime * Math(PI) plus the GetIndex function
		float x = sin(pGameTime->GetTotalTime() * Math::PI + GetIndex());
		//sets the value of x to x * the speed and GetTimeElapsed * 1.4
		x *= GetSpeed() * pGameTime->GetTimeElapsed() * 1.4f;
		TranslatePosition(x, GetSpeed() * pGameTime->GetTimeElapsed());

		//if it is off screen it will then deativate 
		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(pGameTime);
}


void BioEnemyShip::Draw(SpriteBatch *pSpriteBatch)
{
	if (IsActive())
	{
		pSpriteBatch->Draw(m_pTexture, GetPosition(), Color::White, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
