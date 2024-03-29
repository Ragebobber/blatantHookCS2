#pragma once

template <typename T>
class ConfigItem
{
	std::string category, name;
	T* value;
public:
	ConfigItem(std::string category, std::string name, T* value)
	{
		this->category = category;
		this->name = name;
		this->value = value;
	}
};

template <typename T>
class ConfigValue
{
public:
	ConfigValue(std::string category_, std::string name_, T* value_)
	{
		category = category_;
		name = name_;
		value = value_;
	}

	std::string category, name;
	T* value;
};

class Config {
protected:
	std::vector<ConfigValue<int>*> ints;
	std::vector<ConfigValue<bool>*> bools;
	std::vector<ConfigValue<float>*> floats;
private:
	void setupValue(int&, int, std::string, std::string);
	void setupValue(bool&, bool, std::string, std::string);
	void setupValue(float&, float, std::string, std::string);

public:	
	Config();
	~Config();

	void save();
	void load();
	void setUp();
};