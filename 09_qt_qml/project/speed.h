#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float value READ get WRITE notify NOTIFY changed)

private:
            bool hasFirstValue = false;
            bool hasSecondValue = false;
            float firstValue = 0;
            float secondValue = 0;
public:
    explicit Speed(QObject *parent = nullptr);

    [[nodiscard]] bool isHasFirstValue() const;

    [[nodiscard]] bool isHasSecondValue() const;

    [[nodiscard]] float getFirstValue() const;

    [[nodiscard]] float getSecondValue() const;

public slots:
    void notify(float d);
    float get();

signals:
    void changed();

};

#endif // SPEED_H
