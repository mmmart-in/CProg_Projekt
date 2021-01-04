#include "EventSubject.h"
#include <iostream>
#include <algorithm>

void EventSubject::attach(EventObserver& observer) {
	observers.push_back(&observer);
}

void EventSubject::detach(EventObserver& observer) {
	observers.erase(std::remove(observers.begin(), observers.end(), &observer));
}

void EventSubject::notify() {
	for (auto& observer : observers)
		observer->callback(*this);
 }