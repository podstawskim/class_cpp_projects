#include "RingBuffer.h"
#include <gtest/gtest.h>

TEST(RingBuffer, Constructor) {

    RingBuffer RingBuffer{};
}

TEST(RingBuffer, Constructor_PassSizeOfBufferUsingConstructor)
{
    RingBuffer RingBuffer{1};
}
TEST(RingBuffer, GetCapacity_CheckingCapacityOfRingBuffer)
{
    RingBuffer RingBuffer{1};
    EXPECT_EQ(1, RingBuffer.getCapacity());
}
TEST(RingBuffer, GetSize_CheckingCurrentSizeOfRingBuffer)
{
    RingBuffer RingBuffer{1};
    EXPECT_EQ(0, RingBuffer.getSize());
}
TEST(RingBuffer, GetHead_CheckIndexOfHead)
{
    RingBuffer RingBuffer{1};
    EXPECT_EQ(0, RingBuffer.getHead());
}
TEST(RingBuffer, GetTail_CheckIndexOfHead)
{
    RingBuffer RingBuffer{1};
    EXPECT_EQ(0, RingBuffer.getTail());
}
TEST(RingBuffer, AddElement_AddingElementToBuffer)
{
    RingBuffer RingBuffer{5};
    EXPECT_EQ(3, RingBuffer.writeToBuffer(3));
}

TEST(RingBuffer, RemovingElement_RemovingElementFromBuffer)
{
    RingBuffer RingBuffer{5};
    //najpierw dodamy dwa elementy
    RingBuffer.writeToBuffer(3);
    RingBuffer.writeToBuffer(5);
    EXPECT_EQ(3, RingBuffer.readFromBuffer());
}
TEST(RingBuffer, PrintBuffer_PrintingFullBuffer)
{
    RingBuffer RingBuffer{3};
    RingBuffer.writeToBuffer(3);
    RingBuffer.writeToBuffer(5);
    RingBuffer.writeToBuffer(4);
    EXPECT_EQ("[3 5 4 ] Size 3\n", RingBuffer.printBuffer());
}
TEST(RingBuffer, WriteToBuffer_AddingElementToFullBuffer)
{
    RingBuffer RingBuffer{3};
    RingBuffer.writeToBuffer(3);
    RingBuffer.writeToBuffer(5);
    RingBuffer.writeToBuffer(4);
    RingBuffer.writeToBuffer(1);
    EXPECT_EQ(1, RingBuffer.getBuffer()[RingBuffer.getHead()-1] );
    EXPECT_EQ(5, RingBuffer.getBuffer()[RingBuffer.getTail()]);
}

TEST(RingBuffer, WriteToBuffer_AddingMoreElementsToFullBuffer)
{
    RingBuffer RingBuffer{3};
    RingBuffer.writeToBuffer(3);
    RingBuffer.writeToBuffer(5);
    RingBuffer.writeToBuffer(4);
    RingBuffer.writeToBuffer(1);
    RingBuffer.writeToBuffer(2);
    RingBuffer.writeToBuffer(6);

    EXPECT_EQ("[1 2 6 ] Size 3\n", RingBuffer.printBuffer() );
}
TEST(RingBuffer, ReadFromBuffer_ReadingTailElementFromBuffer)
{
    RingBuffer RingBuffer{5};
    RingBuffer.writeToBuffer(1);
    RingBuffer.writeToBuffer(2);
    RingBuffer.writeToBuffer(3);

    EXPECT_EQ(1, RingBuffer.readFromBuffer() );

}
TEST(RingBuffer, WriteToBuffer_CheckingIfHeadIsOnTheRightElement)
{
    RingBuffer RingBuffer{5};
    RingBuffer.writeToBuffer(1);
    RingBuffer.writeToBuffer(2);
    RingBuffer.writeToBuffer(3);
    EXPECT_EQ(3, RingBuffer.getBuffer()[RingBuffer.getHead()-1] );
}
TEST(RingBuffer, GetTail_CheckingIfTailIsOnRightElement)
{
    RingBuffer RingBuffer{5};
    RingBuffer.writeToBuffer(1);
    RingBuffer.writeToBuffer(2);
    RingBuffer.writeToBuffer(3);
    EXPECT_EQ(1, RingBuffer.getBuffer()[RingBuffer.getTail()] );
}
TEST(RingBuffer, FinalTest)
{
    RingBuffer ringBuffer{5};
    EXPECT_EQ("[- - - - - ] Size 0\n", ringBuffer.printBuffer());

}
TEST(RingBuffer, FinalTestPt2)
{
    RingBuffer ringBuffer{5};
    ringBuffer.writeToBuffer(5);
    ringBuffer.writeToBuffer(5);
    EXPECT_EQ("[5 5 - - - ] Size 2\n", ringBuffer.printBuffer());
}
TEST(RingBuffer, FinalTestPt3)
{
    RingBuffer ringBuffer{5};
    EXPECT_EQ("[- - - - - ] Size 0\n", ringBuffer.printBuffer() );
}
TEST(RingBuffer, FinalTestPt4)
{

    RingBuffer ringBuffer{5};
    ringBuffer.writeToBuffer(1);
    ringBuffer.writeToBuffer(2);
    ringBuffer.writeToBuffer(3);
    EXPECT_EQ("[1 2 3 - - ] Size 3\n", ringBuffer.printBuffer() );
    ringBuffer.readFromBuffer();
    EXPECT_EQ("[- 2 3 - - ] Size 2\n", ringBuffer.printBuffer() );
    ringBuffer.writeToBuffer(4);
    EXPECT_EQ("[- 2 3 4 - ] Size 3\n", ringBuffer.printBuffer() );
    ringBuffer.writeToBuffer(5);
    EXPECT_EQ("[- 2 3 4 5 ] Size 4\n", ringBuffer.printBuffer() );
    ringBuffer.writeToBuffer(6);
    EXPECT_EQ("[6 2 3 4 5 ] Size 5\n", ringBuffer.printBuffer() );
    ringBuffer.writeToBuffer(7);
    EXPECT_EQ("[6 7 3 4 5 ] Size 5\n", ringBuffer.printBuffer() );
    ringBuffer.readFromBuffer();
    EXPECT_EQ("[6 7 - 4 5 ] Size 4\n", ringBuffer.printBuffer() );
    ringBuffer.readFromBuffer();
    EXPECT_EQ("[6 7 - - 5 ] Size 3\n", ringBuffer.printBuffer() );

}
