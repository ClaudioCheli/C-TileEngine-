/*
 * Observer.h
 *
 *  Created on: 23 mar 2017
 *      Author: Claudio
 */

#ifndef OBSERVER_OBSERVER_H_
#define OBSERVER_OBSERVER_H_

#include <vector>
#include <list>

class Subject;

class Observer{
public:
	virtual ~Observer(){};
	virtual void updateObserver(Subject* sub, std::list<int> list)=0;
};



class Subject{
public:
	void attach(Observer* obs);
	void detach(Observer* obs);
	void notifyObservers(std::list<int> list);
	void setChanged(){this->changed = true;}

protected:
	Subject();

private:
	bool changed;
	std::vector<Observer*> observers;
};



#endif /* OBSERVER_OBSERVER_H_ */
