#include "Dummy.h"
#include "TestIncludes.h"

TEST(Dummy, Integrate_SingleElement)
{
    Dummy dummy{3, 3};
    EXPECT_EQ(3, dummy.integrate());
}

TEST(Dummy, Integrate_ThreeElements)
{
    Dummy dummy{3, 5};
    EXPECT_EQ(12, dummy.integrate());
}
