#pragma once

#include "Ray.h"
#include "Transform.h"

typedef struct RaycastHit;

class Collider
{
protected:
	Collider() {};
	~Collider() {};

public:
	virtual bool IsColliding(Collider* other) = 0;
	virtual void OnCollition() = 0;

	virtual bool Raycast(Ray ray, RaycastHit& hit) = 0;

	virtual void SetPosition(sf::Vector2f position);
	virtual void SetPosition(const float& x, const float& y);

protected:
	sf::Vector2f position;

private:

	virtual void UpdatePosition() = 0;
};

struct RaycastHit
{
	float distance;
	sf::Vector2f intersection;
	Collider* other;

	RaycastHit()
	{
		distance = 0;
		other = nullptr;
	}
};
