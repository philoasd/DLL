#pragma once

#include "utils_global.h"
#include <QtCore/QtCore>
#define g_utilTool Utils::getInstance()
#define FLOAT_INTER_VALUE 0.0000001
#define PI 3.14159265358979

class UTILS_EXPORT Utils
{
public:
    static Utils* getInstance(void);

    // 获取两个点的距离
    qreal getDistance(const QPointF& p1, const QPointF& p2);
    // 比较两个浮点数是否相等
    bool isEqual(qreal number1, qreal number2);

private:
    Utils();
    virtual ~Utils();
};
