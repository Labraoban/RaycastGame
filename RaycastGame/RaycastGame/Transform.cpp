#include "stdafx.h"
#include "Transform.h"
#include "Vector2Utility.h"

Transform::Transform()
{
	children = new std::vector<Transform*>();
	localPosition = sf::Vector2f(0, 0);
	globalPosition = sf::Vector2f(0, 0);
	forward = sf::Vector2f(0, 1);
}

Transform::~Transform()
{
	if (children != nullptr)
		delete children;
}

void Transform::SetLocalPosition(const sf::Vector2f& position)
{
	localPosition = position;
	UpdateGlobalPosition();
	UpdateChildren();
}

void Transform::SetLocalPosition(const int& posX, const int& posY)
{
	SetLocalPosition(sf::Vector2f(posX, posY));
}

void Transform::SetGlobalPosition(const sf::Vector2f& position)
{
	globalPosition = position;
	UpdateLocalPosition();
	UpdateChildren();
}

void Transform::SetGlobalPosition(const int& posX, const int& posY)
{
	SetGlobalPosition(sf::Vector2f(posX, posY));
}

//void Transform::SetLocalRotation(const sf::Vector2f& rotation)
//{
//	localRotation = rotation;
//}
//
//void Transform::SetGlobalRotation(const sf::Vector2f& rotation)
//{
//	localRotation = rotation;
//}

void Transform::SetForward(const sf::Vector2f& direction)
{
	forward = Vector2Utility::Normalize(direction);
}

sf::Vector2f Transform::GetForward()
{
	return forward;
}

void Transform::Move(const sf::Vector2f& movement)
{
	SetGlobalPosition(GetGlobalPosition() + movement);
}

void Transform::Rotate(float angles)
{
	SetForward(Vector2Utility::Rotate(forward, angles));
}

sf::Vector2f Transform::GetLocalPosition()
{
	return localPosition;
}

sf::Vector2f Transform::GetGlobalPosition()
{
	return globalPosition;
}

//sf::Vector2f Transform::GetLocalRotation()
//{
//	return localRotation;
//}
//
//sf::Vector2f Transform::GetGlobalRotation()
//{
//	return globalPosition;
//}

std::vector<Transform*>* Transform::GetChildren()
{
	return children;
}

Transform* Transform::GetParent()
{
	return parent;
}

void Transform::SetParent(Transform* parent)
{
	if (this->parent != parent)
	{
		if (this->parent != nullptr)
			this->parent->RemoveChild(this);
		this->parent = parent;
		this->parent->AddChild(this);
		UpdateLocalPosition();
	}
}



void Transform::UpdateGlobalPosition()
{
	if (parent != nullptr)
		globalPosition = parent->GetGlobalPosition() + localPosition;
	UpdateChildren();
}

void Transform::UpdateLocalPosition()
{
	if (parent != nullptr)
		localPosition = globalPosition - parent->GetGlobalPosition();
	UpdateChildren();
}

void Transform::UpdateChildren()
{
	for (int i = 0; i < children->size(); ++i)
	{
		children->at(i)->UpdateGlobalPosition();
		children->at(i)->UpdateLocalPosition();
	}
}

void Transform::AddChild(Transform* child)
{
	children->push_back(child);
}

void Transform::RemoveChild(Transform* child)
{
	for (int i = 0; i < children->size(); ++i)
	{
		if (children->at(i) == child)
			children->erase(children->begin() + i);
	}
}

