#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
private:
            bool hasFirstValue = false;
            bool hasSecondValue = false;
            float firstValue = 0;
            float secondValue = 0;
public:
    explicit Speed(QObject *parent = nullptr);
    float get();

    [[nodiscard]] bool isHasFirstValue() const;

    [[nodiscard]] bool isHasSecondValue() const;

    [[nodiscard]] float getFirstValue() const;

    [[nodiscard]] float getSecondValue() const;

public slots:
    void notify(float d);

signals:


};

#endif // SPEED_H
