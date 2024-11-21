#pragma once

class Time
{
public:
	Time();
	~Time();

	void Update();

public:
	float deltaTime;

private:
	double _lastTime;
};