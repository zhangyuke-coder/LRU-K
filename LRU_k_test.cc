#include "LRU_K.h"
#include <gtest/gtest.h>

TEST(LRUKReplacerTest, AntiO2)
{
 using frame_id_t = int;
 LRUKReplacer lru_replacer(3, 3);
 frame_id_t frame;
 ASSERT_EQ(lru_replacer.Size(),0);
 lru_replacer.RecordAccess(1);
 lru_replacer.RecordAccess(1);
 lru_replacer.RecordAccess(1);
 lru_replacer.RecordAccess(2);
 lru_replacer.RecordAccess(2);
 lru_replacer.RecordAccess(2);
 lru_replacer.RecordAccess(1);
 ASSERT_EQ(lru_replacer.Size(),2);
 lru_replacer.RecordAccess(3);
 lru_replacer.Evict(&frame);
 ASSERT_EQ(frame,3);
 lru_replacer.Evict(&frame);
 EXPECT_EQ(frame,1);

 lru_replacer.RecordAccess(1);
 lru_replacer.RecordAccess(3);
 lru_replacer.RecordAccess(1);
 lru_replacer.Evict(&frame);
 EXPECT_EQ(frame,1);
 lru_replacer.RecordAccess(3);
 lru_replacer.RecordAccess(3);
 lru_replacer.Evict(&frame);
 EXPECT_EQ(frame,2);
 lru_replacer.Evict(&frame);
 EXPECT_EQ(frame,3);
}
