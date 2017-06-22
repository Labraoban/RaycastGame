#pragma once

#include "SFML\Graphics.hpp"

class Transform
{
public:
	Transform();
	virtual ~Transform();

	void SetLocalPosition(const sf::Vector2f& position);
	void SetLocalPosition(const int& posX, const int& posY);

	void SetGlobalPosition(const sf::Vector2f& position);
	void SetGlobalPosition(const int& posX, const int& posY);

	//void SetLocalRotation(const sf::Vector2f& rotation);
	//void SetGlobalRotation(const sf::Vector2f& rotation);
	void SetForward(const sf::Vector2f& direction);
	sf::Vector2f GetForward();

	void Move(const sf::Vector2f& movement);
	void Rotate(float angles);

	sf::Vector2f GetLocalPosition();
	sf::Vector2f GetGlobalPosition();
	//sf::Vector2f GetLocalRotation();
	//sf::Vector2f GetGlobalRotation();

	std::vector<Transform*>* GetChildren();
	Transform* GetParent();

	void SetParent(Transform* parent);



protected:

	Transform* parent;
	std::vector<Transform*>* children;

private:
	void UpdateChildren();

	void UpdateLocalPosition();
	void UpdateGlobalPosition();
	

	void AddChild(Transform* child);
	void RemoveChild(Transform* child);

	sf::Vector2f localPosition;
	sf::Vector2f globalPosition;

	//sf::Vector2f localRotation;
	//sf::Vector2f globalRotation;

	sf::Vector2f forward;

};

