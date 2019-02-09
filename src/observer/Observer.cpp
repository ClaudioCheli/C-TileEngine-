/*
 * Observer.cpp
 *
 *  Created on: 15 giu 2017
 *      Author: Claudio
 */

#include "Observer.h"

Subject::Subject(){
	changed = false;
}

void Subject::attach(Observer* obs){
	observers.push_back(obs);
}

void Subject::detach(Observer* obs){
	int dimension = observers.size();
	int i=0;
	bool found = false;
	while(found == false && i<dimension){
		if(observers.at(i) == obs){
			found = true;
			observers.erase(observers.begin()+i);
		}
		i++;
	}
}

void Subject::notifyObservers(std::list<int> list){
	if(changed == true){
		for(int i=0; i<observers.size(); i++){
			observers.at(i)->updateObserver(this, list);
		}
		changed = false;
	}
}


