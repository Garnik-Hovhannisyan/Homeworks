#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H

class LandAnimal
{
public:
	bool inLand = true;

public:
	LandAnimal() = default;
	~LandAnimal() = default;
};

class WaterAnimal
{
public:
	bool inWater = true;

public:
	WaterAnimal() = default;
	~WaterAnimal() = default;
};

class Amphibian : public LandAnimal, public WaterAnimal
{
public:
	Amphibian() = default;
	~Amphibian() = default;

public:
	void check() const;
};

#endif // AMPHIBIAN_H