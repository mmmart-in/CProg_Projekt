#pragma once

class EventSubject;

class EventObserver {
public:
	virtual void callback(EventSubject&) = 0;
};

