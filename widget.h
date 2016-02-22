//
//  widget.h
//  widget
//
//  Created by Brian R. Hall on 1/26/14.
//  Copyright (c) 2014 Brian R. Hall. All rights reserved.
//

#ifndef __widget__widget__
#define __widget__widget__

#include <string>

using namespace std;

enum WidgetType
{
	INVALID_TYPE = -1,
	WEATHER,
	QUOTE,
	STOCK,
	NUM_WIDGET_TYPES
};


const string WIDGET_NAMES[NUM_WIDGET_TYPES] = {	"Weather2000",
   "Of-The-Day",
   "Ups-and-Downs"
};


class Widget
{
public:
	Widget( WidgetType type );
	//add copy constructor
	Widget( const Widget& rhs );
	string getModelName() const { return wModelName; };
   
private:
	WidgetType wType;
	int wID;
	string wModelName;
   //add static data member
	static int seqID;
	void generateModelName();
};


#endif /* defined(__widget__widget__) */
