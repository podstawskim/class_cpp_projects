#pragma once
#include "Time_.h"

class TimeImpl : public Time_ {
public:

    void create(bool end_less) override;
    [[nodiscard]] long long now() const override;
    void flow() override;

private:
    long long year;
    bool endless;
};