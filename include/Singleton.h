#ifndef SINGLETON
#define SINGLETON

template <class T>
class Singleton
{
public:
	static T* Instance(void);
};

template <class T>
T* Singleton<T>::Instance(void)
{
	static T toReturn;
	return &toReturn;
}

#endif