#pragma once

template <class T >
class ServiceLocator
{
private:
	ServiceLocator();

public:
	static void Set(T* service) { ServiceLocator::service = service; };
	static T* Get() { return service; };

private:
	static T* service;
}; 

template <class T>
T* ServiceLocator<T>::service = nullptr;