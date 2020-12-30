#pragma once

#include <vector>
#include "EventObserver.h"

class EventSubject {
public:
	virtual ~EventSubject() = default;
	void attach(EventObserver&);
	void detach(EventObserver&);
	void notify();
private:
	std::vector<EventObserver*> observers;
};

