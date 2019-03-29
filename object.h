#pragma once
#ifndef OBJECT_H
#define	OBJECT_H
class Object
{
private:
					static int _count;
public:
					Object();
					Object(const Object& orig);
					virtual ~Object();
					static int getCount();
};
#endif	/* OBJECT_H */

