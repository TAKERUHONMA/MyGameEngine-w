#pragma once


class SphereCollider
{
	friend class Collider;

	float radius_;
public:
	SphereCollider(float radius);
	float GetRadius() { return radius_; }
};
