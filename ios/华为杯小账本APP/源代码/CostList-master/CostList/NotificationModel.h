//
//  NotificationModel.h
//  CostList
//
//  
//

#import <Foundation/Foundation.h>

@interface NotificationModel : NSObject <NSCoding>

//提醒内容
@property (nonatomic,copy) NSString *alertTitle;
//提醒时间
@property (nonatomic,copy) NSString *alertTime;
//提醒周期
@property (nonatomic,copy) NSString *alertCycle;
//提醒标识符
@property (nonatomic,copy) NSString *alertID;

+(NSString *)nextNotificationID; //获取下一个通知ID

@end
