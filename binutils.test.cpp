// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include "google_test.h"
#include <testconfig.h>
#include <mvvm/utils/binutils.h>

using namespace ModelView;

//! Testing BinUtils

class BinUtilsTest : public ::testing::Test
{
public:
    ~BinUtilsTest();
};

BinUtilsTest::~BinUtilsTest() = default;

//! Testing Binary Files

TEST_F(BinUtilsTest, testBinaryFiles)
{
    std::string root_path =  TestConfig::TestData();
    
    std::string binary_file1 = root_path + std::string("/") + "pdf_file.png";
    std::string binary_file2 = root_path + std::string("/") + "png_file.png";
    std::string binary_file3 = root_path + std::string("/") + "word_file";
    std::string binary_file4 = root_path + std::string("/") + "mandelbrot.ppm";
    std::string binary_file5 = root_path + std::string("/") + "c++_exec";

    EXPECT_EQ(true, Utils::is_binary(binary_file1));
    EXPECT_EQ(true, Utils::is_binary(binary_file2));
    EXPECT_EQ(true, Utils::is_binary(binary_file3));
    EXPECT_EQ(true, Utils::is_binary(binary_file4));
    EXPECT_EQ(true, Utils::is_binary(binary_file5));

}

//! Testing text files

TEST_F(BinUtilsTest, testTextFiles)
{
    std::string root_path =  TestConfig::TestData();

    std::string text_file1 = root_path + std::string("/") + "text_UTF-8.txt";
    std::string text_file2 = root_path + std::string("/") + "text_UTF-8-BOM.txt";

    EXPECT_EQ(true, Utils::is_text(text_file1));
    EXPECT_EQ(true, Utils::is_text(text_file2));

}