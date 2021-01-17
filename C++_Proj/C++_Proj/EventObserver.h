#ifndef EVENTOBSERVER_H
#define EVENTOBSERVER_H

class EventSubject;

class EventObserver {
public:
	virtual void callback(EventSubject&) = 0;
};

#endif
