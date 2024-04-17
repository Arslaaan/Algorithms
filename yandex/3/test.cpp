#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "solution.cpp"

using namespace testing;

TEST(DEFAULT, test1) {
    std::ifstream cin("../yandex/3/input1.txt");
    std::ofstream cout("../yandex/3/output1.txt");

    if (!cin) {
        std::cout << "Incorrect path" << std::endl;
    }
    
    readTask3(cin, cout);

    cin.close();
    cout.close();
}

// TEST(DEFAULT, test2) {
//     std::ifstream cin("../yandex/1/input2.txt");
//     std::ofstream cout("../yandex/1/output2.txt");

//     if (!cin || !cout) {
//         std::cout << "Incorrect path" << std::endl;
//     }
    
//     readTask1(cin, cout);

//     cout.close();
//     cin.close();
// }

// TEST(DEFAULT, test3) {
//     std::ifstream cin("../yandex/1/input3.txt");
//     std::ofstream cout("../yandex/1/output3.txt");

//     if (!cin || !cout) {
//         std::cout << "Incorrect path" << std::endl;
//     }
    
//     readTask1(cin, cout);


//     cout.close();
//     cin.close();
// }

// TEST(DEFAULT, test4) {
//     std::ifstream cin("../yandex/1/input4.txt");
//     std::ofstream cout("../yandex/1/output4.txt");

//     if (!cin || !cout) {
//         std::cout << "Incorrect path" << std::endl;
//     }
    
//     readTask1(cin, cout);

//     cout.close();
//     cin.close();
// }


int main(int argc, char** argv) {
    // ::testing::GTEST_FLAG(filter) = "*test5*";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}