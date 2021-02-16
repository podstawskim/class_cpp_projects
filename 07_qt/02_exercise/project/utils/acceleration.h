#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
private:
    bool hasFirstValue = false;
    bool hasSecondValue = false;
    bool hasThirdValue = false;
    float firstValue = 0;
    float secondValue = 0;
    float thirdValue = 0;
public:
    explicit Acceleration(QObject *parent = nullptr);
    float get();

    [[nodiscard]] bool isHasFirstValue() const;

    [[nodiscard]] bool isHasSecondValue() const;

    [[nodiscard]] bool isHasThirdValue() const;

    [[nodiscard]] float getFirstValue() const;

    [[nodiscard]] float getSecondValue() const;

    [[nodiscard]] float getThirdValue() const;

public slots:
    void notify(float d);
signals:

};

#endif // ACCELERATION_H
