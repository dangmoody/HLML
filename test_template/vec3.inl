//#include "vec3.h"

//#if defined( TEST_TEMPLATE_IMPLEMENTATION )

/*
========================
vec3<T>::vec3
========================
*/
template<class T>
constexpr vec3<T>::vec3() {
	memset( data, 0, sizeof( vec3<T> ) );
}

/*
========================
vec3<T>::vec3
========================
*/
template<class T>
constexpr vec3<T>::vec3( const T number ) {
	x = y = z = number;
}

/*
========================
vec3<T>::vec3
========================
*/
template<class T>
constexpr vec3<T>::vec3( const T x, const T y, const T z ) {
	this->x = x;
	this->y = y;
	this->z = z;
}

/*
========================
vec3<T>::vec3
========================
*/
template<class T>
vec3<T> vec3<T>::operator=( const vec3<T>& other ) {
	memcpy( data, other.data, sizeof( vec3<T> ) );
	return *this;
}

/*
========================
vec3<T>::operator+
========================
*/
template<class T>
vec3<T> vec3<T>::operator+( const T scale ) const {
	return vec3<T>(
		x + scale,
		y + scale,
		z + scale
	);
}

/*
========================
vec3<T>::operator-
========================
*/
template<class T>
vec3<T> vec3<T>::operator-( const T scale ) const {
	return vec3<T>(
		x - scale,
		y - scale,
		z - scale
	);
}

/*
========================
vec3<T>::operator*
========================
*/
template<class T>
vec3<T> vec3<T>::operator*( const T scale ) const {
	return vec3<T>(
		x * scale,
		y * scale,
		z * scale
	);
}

/*
========================
vec3<T>::operator/
========================
*/
template<class T>
vec3<T> vec3<T>::operator/( const T scale ) const {
	return vec3<T>(
		x / scale,
		y / scale,
		z / scale
	);
}

/*
========================
vec3<T>::operator+
========================
*/
template<class T>
vec3<T> vec3<T>::operator+( const vec3<T>& rhs ) const {
	return vec3<T>(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z
		);
}

/*
========================
vec3<T>::operator-
========================
*/
template<class T>
vec3<T> vec3<T>::operator-( const vec3<T>& rhs ) const {
	return vec3<T>(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z
		);
}

/*
========================
vec3<T>::operator*
========================
*/
template<class T>
vec3<T> vec3<T>::operator*( const vec3<T>& rhs ) const {
	return vec3<T>(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z
		);
}

/*
========================
vec3<T>::operator/
========================
*/
template<class T>
vec3<T> vec3<T>::operator/( const vec3<T>& rhs ) const {
	return vec3<T>(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z
	);
}

/*
========================
vec3<T>::operator[]
========================
*/
template<class T>
constexpr T& vec3<T>::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return data[index];
}

/*
========================
vec3<T>::operator==
========================
*/
template<class T>
bool vec3<T>::operator==( const vec3<T>& rhs ) const {
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

/*
========================
vec3<T>::operator!=
========================
*/
template<class T>
bool vec3<T>::operator!=( const vec3<T>& rhs ) const {
	return !( operator==( rhs ) );
}

//#endif