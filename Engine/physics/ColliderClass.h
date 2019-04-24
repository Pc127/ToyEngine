#pragma once
enum ColliderType
{
	SPHRER,
	BOX,
	NONE
};

// Collider仅仅用来保存碰撞体的结构 不做任何逻辑处理
class ColliderClass
{
public:
	ColliderClass();
	virtual ~ColliderClass();
	// 初始化游戏obj 暂时硬编码
	// 不指定参数
public:
	ColliderType m_type;
};