#pragma once

#include "Eigen\Dense"
#include "Eigen\src\Geometry\Quaternion.h"

#define M_PI 3.14159265358979323846f
#define M_RADIANS M_PI/180

typedef Eigen::Vector2f EigenVector2;
typedef Eigen::Vector3f EigenVector3;
typedef Eigen::Vector4f EigenVector4;

typedef Eigen::Vector3f Point3d;
typedef Eigen::Vector2f Point2d;

typedef Eigen::Matrix<float, 4, 4> Matrix4x4;
typedef Eigen::Matrix<float, 4, 3> Matrix4x3;
typedef Eigen::Matrix<float, 3, 3> Matrix3x3;

typedef struct {
	Point2d center;
	float radius;
}Circle;

typedef struct {
	Point3d center;
	float radius;
}Semicircle2d;

typedef struct {
	Point3d point;
	EigenVector3 normal;
}Plane;

typedef struct {
	Point3d leftTop;
	Point3d rightTop;
	Point3d rightBottom;
	Point3d leftBottom;
}Rect;