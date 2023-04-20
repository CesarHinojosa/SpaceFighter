
#include "EnemyShip.h"


EnemyShip::EnemyShip()
{
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void EnemyShip::Update(const GameTime *pGameTime)
{
	//if the delay seconds is greater than 0
	if (m_delaySeconds > 0)
	{
		//it will subtract the delay seconds towards the GetTimeElapsed
		m_delaySeconds -= pGameTime->GetTimeElapsed();

		//if the delay seconds is less than or equal to 2
		if (m_delaySeconds <= 2) //adjusted the spawn time for the bio enemies
		{
			//it will activate the enemy ships
			GameObject::Activate();
		}
	}
	//if the ship is already active
	if (IsActive())
	{
		//it adds the activation seconds to the GetTimeElapsed
		m_activationSeconds += pGameTime->GetTimeElapsed();
		//if the avtivation time has been greater than 2 seoncds AND is not on the screen it will deativate the enemy ship
		if (m_activationSeconds > 2 && !IsOnScreen()) Deactivate();
	}
	//it will then update the ship 
	Ship::Update(pGameTime);
}


void EnemyShip::Initialize(const Vector2 position, const double delaySeconds)
{
	//sets the position of the enemy ship
	SetPosition(position);
	//sets the m_delaySeconds to the parameter delay seconds
	m_delaySeconds = delaySeconds;

	//initializes the enemy ship
	Ship::Initialize();
}


void EnemyShip::Hit(const float damage)
{
	Ship::Hit(damage);
}