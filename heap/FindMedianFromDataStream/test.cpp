#include "solution.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(DEFAULT, 0) {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    ASSERT_THAT(medianFinder.findMedian(), 1.5);
    medianFinder.addNum(3);
    ASSERT_THAT(medianFinder.findMedian(), 2.0);
}

TEST(DEFAULT, 1) {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    ASSERT_THAT(medianFinder.findMedian(), 1.0);

    medianFinder.addNum(2);
    ASSERT_THAT(medianFinder.findMedian(), 1.5);

    medianFinder.addNum(3);
    ASSERT_THAT(medianFinder.findMedian(), 2.0);

    medianFinder.addNum(4);
    ASSERT_THAT(medianFinder.findMedian(), 2.5);

    medianFinder.addNum(5);
    ASSERT_THAT(medianFinder.findMedian(), 3.0);

    medianFinder.addNum(6);
    ASSERT_THAT(medianFinder.findMedian(), 3.5);

    medianFinder.addNum(7);
    ASSERT_THAT(medianFinder.findMedian(), 4.0);

    medianFinder.addNum(8);
    ASSERT_THAT(medianFinder.findMedian(), 4.5);

    medianFinder.addNum(9);
    ASSERT_THAT(medianFinder.findMedian(), 5.0);

    medianFinder.addNum(10);
    ASSERT_THAT(medianFinder.findMedian(), 5.5);
}

TEST(DEFAULT, 2) {
    MedianFinder medianFinder;
    medianFinder.addNum(12);
    ASSERT_THAT(medianFinder.findMedian(), 12.0);

    medianFinder.addNum(10);
    ASSERT_THAT(medianFinder.findMedian(), 11);

    medianFinder.addNum(13);
    ASSERT_THAT(medianFinder.findMedian(), 12);

    medianFinder.addNum(11);
    ASSERT_THAT(medianFinder.findMedian(), 11.5);

    medianFinder.addNum(5);
    ASSERT_THAT(medianFinder.findMedian(), 11);

    medianFinder.addNum(15);
    ASSERT_THAT(medianFinder.findMedian(), 11.5);

}

