#include "hlml_operators_vector.h"

// int2
int2 operator+( const int2& lhs, const int32_t rhs )
{
	return int2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

int2 operator+=( int2& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int2 operator+( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

int2 operator+=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs + rhs );
}

int2 operator-( const int2& lhs, const int32_t rhs )
{
	return int2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

int2 operator-=( int2& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int2 operator-( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

int2 operator-=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs - rhs );
}

int2 operator*( const int2& lhs, const int32_t rhs )
{
	return int2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

int2 operator*=( int2& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int2 operator*( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1]
	);
}

int2 operator*=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs * rhs );
}

int2 operator/( const int2& lhs, const int32_t rhs )
{
	return int2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

int2 operator/=( int2& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int2 operator/( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

int2 operator/=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
int2& operator++( int2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
int2& operator++( int2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
int2& operator--( int2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
int2& operator--( int2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2 operator<( const int2& lhs, const int2& rhs )
{
	return bool2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2 operator<=( const int2& lhs, const int2& rhs )
{
	return bool2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2 operator>( const int2& lhs, const int2& rhs )
{
	return bool2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2 operator>=( const int2& lhs, const int2& rhs )
{
	return bool2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

int2 operator&( const int2& lhs, const int32_t& rhs )
{
	return int2(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

int2 operator&=( int2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int2 operator&( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

int2 operator&=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs & rhs );
}

int2 operator|( const int2& lhs, const int32_t& rhs )
{
	return int2(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

int2 operator|=( int2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int2 operator|( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

int2 operator|=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs | rhs );
}

int2 operator^( const int2& lhs, const int32_t& rhs )
{
	return int2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

int2 operator^=( int2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2 operator^( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

int2 operator^=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2 operator<<( const int2& lhs, const int32_t& rhs )
{
	return int2(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

int2 operator<<=( int2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int2 operator<<( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

int2 operator<<=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs << rhs );
}

int2 operator>>( const int2& lhs, const int32_t& rhs )
{
	return int2(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

int2 operator>>=( int2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2 operator>>( const int2& lhs, const int2& rhs )
{
	return int2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

int2 operator>>=( int2& lhs, const int2& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2 operator~( const int2& lhs )
{
	return int2(
		~lhs[0],
		~lhs[1]
	);
}


// int3
int3 operator+( const int3& lhs, const int32_t rhs )
{
	return int3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

int3 operator+=( int3& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int3 operator+( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

int3 operator+=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs + rhs );
}

int3 operator-( const int3& lhs, const int32_t rhs )
{
	return int3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

int3 operator-=( int3& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int3 operator-( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

int3 operator-=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs - rhs );
}

int3 operator*( const int3& lhs, const int32_t rhs )
{
	return int3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

int3 operator*=( int3& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int3 operator*( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2]
	);
}

int3 operator*=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs * rhs );
}

int3 operator/( const int3& lhs, const int32_t rhs )
{
	return int3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

int3 operator/=( int3& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int3 operator/( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

int3 operator/=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
int3& operator++( int3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
int3& operator++( int3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
int3& operator--( int3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
int3& operator--( int3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3 operator<( const int3& lhs, const int3& rhs )
{
	return bool3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3 operator<=( const int3& lhs, const int3& rhs )
{
	return bool3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3 operator>( const int3& lhs, const int3& rhs )
{
	return bool3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3 operator>=( const int3& lhs, const int3& rhs )
{
	return bool3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

int3 operator&( const int3& lhs, const int32_t& rhs )
{
	return int3(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

int3 operator&=( int3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int3 operator&( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

int3 operator&=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs & rhs );
}

int3 operator|( const int3& lhs, const int32_t& rhs )
{
	return int3(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

int3 operator|=( int3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int3 operator|( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

int3 operator|=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs | rhs );
}

int3 operator^( const int3& lhs, const int32_t& rhs )
{
	return int3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

int3 operator^=( int3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3 operator^( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

int3 operator^=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3 operator<<( const int3& lhs, const int32_t& rhs )
{
	return int3(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

int3 operator<<=( int3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int3 operator<<( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

int3 operator<<=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs << rhs );
}

int3 operator>>( const int3& lhs, const int32_t& rhs )
{
	return int3(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

int3 operator>>=( int3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3 operator>>( const int3& lhs, const int3& rhs )
{
	return int3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

int3 operator>>=( int3& lhs, const int3& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3 operator~( const int3& lhs )
{
	return int3(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// int4
int4 operator+( const int4& lhs, const int32_t rhs )
{
	return int4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

int4 operator+=( int4& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int4 operator+( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

int4 operator+=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs + rhs );
}

int4 operator-( const int4& lhs, const int32_t rhs )
{
	return int4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

int4 operator-=( int4& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int4 operator-( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

int4 operator-=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs - rhs );
}

int4 operator*( const int4& lhs, const int32_t rhs )
{
	return int4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

int4 operator*=( int4& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int4 operator*( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2],
		lhs[3] * rhs[3]
	);
}

int4 operator*=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs * rhs );
}

int4 operator/( const int4& lhs, const int32_t rhs )
{
	return int4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

int4 operator/=( int4& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int4 operator/( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

int4 operator/=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
int4& operator++( int4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
int4& operator++( int4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
int4& operator--( int4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
int4& operator--( int4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4 operator<( const int4& lhs, const int4& rhs )
{
	return bool4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4 operator<=( const int4& lhs, const int4& rhs )
{
	return bool4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4 operator>( const int4& lhs, const int4& rhs )
{
	return bool4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4 operator>=( const int4& lhs, const int4& rhs )
{
	return bool4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

int4 operator&( const int4& lhs, const int32_t& rhs )
{
	return int4(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

int4 operator&=( int4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int4 operator&( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

int4 operator&=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs & rhs );
}

int4 operator|( const int4& lhs, const int32_t& rhs )
{
	return int4(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

int4 operator|=( int4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int4 operator|( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

int4 operator|=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs | rhs );
}

int4 operator^( const int4& lhs, const int32_t& rhs )
{
	return int4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

int4 operator^=( int4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4 operator^( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

int4 operator^=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4 operator<<( const int4& lhs, const int32_t& rhs )
{
	return int4(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

int4 operator<<=( int4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int4 operator<<( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

int4 operator<<=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs << rhs );
}

int4 operator>>( const int4& lhs, const int32_t& rhs )
{
	return int4(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

int4 operator>>=( int4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4 operator>>( const int4& lhs, const int4& rhs )
{
	return int4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

int4 operator>>=( int4& lhs, const int4& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4 operator~( const int4& lhs )
{
	return int4(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// uint2
uint2 operator+( const uint2& lhs, const uint32_t rhs )
{
	return uint2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

uint2 operator+=( uint2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint2 operator+( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

uint2 operator+=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs + rhs );
}

uint2 operator-( const uint2& lhs, const uint32_t rhs )
{
	return uint2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

uint2 operator-=( uint2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint2 operator-( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

uint2 operator-=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs - rhs );
}

uint2 operator*( const uint2& lhs, const uint32_t rhs )
{
	return uint2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

uint2 operator*=( uint2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint2 operator*( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1]
	);
}

uint2 operator*=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs * rhs );
}

uint2 operator/( const uint2& lhs, const uint32_t rhs )
{
	return uint2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

uint2 operator/=( uint2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint2 operator/( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

uint2 operator/=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
uint2& operator++( uint2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
uint2& operator++( uint2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
uint2& operator--( uint2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
uint2& operator--( uint2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2 operator<( const uint2& lhs, const uint2& rhs )
{
	return bool2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2 operator<=( const uint2& lhs, const uint2& rhs )
{
	return bool2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2 operator>( const uint2& lhs, const uint2& rhs )
{
	return bool2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2 operator>=( const uint2& lhs, const uint2& rhs )
{
	return bool2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

uint2 operator&( const uint2& lhs, const uint32_t& rhs )
{
	return uint2(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

uint2 operator&=( uint2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2 operator&( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

uint2 operator&=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2 operator|( const uint2& lhs, const uint32_t& rhs )
{
	return uint2(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

uint2 operator|=( uint2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2 operator|( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

uint2 operator|=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2 operator^( const uint2& lhs, const uint32_t& rhs )
{
	return uint2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

uint2 operator^=( uint2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2 operator^( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

uint2 operator^=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2 operator<<( const uint2& lhs, const uint32_t& rhs )
{
	return uint2(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

uint2 operator<<=( uint2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2 operator<<( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

uint2 operator<<=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2 operator>>( const uint2& lhs, const uint32_t& rhs )
{
	return uint2(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

uint2 operator>>=( uint2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2 operator>>( const uint2& lhs, const uint2& rhs )
{
	return uint2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

uint2 operator>>=( uint2& lhs, const uint2& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2 operator~( const uint2& lhs )
{
	return uint2(
		~lhs[0],
		~lhs[1]
	);
}


// uint3
uint3 operator+( const uint3& lhs, const uint32_t rhs )
{
	return uint3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

uint3 operator+=( uint3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint3 operator+( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

uint3 operator+=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs + rhs );
}

uint3 operator-( const uint3& lhs, const uint32_t rhs )
{
	return uint3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

uint3 operator-=( uint3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint3 operator-( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

uint3 operator-=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs - rhs );
}

uint3 operator*( const uint3& lhs, const uint32_t rhs )
{
	return uint3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

uint3 operator*=( uint3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint3 operator*( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2]
	);
}

uint3 operator*=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs * rhs );
}

uint3 operator/( const uint3& lhs, const uint32_t rhs )
{
	return uint3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

uint3 operator/=( uint3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint3 operator/( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

uint3 operator/=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
uint3& operator++( uint3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
uint3& operator++( uint3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
uint3& operator--( uint3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
uint3& operator--( uint3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3 operator<( const uint3& lhs, const uint3& rhs )
{
	return bool3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3 operator<=( const uint3& lhs, const uint3& rhs )
{
	return bool3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3 operator>( const uint3& lhs, const uint3& rhs )
{
	return bool3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3 operator>=( const uint3& lhs, const uint3& rhs )
{
	return bool3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

uint3 operator&( const uint3& lhs, const uint32_t& rhs )
{
	return uint3(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

uint3 operator&=( uint3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3 operator&( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

uint3 operator&=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3 operator|( const uint3& lhs, const uint32_t& rhs )
{
	return uint3(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

uint3 operator|=( uint3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3 operator|( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

uint3 operator|=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3 operator^( const uint3& lhs, const uint32_t& rhs )
{
	return uint3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

uint3 operator^=( uint3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3 operator^( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

uint3 operator^=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3 operator<<( const uint3& lhs, const uint32_t& rhs )
{
	return uint3(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

uint3 operator<<=( uint3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3 operator<<( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

uint3 operator<<=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3 operator>>( const uint3& lhs, const uint32_t& rhs )
{
	return uint3(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

uint3 operator>>=( uint3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3 operator>>( const uint3& lhs, const uint3& rhs )
{
	return uint3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

uint3 operator>>=( uint3& lhs, const uint3& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3 operator~( const uint3& lhs )
{
	return uint3(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// uint4
uint4 operator+( const uint4& lhs, const uint32_t rhs )
{
	return uint4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

uint4 operator+=( uint4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint4 operator+( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

uint4 operator+=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs + rhs );
}

uint4 operator-( const uint4& lhs, const uint32_t rhs )
{
	return uint4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

uint4 operator-=( uint4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint4 operator-( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

uint4 operator-=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs - rhs );
}

uint4 operator*( const uint4& lhs, const uint32_t rhs )
{
	return uint4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

uint4 operator*=( uint4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint4 operator*( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2],
		lhs[3] * rhs[3]
	);
}

uint4 operator*=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs * rhs );
}

uint4 operator/( const uint4& lhs, const uint32_t rhs )
{
	return uint4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

uint4 operator/=( uint4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint4 operator/( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

uint4 operator/=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
uint4& operator++( uint4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
uint4& operator++( uint4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
uint4& operator--( uint4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
uint4& operator--( uint4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4 operator<( const uint4& lhs, const uint4& rhs )
{
	return bool4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4 operator<=( const uint4& lhs, const uint4& rhs )
{
	return bool4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4 operator>( const uint4& lhs, const uint4& rhs )
{
	return bool4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4 operator>=( const uint4& lhs, const uint4& rhs )
{
	return bool4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

uint4 operator&( const uint4& lhs, const uint32_t& rhs )
{
	return uint4(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

uint4 operator&=( uint4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4 operator&( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

uint4 operator&=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4 operator|( const uint4& lhs, const uint32_t& rhs )
{
	return uint4(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

uint4 operator|=( uint4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4 operator|( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

uint4 operator|=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4 operator^( const uint4& lhs, const uint32_t& rhs )
{
	return uint4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

uint4 operator^=( uint4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4 operator^( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

uint4 operator^=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4 operator<<( const uint4& lhs, const uint32_t& rhs )
{
	return uint4(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

uint4 operator<<=( uint4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4 operator<<( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

uint4 operator<<=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4 operator>>( const uint4& lhs, const uint32_t& rhs )
{
	return uint4(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

uint4 operator>>=( uint4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4 operator>>( const uint4& lhs, const uint4& rhs )
{
	return uint4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

uint4 operator>>=( uint4& lhs, const uint4& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4 operator~( const uint4& lhs )
{
	return uint4(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// float2
float2 operator+( const float2& lhs, const float rhs )
{
	return float2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

float2 operator+=( float2& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float2 operator+( const float2& lhs, const float2& rhs )
{
	return float2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

float2 operator+=( float2& lhs, const float2& rhs )
{
	return ( lhs = lhs + rhs );
}

float2 operator-( const float2& lhs, const float rhs )
{
	return float2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

float2 operator-=( float2& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float2 operator-( const float2& lhs, const float2& rhs )
{
	return float2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

float2 operator-=( float2& lhs, const float2& rhs )
{
	return ( lhs = lhs - rhs );
}

float2 operator*( const float2& lhs, const float rhs )
{
	return float2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

float2 operator*=( float2& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float2 operator*( const float2& lhs, const float2& rhs )
{
	return float2(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1]
	);
}

float2 operator*=( float2& lhs, const float2& rhs )
{
	return ( lhs = lhs * rhs );
}

float2 operator/( const float2& lhs, const float rhs )
{
	return float2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

float2 operator/=( float2& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float2 operator/( const float2& lhs, const float2& rhs )
{
	return float2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

float2 operator/=( float2& lhs, const float2& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
float2& operator++( float2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
float2& operator++( float2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
float2& operator--( float2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
float2& operator--( float2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2 operator<( const float2& lhs, const float2& rhs )
{
	return bool2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2 operator<=( const float2& lhs, const float2& rhs )
{
	return bool2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2 operator>( const float2& lhs, const float2& rhs )
{
	return bool2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2 operator>=( const float2& lhs, const float2& rhs )
{
	return bool2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// float3
float3 operator+( const float3& lhs, const float rhs )
{
	return float3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

float3 operator+=( float3& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float3 operator+( const float3& lhs, const float3& rhs )
{
	return float3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

float3 operator+=( float3& lhs, const float3& rhs )
{
	return ( lhs = lhs + rhs );
}

float3 operator-( const float3& lhs, const float rhs )
{
	return float3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

float3 operator-=( float3& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float3 operator-( const float3& lhs, const float3& rhs )
{
	return float3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

float3 operator-=( float3& lhs, const float3& rhs )
{
	return ( lhs = lhs - rhs );
}

float3 operator*( const float3& lhs, const float rhs )
{
	return float3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

float3 operator*=( float3& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float3 operator*( const float3& lhs, const float3& rhs )
{
	return float3(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2]
	);
}

float3 operator*=( float3& lhs, const float3& rhs )
{
	return ( lhs = lhs * rhs );
}

float3 operator/( const float3& lhs, const float rhs )
{
	return float3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

float3 operator/=( float3& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float3 operator/( const float3& lhs, const float3& rhs )
{
	return float3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

float3 operator/=( float3& lhs, const float3& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
float3& operator++( float3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
float3& operator++( float3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
float3& operator--( float3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
float3& operator--( float3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3 operator<( const float3& lhs, const float3& rhs )
{
	return bool3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3 operator<=( const float3& lhs, const float3& rhs )
{
	return bool3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3 operator>( const float3& lhs, const float3& rhs )
{
	return bool3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3 operator>=( const float3& lhs, const float3& rhs )
{
	return bool3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// float4
float4 operator+( const float4& lhs, const float rhs )
{
	return float4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

float4 operator+=( float4& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float4 operator+( const float4& lhs, const float4& rhs )
{
	return float4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

float4 operator+=( float4& lhs, const float4& rhs )
{
	return ( lhs = lhs + rhs );
}

float4 operator-( const float4& lhs, const float rhs )
{
	return float4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

float4 operator-=( float4& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float4 operator-( const float4& lhs, const float4& rhs )
{
	return float4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

float4 operator-=( float4& lhs, const float4& rhs )
{
	return ( lhs = lhs - rhs );
}

float4 operator*( const float4& lhs, const float rhs )
{
	return float4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

float4 operator*=( float4& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float4 operator*( const float4& lhs, const float4& rhs )
{
	return float4(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2],
		lhs[3] * rhs[3]
	);
}

float4 operator*=( float4& lhs, const float4& rhs )
{
	return ( lhs = lhs * rhs );
}

float4 operator/( const float4& lhs, const float rhs )
{
	return float4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

float4 operator/=( float4& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float4 operator/( const float4& lhs, const float4& rhs )
{
	return float4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

float4 operator/=( float4& lhs, const float4& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
float4& operator++( float4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
float4& operator++( float4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
float4& operator--( float4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
float4& operator--( float4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4 operator<( const float4& lhs, const float4& rhs )
{
	return bool4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4 operator<=( const float4& lhs, const float4& rhs )
{
	return bool4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4 operator>( const float4& lhs, const float4& rhs )
{
	return bool4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4 operator>=( const float4& lhs, const float4& rhs )
{
	return bool4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


// double2
double2 operator+( const double2& lhs, const double rhs )
{
	return double2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

double2 operator+=( double2& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double2 operator+( const double2& lhs, const double2& rhs )
{
	return double2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

double2 operator+=( double2& lhs, const double2& rhs )
{
	return ( lhs = lhs + rhs );
}

double2 operator-( const double2& lhs, const double rhs )
{
	return double2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

double2 operator-=( double2& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double2 operator-( const double2& lhs, const double2& rhs )
{
	return double2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

double2 operator-=( double2& lhs, const double2& rhs )
{
	return ( lhs = lhs - rhs );
}

double2 operator*( const double2& lhs, const double rhs )
{
	return double2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

double2 operator*=( double2& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double2 operator*( const double2& lhs, const double2& rhs )
{
	return double2(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1]
	);
}

double2 operator*=( double2& lhs, const double2& rhs )
{
	return ( lhs = lhs * rhs );
}

double2 operator/( const double2& lhs, const double rhs )
{
	return double2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

double2 operator/=( double2& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double2 operator/( const double2& lhs, const double2& rhs )
{
	return double2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

double2 operator/=( double2& lhs, const double2& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
double2& operator++( double2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
double2& operator++( double2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
double2& operator--( double2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
double2& operator--( double2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2 operator<( const double2& lhs, const double2& rhs )
{
	return bool2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2 operator<=( const double2& lhs, const double2& rhs )
{
	return bool2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2 operator>( const double2& lhs, const double2& rhs )
{
	return bool2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2 operator>=( const double2& lhs, const double2& rhs )
{
	return bool2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// double3
double3 operator+( const double3& lhs, const double rhs )
{
	return double3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

double3 operator+=( double3& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double3 operator+( const double3& lhs, const double3& rhs )
{
	return double3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

double3 operator+=( double3& lhs, const double3& rhs )
{
	return ( lhs = lhs + rhs );
}

double3 operator-( const double3& lhs, const double rhs )
{
	return double3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

double3 operator-=( double3& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double3 operator-( const double3& lhs, const double3& rhs )
{
	return double3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

double3 operator-=( double3& lhs, const double3& rhs )
{
	return ( lhs = lhs - rhs );
}

double3 operator*( const double3& lhs, const double rhs )
{
	return double3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

double3 operator*=( double3& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double3 operator*( const double3& lhs, const double3& rhs )
{
	return double3(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2]
	);
}

double3 operator*=( double3& lhs, const double3& rhs )
{
	return ( lhs = lhs * rhs );
}

double3 operator/( const double3& lhs, const double rhs )
{
	return double3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

double3 operator/=( double3& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double3 operator/( const double3& lhs, const double3& rhs )
{
	return double3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

double3 operator/=( double3& lhs, const double3& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
double3& operator++( double3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
double3& operator++( double3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
double3& operator--( double3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
double3& operator--( double3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3 operator<( const double3& lhs, const double3& rhs )
{
	return bool3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3 operator<=( const double3& lhs, const double3& rhs )
{
	return bool3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3 operator>( const double3& lhs, const double3& rhs )
{
	return bool3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3 operator>=( const double3& lhs, const double3& rhs )
{
	return bool3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// double4
double4 operator+( const double4& lhs, const double rhs )
{
	return double4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

double4 operator+=( double4& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double4 operator+( const double4& lhs, const double4& rhs )
{
	return double4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

double4 operator+=( double4& lhs, const double4& rhs )
{
	return ( lhs = lhs + rhs );
}

double4 operator-( const double4& lhs, const double rhs )
{
	return double4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

double4 operator-=( double4& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double4 operator-( const double4& lhs, const double4& rhs )
{
	return double4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

double4 operator-=( double4& lhs, const double4& rhs )
{
	return ( lhs = lhs - rhs );
}

double4 operator*( const double4& lhs, const double rhs )
{
	return double4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

double4 operator*=( double4& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double4 operator*( const double4& lhs, const double4& rhs )
{
	return double4(
		lhs[0] * rhs[0],
		lhs[1] * rhs[1],
		lhs[2] * rhs[2],
		lhs[3] * rhs[3]
	);
}

double4 operator*=( double4& lhs, const double4& rhs )
{
	return ( lhs = lhs * rhs );
}

double4 operator/( const double4& lhs, const double rhs )
{
	return double4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

double4 operator/=( double4& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double4 operator/( const double4& lhs, const double4& rhs )
{
	return double4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

double4 operator/=( double4& lhs, const double4& rhs )
{
	return ( lhs = lhs / rhs );
}

// prefix
double4& operator++( double4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
double4& operator++( double4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
double4& operator--( double4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
double4& operator--( double4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4 operator<( const double4& lhs, const double4& rhs )
{
	return bool4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4 operator<=( const double4& lhs, const double4& rhs )
{
	return bool4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4 operator>( const double4& lhs, const double4& rhs )
{
	return bool4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4 operator>=( const double4& lhs, const double4& rhs )
{
	return bool4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


