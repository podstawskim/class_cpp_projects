#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>
#include <QDebug>

class Displacement : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float value READ getValue WRITE set NOTIFY valueChanged)
private:
    float value = 0;
public:
    explicit Displacement(QObject *parent = nullptr);

    [[nodiscard]] float getValue() const;

signals:
    void valueChanged(float newValue);

public slots:
    void set(float val);

};

#endif // DISPLACEMENT_H
