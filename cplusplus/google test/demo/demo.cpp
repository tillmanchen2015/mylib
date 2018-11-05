// tcDemo.cpp : Defines the entry point for the console application.
//

#include <gtest/gtest.h>


TEST(tsclientTest, init_detector) {
	ASSERT_STRCASEEQ(test_map["init_detector"].c_str(), "0");
}

TEST(tsclientTest, config) {
	EXPECT_STRCASEEQ(test_map["cla_id"].c_str(), "testClassRoom");
	EXPECT_STRCASEEQ(test_map["live_id"].c_str(), "testLiveID");
	EXPECT_STRCASEEQ(test_map["start_time"].c_str(), "10:00:00");
	EXPECT_STRCASEEQ(test_map["end_time"].c_str(), "12:00:00");
	EXPECT_STRCASEEQ(test_map["class_num"].c_str(), "1");
	EXPECT_STRCASEEQ(test_map["testDate"].c_str(), "2030-02-03");
	EXPECT_STRCASEEQ(test_map["Got config"].c_str(), "true");
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

