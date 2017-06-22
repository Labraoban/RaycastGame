#pragma once

#include "SFML\Graphics.hpp"
#include "Collider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider(const sf::FloatRect& rect);
	~BoxCollider();

	bool IsColliding(Collider* other);
	void OnCollition();

	bool Raycast(Ray ray, RaycastHit& hit);

	std::vector<sf::Vector2f> GetIntersections(Ray ray);

	bool LineIntersection(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4, sf::Vector2f& out);

	sf::FloatRect GetRect();

private:
	void UpdatePosition();

	sf::FloatRect rect;

};
