#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT
private:
    float value = 0;
public:
    explicit Displacement(QObject *parent = nullptr);
    void set(float val);
    [[nodiscard]] float getValue() const;

signals:
    void valueChanged(float newValue);
};

#endif // DISPLACEMENT_H
