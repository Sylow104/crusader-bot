#ifndef _PERSON_
#define _PERSON_

class person
{
	public:
	person(unsigned long discord_id);
	~person();

	unsigned long id();

	private:
	unsigned long person_id = 0;
};

#endif /* _PERSON_ */