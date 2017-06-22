#include "stdafx.h"
#include "BoxCollider.h"
#include <math.h>
#include "Vector2Utility.h"
#include <limits>

BoxCollider::BoxCollider(const sf::FloatRect& rect)
{
	this->rect = rect;
}

BoxCollider::~BoxCollider()
{

}

bool BoxCollider::IsColliding(Collider* other)
{
	return false;
}

void BoxCollider::OnCollition()
{

}

bool BoxCollider::Raycast(Ray ray, RaycastHit& hit)
{
	std::vector<sf::Vector2f> intersections = GetIntersections(ray);
	if (intersections.size() > 0)
	{
		//hit.closestIntersection = intersections[0];
		hit.distance = std::numeric_limits<float>::max();
		for (int i = 0; i < intersections.size(); ++i)
		{
			float distance = Vector2Utility::Distance(ray.GetPosition(), intersections[i]);
			if (distance < hit.distance)
			{
				hit.intersection = intersections[i];
				hit.distance = distance;
				hit.other = this;
			}
		}
		return true;
	}
	return false;
}


//TODO: Optimization, Switch this one out to a real line segment v rect check
std::vector<sf::Vector2f> BoxCollider::GetIntersections(Ray ray)
{
	std::vector<sf::Vector2f> intersections;// = std::vector<sf::Vector2f>(4);
	///
	sf::Vector2f rayStart = ray.GetPosition();
	sf::Vector2f rayEnd = ray.GetPosition() + ray.GetDirection() * ray.GetLength();

	sf::Vector2f topLeft = sf::Vector2f(rect.left, rect.top);
	sf::Vector2f topRight = sf::Vector2f(rect.left + rect.width, rect.top);
	sf::Vector2f botLeft = sf::Vector2f(rect.left, rect.top + rect.height);
	sf::Vector2f botRight = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);

	sf::Vector2f lineIntersection;


	//Top
	if (LineIntersection(rayStart, rayEnd, topLeft, topRight, lineIntersection))
		intersections.push_back(lineIntersection);

	//Left
	if (LineIntersection(rayStart, rayEnd, topLeft, botLeft, lineIntersection))
		intersections.push_back(lineIntersection);

	//Right
	if (LineIntersection(rayStart, rayEnd, topRight, botRight, lineIntersection))
		intersections.push_back(lineIntersection);

	//Bot
	if (LineIntersection(rayStart, rayEnd, botLeft, botRight, lineIntersection))
		intersections.push_back(lineIntersection);

	return intersections;
}


//TODO: Move this to a more suitable location
bool BoxCollider::LineIntersection(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4, sf::Vector2f& out)
{
	double x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
	double y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;

	double den = (y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1);

	if (den == 0)
		return false;

	double ua = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / den;
	double ub = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / den;

	double x = x1 + ua*(x2 - x1);
	double y = y1 + ua*(y2 - y1);

	if( !(ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1))
		return false;

	out.x = x;
	out.y = y;
	return true;
}

sf::FloatRect BoxCollider::GetRect()
{
	return rect;
}

void BoxCollider::UpdatePosition()
{
	rect.left = position.x;
	rect.top = position.y;
}