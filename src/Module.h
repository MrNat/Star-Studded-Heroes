#pragma once
class Module
{
protected:
	bool active;

public:
	Module(void) { active = false; }

	// For outside classes //
	void Enable() { active = true; }
	void Disable() { active = false; }
	void Toggle() { active = !active; }

	bool IsEnabled() { return active; }
};

