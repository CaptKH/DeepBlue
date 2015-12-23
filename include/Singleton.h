#ifndef SINGLETON
#define SINGLETON

template <class T>
class Singleton
{
private:
	static T* instance;
	
public:
	~Singleton<T>(void)
	{
		delete instance; instance = 0;
	}

	static T* Instance(void);
};

template <class T>
T* Singleton<T>::Instance(void)
{
	if (!instance) instance = new T();
	return instance;
}

#endif