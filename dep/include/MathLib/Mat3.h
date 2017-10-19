#pragma once

//NO INCLUDES IN THE HEADER WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
union vec3;
union vec2;

class Mat3
{
public:
	Mat3();
	Mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	~Mat3();

	float m[9];

	float& operator[](const size_t i);
	const float& operator[](const size_t i) const;
};



Mat3 operator+(const Mat3& lhs, const Mat3& rhs);
Mat3 operator-(const Mat3& lhs, const Mat3& rhs);
Mat3 operator-(const Mat3& lhs);
Mat3 operator*(const Mat3& lhs, const float& rhs);
Mat3 operator*(const float& lhs, const Mat3& rhs);
Mat3 operator*(const Mat3& lhs, const Mat3& rhs);
vec3 operator*(const Mat3& lhs, const vec3& rhs);
vec3 operator*(const vec3& lhs, const Mat3& rhs);


//transpose, determinant, inverse
Mat3 transposition(const Mat3 m);
Mat3 transpose(Mat3& m);
float determinant(const Mat3 m);
Mat3 inverse(const Mat3 m);
Mat3 invert(Mat3& m);

Mat3 translation(const vec2& v);
Mat3 scaleMat(const vec2& v);
//Mat3 rotation(const vec2& v);
Mat3 rotationByDeg(const float deg);
Mat3 rotationByRad(const float rad);
Mat3 mat3identity();
