# substring_index
select *
from(
  select substring_index(substring_index(operation, ':', -1), "}", 1) as classroomLogId
  from main_activity
  where operation_type = 21
) as classroomLog
group by classroomLogId
having count(classroomLogId) > 1

# case when 
select ts, 
			sum(messageCount) as messageCountTotal,
			sum(case when userType = 0 then messageCount else 0 end) as messageCountTeacher, 		  			sum(case when userType = 1 then messageCount else 0 end) as messageCountStudent
from nb_amaze_live_message_monitor_chennannan
group by ts;

# from_unixtime
select *,from_unixtime(createdTime/1000) , from_unixtime(startTime/1000) 
from interview 
where createdTime < 1590403200000 
			and startTime > 1590940800000;
      
# upsert
insert into teacher_quality (otId, score, scoringBasis)
values (:otId, :score, :scoringBasis)
on duplicate key update otId=:otId,
                        score=:score,
                        scoringBasis=:scoringBasis
                        
# 修改表结构
ALTER TABLE `course_view` CHANGE `contentType` `contentType` VARCHAR(50) DEFAULT '' COMMENT '课程内容分类'

# dbtime 转 毫秒
REPLACE(unix_timestamp(current_timestamp(3)),'.','')

